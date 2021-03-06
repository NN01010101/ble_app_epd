//
// Copyright 2014 Robin Callender
// Copyright 2013 Pervasive Displays, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at:
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
// express or implied.  See the License for the specific language
// governing permissions and limitations under the License.
//
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "nrf_gpio.h"
#include "nrf_delay.h"
#include "app_timer.h"

#include "pca10001_board.h"
#include "pwm.h"
#include "spi_bus.h"
#include "epd_v1.h"
#include "epd_spi.h"

/*
 *  NOTES:
 *
 *  1) For this version of the COG, only full-display updates are supported.
 *     Pervasive Display states that they will have a partial display 
 *     updates support available sometime around the end of January 2015.
 *     You will notice that there is code in this module which is a start
 *     at supporting partial display updates, but not completed yet.
 */

// delays - more consistent naming
#define Delay_ms(ms)   nrf_delay_ms(ms)
#define Delay_us(us)   nrf_delay_us(us)

#define LOW  0
#define HIGH 1

#define REG_INDEX   0x70
#define REG_DATA    0x72

#define digitalRead(pin)            nrf_gpio_pin_read(pin)
#define digitalWrite(pin, value)    nrf_gpio_pin_write(pin, value)

// inline arrays
#define ARRAY(type, ...) ((type[]){__VA_ARGS__})
#define PARMS(...)       (ARRAY(const uint8_t, __VA_ARGS__))

/*---------------------------------------------------------------------------*/
/*  types                                                                    */
/*---------------------------------------------------------------------------*/

typedef enum {       // Image pixel -> Display pixel
    EPD_compensate,  // B -> W, W -> B (Current Image)
    EPD_white,       // B -> N, W -> W (Current Image)
    EPD_inverse,     // B -> N, W -> B (New Image)
    EPD_normal       // B -> B, W -> W (New Image)
} EPD_stage;

/*---------------------------------------------------------------------------*/
/*  function prototypes                                                      */
/*---------------------------------------------------------------------------*/

static void power_off();
static void PWM_start(int pin);
static void PWM_stop(int pin);
static int  temperature_to_factor_10x(int temperature);
static void frame_fixed(uint8_t fixed_value, EPD_stage stage);
static void frame_data(const uint8_t *image, const uint8_t *mask, 
                       EPD_stage stage);
static void frame_fixed_repeat(uint8_t fixed_value, EPD_stage stage);
static void frame_data_repeat(const uint8_t *image, 
                              const uint8_t *mask, EPD_stage stage);
static void line(uint16_t line, const uint8_t *data, uint8_t fixed_value, 
                 const uint8_t *mask, EPD_stage stage);

/*---------------------------------------------------------------------------*/
/*   panel configuration                                                     */
/*---------------------------------------------------------------------------*/

struct EPD_struct {
    int EPD_Pin_PANEL_ON;
    int EPD_Pin_BORDER;
    int EPD_Pin_DISCHARGE;
    int EPD_Pin_PWM;
    int EPD_Pin_RESET;
    int EPD_Pin_BUSY;

    EPD_size size;

    int stage_time;
    int factored_stage_time;
    int lines_per_display;
    int dots_per_line;
    int bytes_per_line;
    int bytes_per_scan;
    int filler;

    const uint8_t * channel_select;
    size_t          channel_select_length;
    const uint8_t * gate_source;
    size_t          gate_source_length;

    uint8_t * line_buffer;
    size_t    line_buffer_size;
}; 

typedef struct EPD_struct EPD_type;

static EPD_type epd_instance;

EPD_type * epd = &epd_instance;

//
// This should fit all three display sizes.
//
static uint8_t line_buffer [160];

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*---------------------------------------------------------------------------*/
void EPD_GPIO_init(void)
{
    nrf_gpio_cfg_output(EPD_PANEL_ON_PIN);
    nrf_gpio_cfg_output(EPD_BORDER_PIN);
    nrf_gpio_cfg_output(EPD_DISCHARGE_PIN);
    nrf_gpio_cfg_output(EPD_PWM_PIN);
    nrf_gpio_cfg_output(EPD_RESET_PIN);
    nrf_gpio_cfg_output(SPI_M0_CSN_PIN);

    nrf_gpio_cfg_input(EPD_BUSY_PIN, NRF_GPIO_PIN_PULLUP);

#if 1
    nrf_gpio_pin_clear(EPD_PANEL_ON_PIN);
    nrf_gpio_pin_clear(EPD_BORDER_PIN);
    nrf_gpio_pin_clear(EPD_DISCHARGE_PIN);
    nrf_gpio_pin_clear(EPD_PWM_PIN);
    nrf_gpio_pin_set(EPD_RESET_PIN);
    nrf_gpio_pin_set(SPI_M0_CSN_PIN);
#endif

    epd->EPD_Pin_PANEL_ON  = EPD_PANEL_ON_PIN;
    epd->EPD_Pin_BORDER    = EPD_BORDER_PIN;
    epd->EPD_Pin_DISCHARGE = EPD_DISCHARGE_PIN;
    epd->EPD_Pin_PWM       = EPD_PWM_PIN;         // EPD_COG_VERSION == 1
    epd->EPD_Pin_RESET     = EPD_RESET_PIN;
    epd->EPD_Pin_BUSY      = EPD_BUSY_PIN;
}

/*---------------------------------------------------------------------------*/
/*  Create instance                                                          */
/*---------------------------------------------------------------------------*/
void EPD_create(EPD_size size) 
{
    memset(epd, 0, sizeof(*epd));

    /* Configure EPD's GPIO pins */
    EPD_GPIO_init();

    /* Initialize PWM */
    nrf_pwm_config_t pwm_config = PWM_DEFAULT_CONFIG;

    pwm_config.mode          = PWM_MODE_EPD;
    pwm_config.num_channels  = 1;
    pwm_config.gpio_num[0]   = epd->EPD_Pin_PWM;

    nrf_pwm_init(&pwm_config);

    if (EPD_SPI_init() == false)
        APP_ERROR_CHECK(0x0BADCAFE);

    // set up size structure
    switch (size) {

        case EPD_1_44:
        {
            static const uint8_t cs[] = {0x72, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0x00};
            static const uint8_t gs[] = {0x72, 0x03};
        
            epd->stage_time            = 480; // milliseconds
            epd->size                  = size;
            epd->lines_per_display     = 96;
            epd->dots_per_line         = 128;
            epd->bytes_per_line        = 128 / 8;
            epd->bytes_per_scan        = 96 / 4;
            epd->filler                = false;
            epd->channel_select        = cs;
            epd->channel_select_length = sizeof(cs);
            epd->gate_source           = gs;
            epd->gate_source_length    = sizeof(gs);
            break;
        }

        case EPD_2_0:
        {
            static const uint8_t cs[] = {0x72, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xe0, 0x00};
            static const uint8_t gs[] = {0x72, 0x03};

            epd->stage_time            = 480; // milliseconds
            epd->size                  = size;
            epd->lines_per_display     = 96;
            epd->dots_per_line         = 200;
            epd->bytes_per_line        = 200 / 8;
            epd->bytes_per_scan        = 96 / 4;
            epd->filler                = true;
            epd->channel_select        = cs;
            epd->channel_select_length = sizeof(cs);
            epd->gate_source           = gs;
            epd->gate_source_length    = sizeof(gs);
            break;
        }

        case EPD_2_7:
        {
            static const uint8_t cs[] = {0x72, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xfe, 0x00, 0x00};
            static const uint8_t gs[] = {0x72, 0x00};

            epd->stage_time            = 630; // milliseconds
            epd->size                  = size;
            epd->lines_per_display     = 176;
            epd->dots_per_line         = 264;
            epd->bytes_per_line        = 264 / 8;
            epd->bytes_per_scan        = 176 / 4;
            epd->filler                = true;
            epd->channel_select        = cs;
            epd->channel_select_length = sizeof(cs);
            epd->gate_source           = gs;
            epd->gate_source_length    = sizeof(gs);
            break;
        }

        default:
            APP_ERROR_CHECK(0xDEADBEEF);
            break;
    }

    epd->factored_stage_time = epd->stage_time;

    EPD_set_temperature(23);   // assume 23 degrees Celcius (73 degrees F)

    // buffer for frame line --
    // command byte, border byte and filler byte
    epd->line_buffer_size = 2 * epd->bytes_per_line + epd->bytes_per_scan + 3; 
    epd->line_buffer      = line_buffer;

    // ensure I/O is all set to ZERO
    power_off();
}

/*---------------------------------------------------------------------------*/
/*  Destroy instance                                                         */
/*---------------------------------------------------------------------------*/
void EPD_destroy(void)
{
    power_off();

    memset(epd, 0, sizeof(*epd));
}

/*---------------------------------------------------------------------------*/
/*  Starts an EPD sequence                                                   */
/*---------------------------------------------------------------------------*/
void EPD_begin(void)
{
    // power up sequence
    digitalWrite(epd->EPD_Pin_RESET,     LOW);
    digitalWrite(epd->EPD_Pin_PANEL_ON,  LOW);
    digitalWrite(epd->EPD_Pin_DISCHARGE, LOW);
    digitalWrite(epd->EPD_Pin_BORDER,    LOW);

    EPD_SPI_on();

    PWM_start(epd->EPD_Pin_PWM);
    Delay_ms(25);
    digitalWrite(epd->EPD_Pin_PANEL_ON, HIGH);
    Delay_ms(10);

    digitalWrite(epd->EPD_Pin_RESET, HIGH);
    digitalWrite(epd->EPD_Pin_BORDER, HIGH);
    Delay_ms(5);

    digitalWrite(epd->EPD_Pin_RESET, LOW);
    Delay_ms(5);

    digitalWrite(epd->EPD_Pin_RESET, HIGH);

    // wait for COG to become ready
    while (digitalRead(epd->EPD_Pin_BUSY) == HIGH) {
        Delay_us(10);
    }

    // channel select
    EPD_SPI_send(PARMS(REG_INDEX, 0x01), 2);
    EPD_SPI_send(epd->channel_select, epd->channel_select_length);

    // DC/DC frequency
    EPD_SPI_send(PARMS(REG_INDEX, 0x06), 2);
    EPD_SPI_send(PARMS(REG_DATA,  0xff), 2);

    // high power mode osc
    EPD_SPI_send(PARMS(REG_INDEX, 0x07), 2);
    EPD_SPI_send(PARMS(REG_DATA,  0x9d), 2);

    // disable ADC
    EPD_SPI_send(PARMS(REG_INDEX, 0x08), 2);
    EPD_SPI_send(PARMS(REG_DATA,  0x00), 2);

    // Vcom level
    EPD_SPI_send(PARMS(REG_INDEX, 0x09), 2);
    EPD_SPI_send(PARMS(REG_DATA,  0xd0, 0x00), 3);

    // gate and source voltage levels
    EPD_SPI_send(PARMS(REG_INDEX, 0x04), 2);
    EPD_SPI_send(epd->gate_source, epd->gate_source_length);

    Delay_ms(5);  //???

    // driver latch on
    EPD_SPI_send(PARMS(REG_INDEX, 0x03), 2);
    EPD_SPI_send(PARMS(REG_DATA,  0x01), 2);

    // driver latch off
    EPD_SPI_send(PARMS(REG_INDEX, 0x03), 2);
    EPD_SPI_send(PARMS(REG_DATA,  0x00), 2);

    Delay_ms(5);

    // charge pump positive voltage on
    EPD_SPI_send(PARMS(REG_INDEX, 0x05), 2);
    EPD_SPI_send(PARMS(REG_DATA,  0x01), 2);

    // final delay before PWM off
    Delay_ms(30);
    PWM_stop(epd->EPD_Pin_PWM);

    // charge pump negative voltage on
    EPD_SPI_send(PARMS(REG_INDEX, 0x05), 2);
    EPD_SPI_send(PARMS(REG_DATA,  0x03), 2);

    Delay_ms(30);

    // Vcom driver on
    EPD_SPI_send(PARMS(REG_INDEX, 0x05), 2);
    EPD_SPI_send(PARMS(REG_DATA,  0x0f), 2);

    Delay_ms(30);

    // output enable to disable
    EPD_SPI_send(PARMS(REG_INDEX, 0x02), 2);
    EPD_SPI_send(PARMS(REG_DATA,  0x24), 2);

    EPD_SPI_off();
}

/*---------------------------------------------------------------------------*/
/*  Ends an EPD sequence                                                     */
/*---------------------------------------------------------------------------*/
void EPD_end(void)
{
    // dummy frame
    frame_fixed(0x55, EPD_normal);

    // dummy line and border
    if (EPD_1_44 == epd->size) {
        
        // only for 1.44" EPD
        line(0x7fffu, 0, 0x55, NULL, EPD_normal);
        Delay_ms(250);
    } 
    else {
        // all other display sizes
        line(0x7fffu, 0, 0x55, NULL, EPD_normal);
        Delay_ms(25);

        digitalWrite(epd->EPD_Pin_BORDER, LOW);
        Delay_ms(250);
        digitalWrite(epd->EPD_Pin_BORDER, HIGH);
    }

    EPD_SPI_on();

    // latch reset turn on
    EPD_SPI_send(PARMS(REG_INDEX, 0x03), 2);
    EPD_SPI_send(PARMS(REG_DATA,  0x01), 2);

    // output enable off
    EPD_SPI_send(PARMS(REG_INDEX, 0x02), 2);
    EPD_SPI_send(PARMS(REG_DATA,  0x05), 2);

    // Vcom power off
    EPD_SPI_send(PARMS(REG_INDEX, 0x05), 2);
    EPD_SPI_send(PARMS(REG_DATA,  0x0e), 2);

    // power off negative charge pump
    EPD_SPI_send(PARMS(REG_INDEX, 0x05), 2);
    EPD_SPI_send(PARMS(REG_DATA,  0x02), 2);

    // discharge
    EPD_SPI_send(PARMS(REG_INDEX, 0x04), 2);
    EPD_SPI_send(PARMS(REG_DATA,  0x0c), 2);

    Delay_ms(120);

    // all charge pumps off
    EPD_SPI_send(PARMS(REG_INDEX, 0x05), 2);
    EPD_SPI_send(PARMS(REG_DATA,  0x00), 2);

    // turn of osc
    EPD_SPI_send(PARMS(REG_INDEX, 0x07), 2);
    EPD_SPI_send(PARMS(REG_DATA,  0x0d), 2);

    // discharge internal - 1
    EPD_SPI_send(PARMS(REG_INDEX, 0x04), 2);
    EPD_SPI_send(PARMS(REG_DATA,  0x50), 2);

    Delay_ms(40);

    // discharge internal - 2
    EPD_SPI_send(PARMS(REG_INDEX, 0x04), 2);
    EPD_SPI_send(PARMS(REG_DATA,  0xA0), 2);

    Delay_ms(40);

    // discharge internal - 3
    EPD_SPI_send(PARMS(REG_INDEX, 0x04), 2);
    EPD_SPI_send(PARMS(REG_DATA,  0x00), 2);

    power_off();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*---------------------------------------------------------------------------*/
static void power_off(void)
{
    // turn of power and all signals
    digitalWrite(epd->EPD_Pin_RESET,    LOW);
    digitalWrite(epd->EPD_Pin_PANEL_ON, LOW);
    digitalWrite(epd->EPD_Pin_BORDER,   LOW);

    // ensure SPI MOSI and CLOCK are Low before CS Low
    EPD_SPI_off();

    // discharge pulse
    digitalWrite(epd->EPD_Pin_DISCHARGE, HIGH);
    Delay_ms(150);
    digitalWrite(epd->EPD_Pin_DISCHARGE, LOW);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*---------------------------------------------------------------------------*/
void EPD_set_temperature(int temperature)
{
    epd->factored_stage_time = 
        epd->stage_time * temperature_to_factor_10x(temperature) / 10;
}

/*---------------------------------------------------------------------------*/
/*  clear display (anything -> white)                                        */
/*---------------------------------------------------------------------------*/
void EPD_clear(void)
{
    frame_fixed_repeat(0xff, EPD_compensate);
    frame_fixed_repeat(0xff, EPD_white);
    frame_fixed_repeat(0xaa, EPD_inverse);
    frame_fixed_repeat(0xaa, EPD_normal);
}

/*---------------------------------------------------------------------------*/
/*  assuming a clear (white) screen output an image                          */
/*---------------------------------------------------------------------------*/
void EPD_image_0(const uint8_t * image)
{
    frame_fixed_repeat(0xaa, EPD_compensate);
    frame_fixed_repeat(0xaa, EPD_white);

    frame_data_repeat(image, NULL, EPD_inverse);
    frame_data_repeat(image, NULL, EPD_normal);
}

/*---------------------------------------------------------------------------*/
/*  change from old image to new image                                       */
/*---------------------------------------------------------------------------*/
void EPD_image(const uint8_t * old_image, const uint8_t * new_image)
{
    frame_data_repeat(old_image, NULL, EPD_compensate);
    frame_data_repeat(old_image, NULL, EPD_white);
    frame_data_repeat(new_image, NULL, EPD_inverse);
    frame_data_repeat(new_image, NULL, EPD_normal);
}

/*---------------------------------------------------------------------------*/
/*  change from old image to new image                                       */
/*---------------------------------------------------------------------------*/
void EPD_partial_image(const uint8_t *old_image, const uint8_t * new_image)
{
    frame_data_repeat(old_image, new_image, EPD_compensate);
    frame_data_repeat(old_image, new_image, EPD_white);
    frame_data_repeat(new_image, old_image, EPD_inverse);
    frame_data_repeat(new_image, old_image, EPD_normal);
}

/*---------------------------------------------------------------------------*/
/*  Convert a temperature in Celcius to                                      */
/*  the scale factor for frame_*_repeat methods                              */
/*---------------------------------------------------------------------------*/
static int temperature_to_factor_10x(int temperature)
{
    if (temperature <= -10) {
        return 170;
    } 
    else if (temperature <= -5) {
        return 120;
    } 
    else if (temperature <= 5) {
        return 80;
    } 
    else if (temperature <= 10) {
        return 40;
    } 
    else if (temperature <= 15) {
        return 30;
    } 
    else if (temperature <= 20) {
        return 20;
    } 
    else if (temperature <= 40) {
        return 10;
    }
    return 7;
}

/*---------------------------------------------------------------------------*/
/*  One frame of data is the number of lines * rows.                         */
/*  For example:                                                             */
/*     The 1.44” frame of data is 96 lines * 128 dots.                       */
/*     The 2” frame of data is 96 lines * 200 dots.                          */
/*     The 2.7” frame of data is 176 lines * 264 dots.                       */
/*                                                                           */
/*  The image is arranged by line which matches the display size             */
/*  so the smallest would have 96 * 32 bytes.                                */
/*---------------------------------------------------------------------------*/
static void frame_fixed(uint8_t fixed_value, EPD_stage stage)
{
    for (uint8_t row = 0; row < epd->lines_per_display; row++) {

        line(row, NULL, fixed_value, NULL, stage);
    }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*---------------------------------------------------------------------------*/
static void frame_data(const uint8_t * image,
                       const uint8_t * mask, EPD_stage stage)
{
    if (NULL == mask) {
        for (uint8_t row = 0; row < epd->lines_per_display; row++) {

            line(row, &image[row * epd->bytes_per_line], 0, NULL, stage);
        }
    }
    else {
        for (uint8_t row = 0; row < epd->lines_per_display; row++) {
            size_t n = row * epd->bytes_per_line;

            line(row, &image[n], 0, &mask[n], stage);
        }
    }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*---------------------------------------------------------------------------*/
static void frame_fixed_repeat(uint8_t fixed_value, EPD_stage stage)
{
    frame_fixed(fixed_value, stage);
    Delay_ms(epd->factored_stage_time);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*---------------------------------------------------------------------------*/
static void frame_data_repeat(const uint8_t * image,
                              const uint8_t * mask, EPD_stage stage)
{
    frame_data(image, mask, stage);
    Delay_ms(epd->factored_stage_time);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*---------------------------------------------------------------------------*/
static void line(uint16_t line, const uint8_t * data, 
                 uint8_t fixed_value, const uint8_t * mask, EPD_stage stage)
{
    EPD_SPI_on();

    // charge pump voltage levels
    EPD_SPI_send(PARMS(REG_INDEX, 0x04), 2);
    EPD_SPI_send(epd->gate_source, epd->gate_source_length);

    // send data
    EPD_SPI_send(PARMS(REG_INDEX, 0x0a), 2);

    // CS low
    uint8_t * p = epd->line_buffer;

    *p++ = 0x72;

    // border byte only necessary for 1.44" EPD
    if (EPD_1_44 == epd->size) {
        *p++ = 0x00;
    }

    // even pixels
    for (uint16_t b = epd->bytes_per_line; b > 0; --b) {
        if (NULL != data) {
            uint8_t pixels = data[b - 1] & 0xaa;
            uint8_t pixel_mask = 0xff;

            if (NULL != mask) {
                pixel_mask = (mask[b - 1] ^ pixels) & 0xaa;
                pixel_mask |= pixel_mask >> 1;
            }

            switch(stage) {
                case EPD_compensate:  // B -> W, W -> B (Current Image)
                    pixels = 0xaa | ((pixels ^ 0xaa) >> 1);
                    break;
                case EPD_white:       // B -> N, W -> W (Current Image)
                    pixels = 0x55 + ((pixels ^ 0xaa) >> 1);
                    break;
                case EPD_inverse:     // B -> N, W -> B (New Image)
                    pixels = 0x55 | (pixels ^ 0xaa);
                    break;
                case EPD_normal:       // B -> B, W -> W (New Image)
                    pixels = 0xaa | (pixels >> 1);
                    break;
            }
            *p++ = (pixels & pixel_mask) | (~pixel_mask & 0x55);
        }
        else {
            *p++ = fixed_value;
        }
    }

    // scan line
    for (uint16_t b = 0; b < epd->bytes_per_scan; ++b) {
        if (line / 4 == b) {
            *p++ = 0xc0 >> (2 * (line & 0x03));
        }
        else {
            *p++ = 0x00;
        }
    }

    // odd pixels
    for (uint16_t b = 0; b < epd->bytes_per_line; ++b) {
        if (NULL != data) {
            uint8_t pixels = data[b] & 0x55;
            uint8_t pixel_mask = 0xff;

            if (NULL != mask) {
                pixel_mask = (mask[b] ^ pixels) & 0x55;
                pixel_mask |= pixel_mask << 1;
            }

            switch(stage) {
                case EPD_compensate:  // B -> W, W -> B (Current Image)
                    pixels = 0xaa | (pixels ^ 0x55);
                    break;
                case EPD_white:       // B -> N, W -> W (Current Image)
                    pixels = 0x55 + (pixels ^ 0x55);
                    break;
                case EPD_inverse:     // B -> N, W -> B (New Image)
                    pixels = 0x55 | ((pixels ^ 0x55) << 1);
                    break;
                case EPD_normal:       // B -> B, W -> W (New Image)
                    pixels = 0xaa | pixels;
                    break;
            }

            pixels = (pixels & pixel_mask) | (~pixel_mask & 0x55);

            uint8_t p1 = (pixels >> 6) & 0x03;
            uint8_t p2 = (pixels >> 4) & 0x03;
            uint8_t p3 = (pixels >> 2) & 0x03;
            uint8_t p4 = (pixels >> 0) & 0x03;
            pixels = (p1 << 0) | (p2 << 2) | (p3 << 4) | (p4 << 6);
            *p++ = pixels;
        }
        else {
            *p++ = fixed_value;
        }
    }

    if (epd->filler) {
        *p++ = 0x00;
    }

    // send the accumulated line buffer
    EPD_SPI_send(epd->line_buffer, p - epd->line_buffer);

    // output data to panel
    EPD_SPI_send(PARMS(REG_INDEX, 0x02), 2);
    EPD_SPI_send(PARMS(REG_DATA,  0x2f), 2);

    EPD_SPI_off();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*---------------------------------------------------------------------------*/
static void PWM_start(int pin)
{
    nrf_pwm_set_enabled(true);
    nrf_pwm_set_value(0, 62);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*---------------------------------------------------------------------------*/
static void PWM_stop(int pin)
{
    nrf_pwm_set_value(0, 0);
    nrf_pwm_set_enabled(false);
}

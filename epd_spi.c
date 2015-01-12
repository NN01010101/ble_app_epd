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

#include "pca10001_board.h"
#include "epd_spi.h"

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*---------------------------------------------------------------------------*/

#define EPD_SPI_CONTROLLER   ((const spi_master_hw_instance_t) SPI_MASTER_0)

typedef enum {
    SPI_MODE_0,   /* (CPOL = 0, CPHA = 0) */
    SPI_MODE_1,   /* (CPOL = 0, CPHA = 1) */
    SPI_MODE_2,   /* (CPOL = 1, CPHA = 0) */
    SPI_MODE_3    /* (CPOL = 1, CPHA = 1) */
} spi_mode_t;

/*
 *  SPI_MODE_0:  (CPOL = 0, CPHA = 0)
 *  SPI_MODE_1:  (CPOL = 0, CPHA = 1)
 *  SPI_MODE_2:  (CPOL = 1, CPHA = 0)  <-- use this mode for EPD v1
 *  SPI_MODE_3:  (CPOL = 1, CPHA = 1)
 *
 *  SPI_MODE_0:  SPIS_CONFIG_CPOL_ActiveHigh, SPIS_CONFIG_CPHA_Leading
 *  SPI_MODE_1:  SPIS_CONFIG_CPOL_ActiveHigh, SPIS_CONFIG_CPHA_Trailing
 *  SPI_MODE_2:  SPIS_CONFIG_CPOL_ActiveLow,  SPIS_CONFIG_CPHA_Leading  <--
 *  SPI_MODE_3:  SPIS_CONFIG_CPOL_ActiveLow,  SPIS_CONFIG_CPHA_Trailing
 */

/*
 *  SPI configuration for EPD
 */
spi_master_config_t   epd_spi_config = {

    SPI_FREQUENCY_FREQUENCY_M4,     /* Serial clock frequency  */
    SPI_M0_SCK_PIN,                 /* SCK pin                 */
    SPI_M0_MISO_PIN,                /* MISO pin                */
    SPI_M0_MOSI_PIN,                /* MOSI pin                */
    SPI_M0_CSN_PIN,                 /* Select pin              */
    APP_IRQ_PRIORITY_LOW,           /* Interrupt priority      */
    SPI_CONFIG_ORDER_MsbFirst,      /* Bits order              */
    SPI_CONFIG_CPOL_ActiveHigh,      /* Serial clock polarity   */
    SPI_CONFIG_CPHA_Leading,        /* Serial clock phase      */
    false                           /* Don't disable all IRQs. */
};

static bool spi_on = false;

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*---------------------------------------------------------------------------*/
static void set_spi_mode(spi_mode_t mode)
{
    switch (mode) {

        case SPI_MODE_0:
            epd_spi_config.SPI_CONFIG_CPOL = SPI_CONFIG_CPOL_ActiveLow;
            epd_spi_config.SPI_CONFIG_CPHA = SPI_CONFIG_CPHA_Leading;
            break;

        case SPI_MODE_1:
            epd_spi_config.SPI_CONFIG_CPOL = SPI_CONFIG_CPOL_ActiveLow;
            epd_spi_config.SPI_CONFIG_CPHA = SPI_CONFIG_CPHA_Leading;
            break;

        case SPI_MODE_2:
            epd_spi_config.SPI_CONFIG_CPOL = SPI_CONFIG_CPOL_ActiveLow;
            epd_spi_config.SPI_CONFIG_CPHA = SPI_CONFIG_CPHA_Leading;
            break;

        case SPI_MODE_3:
            epd_spi_config.SPI_CONFIG_CPOL = SPI_CONFIG_CPOL_ActiveLow;
            epd_spi_config.SPI_CONFIG_CPHA = SPI_CONFIG_CPHA_Leading;
            break;

        default:
            break;
    }
}

/*---------------------------------------------------------------------------*/
/*  Initialize SPI interface                                                 */
/*---------------------------------------------------------------------------*/
bool EPD_SPI_init(void)
{
    uint32_t err_code;

    err_code = spi_init(EPD_SPI_CONTROLLER, &epd_spi_config);
    APP_ERROR_CHECK(err_code);

    spi_on = true;

    return true;
}

/*---------------------------------------------------------------------------*/
/*  Close SPI interface                                                      */
/*---------------------------------------------------------------------------*/
bool EPD_SPI_close(void)
{
    spi_close(EPD_SPI_CONTROLLER);
    
    spi_on = false;

    return true;
}

/*---------------------------------------------------------------------------*/
/*  Enable SPI, ensures a zero byte was sent (MOSI=0)                        */
/*---------------------------------------------------------------------------*/
void EPD_SPI_on(void) 
{
    if (spi_on == true) {
        return;
    }
    spi_on = true;

    const uint8_t buffer[1] = {0};

#if EPD_COG_VERSION == 1
    set_spi_mode(SPI_MODE_2);
#else
    set_spi_mode(SPI_MODE_0);
#endif

    EPD_SPI_init();

    EPD_SPI_send(buffer, sizeof(buffer));
}

/*---------------------------------------------------------------------------*/
/*  Disable SPI, ensures a zero byte was sent (MOSI=0)                       */
/*---------------------------------------------------------------------------*/
void EPD_SPI_off(void)
{
    const uint8_t buffer[1] = {0};

    if (spi_on == false) {
        return;
    }
    spi_on = false;

    set_spi_mode(SPI_MODE_0);

    EPD_SPI_init();

    EPD_SPI_send(buffer, sizeof(buffer));

    EPD_SPI_close();
}

/*---------------------------------------------------------------------------*/
/*  Send a data block to SPI                                                 */
/*---------------------------------------------------------------------------*/
void EPD_SPI_send(const uint8_t * buffer, uint16_t length) 
{
    uint32_t err_code;

    err_code = spi_send_recv(EPD_SPI_CONTROLLER, 
                             (uint8_t * const) buffer, length, 
                             NULL, 0);
    APP_ERROR_CHECK(err_code);
}

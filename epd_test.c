/*---------------------------------------------------------------------------*/
/* Copyright (c) 2014 Robin Callender. All Rights Reserved.                  */
/*---------------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "ble_nus.h"
#include "app_timer.h"

#if EPD_COG_VERSION == 1
    #include "epd_v1.h"
#elif EPD_COG_VERSION == 2
    #include "epd_v2.h"
#else
    #error "unsupported COG version"
#endif

static void (*function)(void);

bool ble_attempt_to_send(uint8_t * data, uint8_t length);  // in main.c

/* 
 * NOTE: All *.xbm files should have "const" in their image definition.
 *       This directs the build to put the bitmap in the Flash area,
 *       rather than in RAM area, thereby reducing memory pressure
 *       on the more constrained resource, RAM.
 *
 *       Example:
 *          static const unsigned char cat_1_44_bits[] 
 */

#ifdef EPD_DISPLAY_SIZE_1_44
    #include "aphrodite_1_44.xbm"
    #include "cat_1_44.xbm"
    #include "saturn_1_44.xbm"
    #include "venus_1_44.xbm"
    #include "text_hello_1_44.xbm"
    #include "text_image_1_44.xbm"

    static const uint8_t * images_array [] = {
        aphrodite_1_44_bits,
        cat_1_44_bits,
        saturn_1_44_bits,
        venus_1_44_bits,
        text_hello_1_44_bits,
        text_image_1_44_bits,
    };

    #define EPD_DISPLAY_SIZE  EPD_1_44

#endif

#ifdef EPD_DISPLAY_SIZE_2_0
    #include "aphrodite_2_0.xbm"
    #include "cat_2_0.xbm"
    #include "saturn_2_0.xbm"
    #include "venus_2_0.xbm"
    #include "text_hello_2_0.xbm"
    #include "text_image_2_0.xbm"

    static const uint8_t * images_array [] = {
        aphrodite_2_0_bits,
        cat_2_0_bits,
        saturn_2_0_bits,
        venus_2_0_bits,
        text_hello_2_0_bits,
        text_image_2_0_bits,
    };

    #define EPD_DISPLAY_SIZE  EPD_DISPLAY_SIZE_2_0

#endif

#ifdef EPD_DISPLAY_SIZE_2_7
    #include "aphrodite_2_7.xbm"
    #include "cat_2_7.xbm"
    #include "saturn_2_7.xbm"
    #include "venus_2_7.xbm"
    #include "text_hello_2_7.xbm"
    #include "text_image_2_7.xbm"

    static const uint8_t * images_array [] = {
        aphrodite_2_7_bits,
        cat_2_7_bits,
        saturn_2_7_bits,
        venus_2_7_bits,
        text_hello_2_7_bits,
        text_image_2_7_bits,
    };

    #define EPD_DISPLAY_SIZE  EPD_2_7

#endif

#define SIZE_OF_ARRAY(a) (sizeof(a) / sizeof((a)[0]))

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*---------------------------------------------------------------------------*/
void epd_slide_show(void)
{
    EPD_create(EPD_DISPLAY_SIZE);

    for (int i = 0; i < SIZE_OF_ARRAY(images_array); ++i) {

        EPD_begin();

        if (i == 0) {
            EPD_image_0(images_array[i]);
        } 
        else {
            EPD_image(images_array[i - 1], images_array[i]);
        }

        EPD_end();
    }

    EPD_destroy();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*---------------------------------------------------------------------------*/
void epd_clear_screen(void)
{
    EPD_create(EPD_DISPLAY_SIZE);
    EPD_begin();
    EPD_clear();
    EPD_end();
    EPD_destroy();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*---------------------------------------------------------------------------*/
static void send_cmd_response(char * stringz)
{
    int len = strlen(stringz);

    if (len >= BLE_NUS_MAX_DATA_LEN)
        return;  // FIXME needs an assert here

    ble_attempt_to_send((uint8_t*)stringz, (uint8_t)len);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*---------------------------------------------------------------------------*/
void epd_processs(void)      
{
    if (function != NULL) {
        function();
        function = NULL;
        send_cmd_response("done\r\n");
    }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*---------------------------------------------------------------------------*/
void epd_commands(uint8_t * string, uint16_t length)
{
    if (function != NULL) {
        send_cmd_response("busy...\r\n");
        return;
    }

    do {

        if (strnicmp((char*)string, "show", sizeof("show")-1) == 0) {
            send_cmd_response("start slide show\r\n");
            function = epd_slide_show;
            break;
        }

        if (strnicmp((char*)string, "clear", sizeof("clear")-1) == 0) {
            send_cmd_response("clear screen\r\n");
            function = epd_clear_screen;
            break;
        }

    } while (0);
}

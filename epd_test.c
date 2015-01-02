#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#if EPD_COG_VERSION == 1
    #include "epd_v1.h"
#elif EPD_COG_VERSION == 2
    #include "epd_v2.h"
#else
    #error "unsupported COG version"
#endif

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

// the main test program
int epd_test(void)
{
    EPD_size         display_size;
    int              image_count;
    const uint8_t ** images;

    display_size = EPD_DISPLAY_SIZE;
    images       = images_array;
    image_count  = SIZE_OF_ARRAY(images_array);

    EPD_create(display_size);

    for (int i = 0; i < image_count; ++i) {

        EPD_begin();

        if (i == 0) {
            EPD_image_0(images[i]);
        } 
        else {
            EPD_image(images[i - 1], images[i]);
        }

        EPD_end();
    }

    EPD_destroy();

    return 0;
}

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "epd_v1.h"


#if 1
#include "cat_1_44.xbm"
#include "venus_1_44.xbm"
static const uint8_t * images_1_44 [] = {
    cat_1_44_bits,
    venus_1_44_bits,
};
#endif

#if 0
#include "cat_1_44.xbm"
static const uint8_t * images_2_0 [] = {
    cat_2_0_bits
};
#endif

#if 0
#include "cat_1_44.xbm"
static const uint8_t * images_2_7 [] = {
    cat_2_7_bits
};
#endif

#define SIZE_OF_ARRAY(a) (sizeof(a) / sizeof((a)[0]))

// the main test program
int epd_test(void)
{
    int rc = 0;
    EPD_size display_size = EPD_1_44;
    const uint8_t *const * images = images_1_44;
    int image_count = SIZE_OF_ARRAY(images_1_44);

    display_size = EPD_1_44;
    images       = images_1_44;
    image_count  = SIZE_OF_ARRAY(images_1_44);

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

    return rc;
}

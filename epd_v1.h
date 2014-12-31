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
#ifndef EPD_V1_H
#define EPD_V1_H

#include "nrf.h"
#include "spi_master.h"
#include "spi_bus.h"


typedef enum {
    EPD_1_44,        // 128 x 96
    EPD_2_0,         // 200 x 96
    EPD_2_7          // 264 x 176
} EPD_size;

typedef enum {       // error codes
    EPD_OK,
} EPD_error;


// ================================================
// Functions 
// ================================================

// Create EPD instance.
void EPD_create(EPD_size size);

// Destroy EPD instance
void EPD_destroy(void);

// set the temperature compensation (call before begin)
void EPD_set_temperature(int temperature);

// sequence start/end  (bracket)
void EPD_begin(void);
void EPD_end(void);

// ================================================
// Functions below must be bracketed by begin/end
// ================================================

// Clear the screen
void EPD_clear(void);

// Assuming a clear (white) screen output an image
void EPD_image_0(const uint8_t *image);

// Change from old image to new image
void EPD_image(const uint8_t *old_image, const uint8_t *new_image);

// Change from old image to new image:  Only updating changed pixels
void EPD_partial_image(const uint8_t *old_image, const uint8_t *new_image);


#endif /* EPD_V1_H */

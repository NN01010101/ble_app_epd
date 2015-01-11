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
#ifndef _EPD_SPI_H
#define _EPD_SPI_H

#include <stdint.h>
#include <stdbool.h>

#include "nordic_common.h"
#include "common.h"
#include "nrf.h"
#include "spi_master.h"
#include "spi_bus.h"
#include "app_util_platform.h"
#include "pca10001_board.h"

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*---------------------------------------------------------------------------*/

bool EPD_SPI_init(void);
bool EPD_SPI_close(void);

// Enable SPI, ensures a zero byte was sent (MOSI=0)
void EPD_SPI_on(void);

// Disable SPI, ensures a zero byte was sent (MOSI=0)
void EPD_SPI_off(void);

// Send a data block to SPI -- NOTE: EPD is write-only device.
void EPD_SPI_send(const uint8_t * buffer, uint16_t length);

#endif /* _EPD_SPI_H */

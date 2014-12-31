/* 
 *  Copyright (c) 2014 Robin Callender. All Rights Reserved.
 */
#ifndef PCA10001_BOARD_H
#define PCA10001_BOARD_H

#include "nrf_gpio.h"

#define RTS_PIN_NUMBER      8
#define TX_PIN_NUMBER       9
#define CTS_PIN_NUMBER     10
#define RX_PIN_NUMBER      11
#define HWFC               true

#define BUTTON_0           16
#define BUTTON_1           17
#define BUTTON_PULL        NRF_GPIO_PIN_PULLUP

#define LED_0              18
#define LED_1              19

#define SPI_M0_SCK_PIN     20    // EPD SPI SCK signal. 
#define SPI_M0_MISO_PIN    21    // EPD SPI MISO signal. 
#define SPI_M0_MOSI_PIN    22    // EPD SPI MOSI signal. 
#define SPI_M0_CSN_PIN     23    // EPD SPI CSN signal. 

#define EPD_PANEL_ON_PIN   24
#define EPD_BORDER_PIN     25
#define EPD_DISCHARGE_PIN  26
#define EPD_PWM_PIN        27
#define EPD_RESET_PIN      28
#define EPD_BUSY_PIN       29
#define EPD_FLASH_CS_PIN   30

#endif /* PCA10001_BOARD_H */

/* 
 *  Copyright (c) 2014 Robin Callender. All Rights Reserved.
 */
#ifndef PCA10001_BOARD_H
#define PCA10001_BOARD_H

#include "nrf_gpio.h"

#define EPD_PANEL_ON_PIN    0
#define EPD_BORDER_PIN      1
#define EPD_DISCHARGE_PIN   2
#define EPD_PWM_PIN         3
#define EPD_RESET_PIN       4
#define EPD_BUSY_PIN        5

#define RTS_PIN_NUMBER      8
#define TX_PIN_NUMBER       9
#define CTS_PIN_NUMBER     10
#define RX_PIN_NUMBER      11
#define HWFC               true

#define SPI_M0_SCK_PIN     12    // EPD SPI SCK signal. 
#define SPI_M0_MISO_PIN    13    // EPD SPI MISO signal. 
#define SPI_M0_MOSI_PIN    14    // EPD SPI MOSI signal. 
#define SPI_M0_CSN_PIN     15    // EPD SPI CSN signal. 

#define BUTTON_0           16
#define BUTTON_1           17
#define BUTTON_PULL        NRF_GPIO_PIN_PULLUP

#define LED_0              18
#define LED_1              19


static __INLINE void nrf_gpio_pin_pulse(uint32_t pin_number)
{
    NRF_GPIO->OUTSET = (1UL << pin_number);

    NRF_GPIO->OUTCLR = (1UL << pin_number);
}

#define __breakpoint     __ASM volatile ( "bkpt \n" )

#endif /* PCA10001_BOARD_H */

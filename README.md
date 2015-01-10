ble_app_epd
===========

Nordic nRF51822 PCA10001 support for Pervasive Display Extension Board and 1.44" ePaper display
 
Requirements
------------
- nRF51 SDK version 6.1.0
- S110 SoftDevice version 7.0.0
- nRF51822 Evaluation Kit version 2.1.0 or later containing PCA10001 board V2.2.0.

## Pin Assignment

The table below give the pin connections of the 20-pin male ribbon
connector.  Looking a the board oriented display side up (as front
view above) and connector on the left.  Pin 1 is the top left pin (the
left column are all odd numbered pins) and pin 2 is immediately to its
right (right hand column is all the even pins).  There is also small 1
and 2 on the PCB silk screen above the socket and a 19 and 20 below
the socket.

```
Pin Number   Description       Color    PCA10001 
----------   ---------------   ------   --------- 
1.           Vcc 3V            Red      p4.Vcc
2.           LED1              White    n/c
3.           UART_RX           Grey     n/c
4.           UART_TX           Purple   n/c
5.           SW2               Blue     n/c
6.           Temperature       Green    n/c
7.           SPI_CLK           Yellow   P4.12
8.           BUSY              Orange   p3.05
9.           PWM               Brown    p3.03
10.          /RESET            Black    p3,04
11.          PANEL_ON          Red      p3.00
12.          DISCHARGE         White    p3.02
13.          BORDER_CONTROL    Grey     p3.01
14.          SPI_MISO          Purple   p4.13
15.          SPI_MOSI          Blue     p4.14
16.          RST/SBWTDIO       Green    n/c
17.          TEST/SBWTCK       Yellow   n/c
18.          /FLASH_CS         Orange   n/c
19.          /EPD_CS           Brown    p4.15
20.          GND               Black    p4.GND         
```
### Notes

* The above values marked as *n/c*, and are not connected to the PCA10001 board.  
* Active low signals are indicated with a leading slash, e.g. */RESET*

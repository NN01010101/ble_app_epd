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

Pin Number   Description       Color    PCA10001 
----------   ---------------   ------   --------- 
1.           Vcc 3V            Red      3.3V
2.           *(LED1)*          White    -
3.           *(UART_RX)*       Grey     -
4.           *(UART_TX)*       Purple   -
5.           *(SW2)*           Blue     -
6.           Temperature       Green    -
7.           SPI\_CLK          Yellow   P5.20
8.           BUSY              Orange   p6.29
9.           PWM               Brown    p6.27
10.          /RESET            Black    p6.28
11.          PANEL\_ON         Red      p6.24
12.          DISCHARGE         White    p6.26
13.          BORDER_CONTROL    Grey     p6.25
14.          SPI_MISO          Purple   p5.21
15.          SPI_MOSI          Blue     p5.22
16.          *(RST/SBWTDIO)*   Green    -
17.          *(TEST/SBWTCK)*   Yellow   -
18.          FLASH\_CS         Orange   p6.30
19.          /EPD\_CS          Brown    p5.23
20.          GND               Black    GND         

### Notes

* The above values in parentheses like *(SW2)*, are not connected
  to the driver circuit and can be left open on non-LaunchPad
  projects.  These are only provided so that all the LaunchPad pins
  are brought through to the 20 pin connector.
* Active low signals are indicated with a leading solidus (slash) e.g. /RESET
* The ICSP pins on a Leonardo have a small dot to mark pin 1 and the letters ICSP
  above it; pin 2 is to the right of pin 1, same as the normal IDC ribbon cable order
  i.e. left colum 1,3,5 and right column 2,4,6. 

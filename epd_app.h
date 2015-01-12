/*---------------------------------------------------------------------------*/
/* Copyright (c) 2014 Robin Callender. All Rights Reserved.                  */
/*---------------------------------------------------------------------------*/
#ifndef __EPD_APP_H__
#define __EPD_APP_H__

#include <stdint.h>

void epd_commands(uint8_t * string, uint16_t length);
void epd_process(void);

#endif /* __EPD_APP_H__ */

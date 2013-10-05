/*
$Id:$

ST7565 LCD library!

Copyright (C) 2010 Limor Fried, Adafruit Industries

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

// some of this code was written by <cstone@pobox.com> originally; it is in the public domain.

 20121012 // dmo@nanibox.com // modified for ARM and plain C!
*/

//-----------------------------------------------------------------------------
#ifndef __ST7565_h__
#define __ST7565_h__

//-----------------------------------------------------------------------------
#include "ch.h"
#include "hal.h"
#include "kb_util.h"

//-----------------------------------------------------------------------------
#define COLOUR_BLACK 1
#define COLOUR_WHITE 0

//-----------------------------------------------------------------------------
#define LCDWIDTH					128
#define LCDHEIGHT					32
#define NUM_PAGES					(32>>3)
#define ST7565_BUFFER_SIZE			(LCDWIDTH*LCDHEIGHT>>3)  // 512 bytes

//-----------------------------------------------------------------------------
// chars to pixels
#define CHAR_WIDTH 		6
#define CHAR_HEIGHT 	7
#define C2P(c) 			(c*CHAR_WIDTH)

//-----------------------------------------------------------------------------
typedef struct ST7565Config ST7565Config;
struct ST7565Config
{
	SPIConfig spicfg;
	PortPad A0;
	PortPad Reset;
};

//-----------------------------------------------------------------------------
typedef struct ST7565Driver ST7565Driver;
struct ST7565Driver
{
	const ST7565Config * cfgp;
	SPIDriver * spip;
	uint8_t * buffer;
};

//-----------------------------------------------------------------------------
extern ST7565Driver ST7565D1;

//-----------------------------------------------------------------------------
void st7565Start(ST7565Driver * stdp, const ST7565Config * stcfgp, SPIDriver * spip, uint8_t * buffer);
void st7565_display(ST7565Driver * stdp);
void st7565_clear_display(ST7565Driver * stdp);
void st7565_clear(ST7565Driver * stdp);
void st7565_drawchar(ST7565Driver * stdp, int8_t x, uint8_t line, char c);
void st7565_drawstring(ST7565Driver * stdp, int8_t x, uint8_t line, const char *str);
void st7565_setpixel(ST7565Driver * stdp, int8_t x, uint8_t y, uint8_t colour);
void st7565_drawline(ST7565Driver * stdp, int8_t x0, uint8_t y0, int8_t x1, uint8_t y1, uint8_t color);
void st7565_drawrect(ST7565Driver * stdp, int8_t x, uint8_t y, int8_t w, uint8_t h, uint8_t color);
void st7565_fillrect(ST7565Driver * stdp, int8_t x, uint8_t y, int8_t w, uint8_t h, uint8_t color);

#endif //  __ST7565_h__

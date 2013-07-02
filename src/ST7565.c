/*
$Id:$

ST7565 LCD library!

// some of this code was written by <cstone@pobox.com> originally; it is in the public domain.
// parts modified to work with the NHD_C12832A by talsit@talsit.org
// 20121012 // dmo@nanibox.com // modified for ARM and plain C!
// Copyright ( C ) 2010 Limor Fried, Adafruit Industries

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or ( at your option ) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

*/

//----------------------------------------------------------------------------
#include "ch.h"
#include "hal.h"
#include "string.h"
#include "ST7565.h"
#include <stdlib.h>

ST7565Driver ST7565D1;

extern const uint8_t ST7565font[];
static const uint8_t pagemap[] = { 3,2,1,0 };
/**/ //const static uint8_t pagemap[] = { 0, 1, 2, 3 };
static const uint8_t st7565_nanibox[]=
{
0x07, 0x07, 0x0e, 0x0e, 0x0f, 0x0b, 0x09, 0x19, 0x18, 0x10, 0x10, 0x30, 0x30, 0x30, 0x20, 0x20,
0x60, 0x60, 0x40, 0x40, 0xc0, 0xc0, 0x80, 0x80, 0xc0, 0xc0, 0x40, 0x41, 0x61, 0x63, 0x63, 0x22,
0x26, 0x36, 0x3c, 0x3c, 0x1c, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0x60, 0x60, 0x30, 0x30, 0x18, 0x18,
0x1f, 0x1f, 0x18, 0x30, 0x30, 0x30, 0x60, 0x60, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0f, 0x1f, 0x1e,
0x1e, 0x1e, 0x1f, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x0f, 0x1f, 0x1e, 0x1e, 0x1f,
0x1f, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x03, 0x07, 0x0f, 0x1f, 0x1e, 0x1e, 0x1e, 0x1f, 0x0f, 0x07,
0x03, 0x00, 0x00, 0x9f, 0xdf, 0xdf, 0x9f, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xe0,
0xe7, 0xff, 0xff, 0xff, 0x79, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x0f, 0x1f, 0x1e, 0x1e, 0x1f,
0x0f, 0x0f, 0x07, 0x01, 0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x01, 0x01, 0x01, 0x1f, 0x1f, 0x1f, 0x1f,

0xe0, 0xf0, 0x38, 0x1c, 0x0e, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x07, 0x0e, 0x0c, 0x18,
0x38, 0x70, 0x60, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xfe, 0xfe, 0xfe, 0x00,
0x00, 0x00, 0xfe, 0xfe, 0xfe, 0xfe, 0x00, 0x00, 0xf0, 0xf8, 0xfc, 0xfc, 0x3e, 0x1e, 0x3e, 0x00,
0xfe, 0xfe, 0xfe, 0xfe, 0x00, 0x00, 0xfe, 0xfe, 0xfe, 0xfe, 0x00, 0x00, 0x00, 0xfe, 0xfe, 0xfe,
0xfe, 0x00, 0x00, 0xfe, 0xfe, 0xfe, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xfe, 0xfe, 0xfe, 0x00,
0x9e, 0x9e, 0xfe, 0xfe, 0xfc, 0xf8, 0x00, 0x00, 0xe0, 0xf8, 0xfc, 0xfc, 0x3e, 0x1e, 0x1e, 0x3e,
0xfc, 0xfc, 0xf8, 0xe0, 0x00, 0x3e, 0xfe, 0xfe, 0xfe, 0xc0, 0xc0, 0xc0, 0xfe, 0xfe, 0xfe, 0x3e,

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0x60, 0x70, 0x38, 0x1c, 0x0c, 0x0e,
0xff, 0xff, 0x0e, 0x0c, 0x1c, 0x38, 0x70, 0x60, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0x00, 0x3c, 0x7e, 0x66, 0x66, 0x6e, 0x2c, 0x00,
0x3c, 0x7e, 0x66, 0x66, 0x7e, 0x3c, 0x00, 0x00, 0x3e, 0x7e, 0x60, 0x7e, 0x7e, 0x60, 0x7e, 0x3e,
};


#define CMD_DISPLAY_OFF				0xAE
#define CMD_DISPLAY_ON				0xAF

#define CMD_SET_DISP_START_LINE		0x40
#define CMD_SET_PAGE				0xB0

#define CMD_SET_COLUMN_UPPER		0x10
#define CMD_SET_COLUMN_LOWER		0x00

#define CMD_SET_ADC_NORMAL			0xA0
#define CMD_SET_ADC_REVERSE			0xA1

#define CMD_SET_DISP_NORMAL			0xA6
#define CMD_SET_DISP_REVERSE		0xA7

#define CMD_SET_COM_NORMAL			0xC0
#define CMD_SET_COM_REVERSE			0xC8

#define CMD_SET_ALLPTS_NORMAL		0xA4
#define CMD_SET_ALLPTS_ON			0xA5

#define CMD_SET_BIAS_9				0xA2 
#define CMD_SET_BIAS_7				0xA3

#define CMD_RMW						0xE0
#define CMD_RMW_CLEAR				0xEE

#define CMD_INTERNAL_RESET			0xE2

#define CMD_SET_POWER_CONTROL		0x28
#define CMD_SET_RESISTOR_RATIO		0x20
#define CMD_SET_VOLUME_FIRST		0x81
#define CMD_SET_VOLUME_SECOND		0x00

#define CMD_SET_STATIC_OFF			0xAC
#define CMD_SET_STATIC_ON			0xAD
#define CMD_SET_STATIC_REG			0x00

#define CMD_SET_BOOSTER_FIRST		0xF8
#define CMD_SET_BOOSTER_234			0
#define CMD_SET_BOOSTER_5			1
#define CMD_SET_BOOSTER_6			3

#define CMD_NOP						0xE3
#define CMD_TEST					0xF0

#define enablePartialUpdate
#ifdef enablePartialUpdate
	static uint8_t xUpdateMin, xUpdateMax, yUpdateMin, yUpdateMax;
	static void updateBoundingBox( uint8_t xmin, uint8_t ymin, uint8_t xmax, uint8_t ymax ) 
	{
		if ( xmin < xUpdateMin ) xUpdateMin = xmin;
		if ( xmax > xUpdateMax ) xUpdateMax = xmax;
		if ( ymin < yUpdateMin ) yUpdateMin = ymin;
		if ( ymax > yUpdateMax ) yUpdateMax = ymax;
	}
#else
#define updateBoundingBox( a,b,c,d ) {}
#endif

#define ST7565_CMD_MODE(x) palClearPad(x->cfgp->A0.port, x->cfgp->A0.pad);
#define ST7565_DATA_MODE(x) palSetPad(x->cfgp->A0.port, x->cfgp->A0.pad);
//#define READ_BYTE_MEM(x) (*(uint8_t*)x)
//#define _BV(bit) (1 << (bit))

//----------------------------------------------------------------------------
void st7565Start(ST7565Driver * stdp, const ST7565Config * stp, SPIDriver * spip, uint8_t * buffer)
{
	stdp->cfgp = stp;
	stdp->spip = spip;
	stdp->buffer = buffer;
	
	spiStart(stdp->spip, &stdp->cfgp->spicfg);
	spiSelect(stdp->spip);

	chThdSleepMilliseconds(50);
	palClearPad(stdp->cfgp->Reset.port, stdp->cfgp->Reset.pad);
	chThdSleepMilliseconds(50);
	palSetPad(stdp->cfgp->Reset.port, stdp->cfgp->Reset.pad);
	chThdSleepMilliseconds(10);

	ST7565_CMD_MODE(stdp);
	spiPolledExchange(stdp->spip, CMD_DISPLAY_OFF);
	spiPolledExchange(stdp->spip, CMD_SET_ADC_REVERSE);
	spiPolledExchange(stdp->spip, CMD_SET_COM_REVERSE);
	spiPolledExchange(stdp->spip, CMD_SET_DISP_NORMAL);
	spiPolledExchange(stdp->spip, CMD_SET_BIAS_9);
	spiPolledExchange(stdp->spip, CMD_SET_POWER_CONTROL|0x07);
	spiPolledExchange(stdp->spip, CMD_SET_RESISTOR_RATIO|0x01);
	spiPolledExchange(stdp->spip, CMD_SET_ALLPTS_NORMAL);
	spiPolledExchange(stdp->spip, CMD_SET_VOLUME_FIRST);
	spiPolledExchange(stdp->spip, CMD_SET_VOLUME_SECOND | (0x23 & 0x3f));
	spiPolledExchange(stdp->spip, CMD_DISPLAY_ON);

	spiUnselect(stdp->spip);

	updateBoundingBox(0, 0, LCDWIDTH-1, LCDHEIGHT-1);

	memcpy(buffer, st7565_nanibox, sizeof(st7565_nanibox));
	st7565_display(stdp);
}

#define SWIZZLE_BITS(X) __RBIT(X)>>24


//----------------------------------------------------------------------------
void st7565_display(ST7565Driver * stdp)
{
	spiStart(stdp->spip, &stdp->cfgp->spicfg);
	spiSelect(stdp->spip);
	for( uint8_t page = 0; page < NUM_PAGES; page++ ) 
	{
#ifdef enablePartialUpdate
		// check if this page is part of update
		if ( yUpdateMin >= ( ( page+1 )*8 ) ) 
			continue;   // nope, skip it!
		if ( yUpdateMax < page*8 )
			break;

		uint8_t col = xUpdateMin;
		uint8_t maxcol = xUpdateMax;
#else
		// start at the beginning of the row
		uint8_t col = 0;
		uint8_t maxcol = LCDWIDTH-1;
#endif

		ST7565_CMD_MODE(stdp);
		spiPolledExchange(stdp->spip, CMD_SET_PAGE | pagemap[page]);
		spiPolledExchange(stdp->spip, CMD_SET_COLUMN_LOWER | ( (col+4) & 0x0f ));
		spiPolledExchange(stdp->spip, CMD_SET_COLUMN_UPPER | ( ( (col+4) >> 4 ) & 0x0f ));
		spiPolledExchange(stdp->spip, CMD_RMW );
		
		ST7565_DATA_MODE(stdp);
		uint16_t page_offset = LCDWIDTH*page;
		for( ; col <= maxcol; col++ )
			spiPolledExchange( stdp->spip, stdp->buffer[page_offset+col] );
			/**/ //spiPolledExchange( stdp->spip, SWIZZLE_BITS(stdp->buffer[page_offset+(LCDWIDTH-1)-col]) );
	}
#ifdef enablePartialUpdate
	xUpdateMin = LCDWIDTH-1;
	xUpdateMax = 0;
	yUpdateMin = LCDHEIGHT-1;
	yUpdateMax = 0;
#endif
	spiUnselect(stdp->spip);
}

//----------------------------------------------------------------------------
void
st7565_clear(ST7565Driver * stdp)
{
	memset(stdp->buffer, 0, ST7565_BUFFER_SIZE);
	updateBoundingBox(0, 0, LCDWIDTH-1, LCDHEIGHT-1);
}

//----------------------------------------------------------------------------
void
st7565_clear_display(ST7565Driver * stdp)
{
	for( uint8_t p = 0; p < NUM_PAGES; p++ ) 
	{
		ST7565_CMD_MODE(stdp);
		spiPolledExchange(stdp->spip, CMD_SET_PAGE | p );
		for( uint8_t c = 0; c < LCDWIDTH; c++ ) 
		{
			ST7565_CMD_MODE(stdp);
			spiPolledExchange(stdp->spip, CMD_SET_COLUMN_LOWER | (c & 0xf));
			spiPolledExchange(stdp->spip, CMD_SET_COLUMN_UPPER | ((c >> 4)  & 0xf));
			ST7565_DATA_MODE(stdp);
			spiPolledExchange(stdp->spip, 0x0);
		}     
	}
}

//----------------------------------------------------------------------------
void 
st7565_drawchar(ST7565Driver * stdp, int8_t x, uint8_t line, char c)
{
	if ( x < 0 )
		x = (LCDWIDTH-1) + x;
	for ( uint8_t i =0; i<5; i++ ) 
	{
		stdp->buffer[x+i+( line*128 ) ] = ST7565font[ c*5+i ];
	}
	updateBoundingBox(x, line*8, x+5, line*8 + 8);
}

//----------------------------------------------------------------------------
void 
st7565_drawstring(ST7565Driver * stdp, int8_t x, uint8_t line, const char *str)
{
	if ( x < 0 )
		x = (LCDWIDTH-1) + x;
	while (*str) 
	{
		if (*str == '\n')
		{
			x = 0;
			line++;
			str++;
			continue;
		}
		st7565_drawchar(stdp, x, line, *str);
		str++;
		x += 6; // 6 pixels wide
		if (x + 6 >= LCDWIDTH) 
		{
			x = 0;    // ran out of this line
			line++;
		}
		if (line >= (LCDHEIGHT >> 3))
			return;        // ran out of space :( 
	}
}

//----------------------------------------------------------------------------
void 
st7565_setpixel(ST7565Driver * stdp, int8_t x, uint8_t y, uint8_t colour)
{
	if ( x < 0 )
		x = (LCDWIDTH-1) + x;
	if ( ( x < 0 ) || ( y >= LCDHEIGHT ) )
		return;

	// x is which column
	if ( colour ) 
		stdp->buffer[x+(y/8)*LCDWIDTH] |= 1<<(7-(y%8));  
	else
		stdp->buffer[x+(y/8)*LCDWIDTH] &= ~(1<<(7-(y%8))); 

	updateBoundingBox(x, y, x, y);
}

//----------------------------------------------------------------------------
// bresenham's algorithm - thx wikpedia
void
st7565_drawline(ST7565Driver * stdp, int8_t x0, uint8_t y0, int8_t x1, uint8_t y1, uint8_t color)
{
	if ( x0 < 0 )
		x0 = (LCDWIDTH-1) + x0;
	if ( x1 < 0 )
		x1 = (LCDWIDTH-1) + x1;
	uint8_t steep = abs( y1 - y0 ) > abs( x1 - x0 );
	if ( steep )
	{
		swap_u8( x0, y0 );
		swap_u8( x1, y1 );
	}

	if ( x0 > x1 )
	{
		swap_u8( x0, x1 );
		swap_u8( y0, y1 );
	}

	// much faster to put the test here, since we've already sorted the points
	updateBoundingBox( x0, y0, x1, y1 );

	uint8_t dx, dy;
	dx = x1 - x0;
	dy = abs( y1 - y0 );

	int8_t err = dx / 2;
	int8_t ystep;

	if ( y0 < y1 )
		ystep = 1;
	else
		ystep = -1;

	for ( ; x0<=x1; x0++ )
	{
		if ( steep )
			st7565_setpixel( stdp, y0, x0, color );
		else
			st7565_setpixel( stdp, x0, y0, color );
		err -= dy;
		if ( err < 0 )
		{
			y0 += ystep;
			err += dx;
		}
	}
}

//----------------------------------------------------------------------------
void
st7565_drawrect(ST7565Driver * stdp, int8_t x, uint8_t y, int8_t w, uint8_t h, uint8_t color)
{
	if ( x < 0 )
		x = (LCDWIDTH-1) + x;
	// stupidest version - just pixels - but fast with internal buffer!
	for ( uint8_t i=x; i<x+w; i++ )
	{
		st7565_setpixel( stdp, i, y, color );
		st7565_setpixel( stdp, i, y+h-1, color );
	}
	for ( uint8_t i=y; i<y+h; i++ )
	{
		st7565_setpixel( stdp, x, i, color );
		st7565_setpixel( stdp, x+w-1, i, color );
	}

	updateBoundingBox( x, y, x+w, y+h );
}

//----------------------------------------------------------------------------
void
st7565_fillrect(ST7565Driver * stdp, int8_t x, uint8_t y, int8_t w, uint8_t h, uint8_t color)
{
	if ( x < 0 )
		x = (LCDWIDTH-1) + x;
	// stupidest version - just pixels - but fast with internal buffer!
	for ( uint8_t i=x; i<x+w; i++ )
		for ( uint8_t j=y; j<y+h; j++ )
			st7565_setpixel( stdp, i, j, color );

	updateBoundingBox( x, y, x+w, y+h );

}

/*
//----------------------------------------------------------------------------
#define ST7565_STARTBYTES 0
#define swap(a, b) { uint8_t t = a; a = b; b = t; }

//----------------------------------------------------------------------------
uint8_t is_reversed = 0;

//----------------------------------------------------------------------------
// a handy reference to where the pages are on the screen
const uint8_t pagemap[] = { 3, 2, 1, 0 };


//----------------------------------------------------------------------------
// a 5x7 font table

//----------------------------------------------------------------------------
static const char HEX_CHARS[] = "0123456789ABCDEF";

//----------------------------------------------------------------------------
// the memory buffer for the LCD
static uint8_t st7565_buffer[]=
{
0x07, 0x07, 0x0e, 0x0e, 0x0f, 0x0b, 0x09, 0x19, 0x18, 0x10, 0x10, 0x30, 0x30, 0x30, 0x20, 0x20,
0x60, 0x60, 0x40, 0x40, 0xc0, 0xc0, 0x80, 0x80, 0xc0, 0xc0, 0x40, 0x41, 0x61, 0x63, 0x63, 0x22,
0x26, 0x36, 0x3c, 0x3c, 0x1c, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0x60, 0x60, 0x30, 0x30, 0x18, 0x18,
0x1f, 0x1f, 0x18, 0x30, 0x30, 0x30, 0x60, 0x60, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0f, 0x1f, 0x1e,
0x1e, 0x1e, 0x1f, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x0f, 0x1f, 0x1e, 0x1e, 0x1f,
0x1f, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x03, 0x07, 0x0f, 0x1f, 0x1e, 0x1e, 0x1e, 0x1f, 0x0f, 0x07,
0x03, 0x00, 0x00, 0x9f, 0xdf, 0xdf, 0x9f, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xe0,
0xe7, 0xff, 0xff, 0xff, 0x79, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x0f, 0x1f, 0x1e, 0x1e, 0x1f,
0x0f, 0x0f, 0x07, 0x01, 0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x01, 0x01, 0x01, 0x1f, 0x1f, 0x1f, 0x1f,

0xe0, 0xf0, 0x38, 0x1c, 0x0e, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x07, 0x0e, 0x0c, 0x18,
0x38, 0x70, 0x60, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xfe, 0xfe, 0xfe, 0x00,
0x00, 0x00, 0xfe, 0xfe, 0xfe, 0xfe, 0x00, 0x00, 0xf0, 0xf8, 0xfc, 0xfc, 0x3e, 0x1e, 0x3e, 0x00,
0xfe, 0xfe, 0xfe, 0xfe, 0x00, 0x00, 0xfe, 0xfe, 0xfe, 0xfe, 0x00, 0x00, 0x00, 0xfe, 0xfe, 0xfe,
0xfe, 0x00, 0x00, 0xfe, 0xfe, 0xfe, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xfe, 0xfe, 0xfe, 0x00,
0x9e, 0x9e, 0xfe, 0xfe, 0xfc, 0xf8, 0x00, 0x00, 0xe0, 0xf8, 0xfc, 0xfc, 0x3e, 0x1e, 0x1e, 0x3e,
0xfc, 0xfc, 0xf8, 0xe0, 0x00, 0x3e, 0xfe, 0xfe, 0xfe, 0xc0, 0xc0, 0xc0, 0xfe, 0xfe, 0xfe, 0x3e,

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0x60, 0x70, 0x38, 0x1c, 0x0c, 0x0e,
0xff, 0xff, 0x0e, 0x0c, 0x1c, 0x38, 0x70, 0x60, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0x00, 0x3c, 0x7e, 0x66, 0x66, 0x6e, 0x2c, 0x00,
0x3c, 0x7e, 0x66, 0x66, 0x7e, 0x3c, 0x00, 0x00, 0x3e, 0x7e, 0x60, 0x7e, 0x7e, 0x60, 0x7e, 0x3e,
};

#define READ_BYTE_MEM(x) (*(uint8_t*)x)
#define _BV(bit) (1 << (bit))

//----------------------------------------------------------------------------
// reduces how much is refreshed, which speeds it up!
// originally derived from Steve Evans/JCW's mod but cleaned up and
// optimized
#define enablePartialUpdate
#ifdef enablePartialUpdate
	static uint8_t xUpdateMin, xUpdateMax, yUpdateMin, yUpdateMax;
	static void updateBoundingBox( uint8_t xmin, uint8_t ymin, uint8_t xmax, uint8_t ymax ) 
	{
		if ( xmin < xUpdateMin ) xUpdateMin = xmin;
		if ( xmax > xUpdateMax ) xUpdateMax = xmax;
		if ( ymin < yUpdateMin ) yUpdateMin = ymin;
		if ( ymax > yUpdateMax ) yUpdateMax = ymax;
	}
#else
#define updateBoundingBox( a,b,c,d ) {}
#endif

//----------------------------------------------------------------------------
void 
ST7565::drawbitmap( uint8_t x, 
					uint8_t y,
					const uint8_t * bitmap, 
					uint8_t w, 
					uint8_t h,
					uint8_t color ) 
{
	for ( uint8_t j=0; j<h; j++ ) 
	{
		for ( uint8_t i=0; i<w; i++ ) 
		{
			if ( READ_BYTE_MEM( bitmap + i + ( j/8 )*w ) & _BV( j%8 ) ) 
			{
				my_setpixel( x+i, y+j, color );
			}
		}
	}
	updateBoundingBox( x, y, x+w, y+h );
}

//----------------------------------------------------------------------------
void 
ST7565::drawstring( uint8_t x, uint8_t line, const char * c ) 
{
	while ( *c ) 
	{
		drawchar( x, line, *c );
		c++;
		x += 6; // 6 pixels wide
		while ( x + 6 >= LCDWIDTH ) 
		{
			x = 0;    // ran out of this line
			line++;
		}
		if ( line >= ( LCDHEIGHT >> 3 ) )
			return;        // ran out of space :( 
	}
}

//----------------------------------------------------------------------------
void 
ST7565::drawstring_P( uint8_t x, uint8_t line, const char * str ) 
{
	while ( 1 ) 
	{
		char c = READ_BYTE_MEM( str++ );
		if ( !c )
			return;
		drawchar( x, line, c );
		x += 6; // 6 pixels wide
		if ( x + 6 >= LCDWIDTH ) 
		{
			x = 0;    // ran out of this line
			line++;
		}
		if ( line >= ( LCDHEIGHT >> 3 ) )
			return;        // ran out of space :( 
	}
}

//----------------------------------------------------------------------------
void
ST7565::drawchar( uint8_t x, uint8_t line, char c ) 
{
	for ( uint8_t i =0; i<5; i++ ) 
	{
		st7565_buffer[x+i+( line*128 ) ] = READ_BYTE_MEM( font+( c*5 )+i );
	}
	updateBoundingBox( x, line*8, x+5, line*8 + 8 );
}

//----------------------------------------------------------------------------
// bresenham's algorithm - thx wikpedia
void 
ST7565::drawline( uint8_t x0, 
				  uint8_t y0, 
				  uint8_t x1,
				  uint8_t y1,
				  uint8_t color ) 
{
	uint8_t steep = abs( y1 - y0 ) > abs( x1 - x0 );
	if ( steep ) 
	{
		swap( x0, y0 );
		swap( x1, y1 );
	}

	if ( x0 > x1 ) 
	{
		swap( x0, x1 );
		swap( y0, y1 );
	}

	// much faster to put the test here, since we've already sorted the points
	updateBoundingBox( x0, y0, x1, y1 );

	uint8_t dx, dy;
	dx = x1 - x0;
	dy = abs( y1 - y0 );

	char err = dx / 2;
	char ystep;

	if ( y0 < y1 ) 
		ystep = 1;
	else 
		ystep = -1;

	for ( ; x0<=x1; x0++ ) 	
	{
		if ( steep ) 
			my_setpixel( y0, x0, color );
		else 
			my_setpixel( x0, y0, color );
		err -= dy;
		if ( err < 0 ) 
		{
			y0 += ystep;
			err += dx;
		}
	}
}

//----------------------------------------------------------------------------
// filled rectangle
void 
ST7565::fillrect( uint8_t x,
				  uint8_t y, 
				  uint8_t w, 
				  uint8_t h, 
				  uint8_t color )
{
	// stupidest version - just pixels - but fast with internal buffer!
	for ( uint8_t i=x; i<x+w; i++ ) 
		for ( uint8_t j=y; j<y+h; j++ ) 
			my_setpixel( i, j, color );

	updateBoundingBox( x, y, x+w, y+h );
}

//----------------------------------------------------------------------------
// draw a rectangle
void 
ST7565::drawrect( uint8_t x, 
				  uint8_t y, 
				  uint8_t w, 
				  uint8_t h,
				  uint8_t color ) 
{
	// stupidest version - just pixels - but fast with internal buffer!
	for ( uint8_t i=x; i<x+w; i++ ) 
	{
		my_setpixel( i, y, color );
		my_setpixel( i, y+h-1, color );
	}
	for ( uint8_t i=y; i<y+h; i++ ) 
	{
		my_setpixel( x, i, color );
		my_setpixel( x+w-1, i, color );
	} 

	updateBoundingBox( x, y, x+w, y+h );
}

//----------------------------------------------------------------------------
// draw a circle outline
void
ST7565::drawcircle( uint8_t x0, 
					uint8_t y0, 
					uint8_t r, 
					uint8_t color ) 
{
	updateBoundingBox( x0-r, y0-r, x0+r, y0+r );

	char f = 1 - r;
	char ddF_x = 1;
	char ddF_y = -2 * r;
	char x = 0;
	char y = r;

	my_setpixel( x0, y0+r, color );
	my_setpixel( x0, y0-r, color );
	my_setpixel( x0+r, y0, color );
	my_setpixel( x0-r, y0, color );

	while ( x<y ) 
	{
		if ( f >= 0 ) 
		{
			y--;
			ddF_y += 2;
			f += ddF_y;
		}
		x++;
		ddF_x += 2;
		f += ddF_x;
	
		my_setpixel( x0 + x, y0 + y, color );
		my_setpixel( x0 - x, y0 + y, color );
		my_setpixel( x0 + x, y0 - y, color );
		my_setpixel( x0 - x, y0 - y, color );
		
		my_setpixel( x0 + y, y0 + x, color );
		my_setpixel( x0 - y, y0 + x, color );
		my_setpixel( x0 + y, y0 - x, color );
		my_setpixel( x0 - y, y0 - x, color );
	}
}

//----------------------------------------------------------------------------
void 
ST7565::fillcircle( uint8_t x0, 
					uint8_t y0, 
					uint8_t r, 
					uint8_t color )
{
	updateBoundingBox( x0-r, y0-r, x0+r, y0+r );

	char f = 1 - r;
	char ddF_x = 1;
	char ddF_y = -2 * r;
	char x = 0;
	char y = r;

	for ( uint8_t i=y0-r; i<=y0+r; i++ ) 
	{
		my_setpixel( x0, i, color );
	}

	while ( x<y ) 
	{
		if ( f >= 0 ) 
		{
			y--;
			ddF_y += 2;
			f += ddF_y;
		}
		x++;
		ddF_x += 2;
		f += ddF_x;
	
		for ( uint8_t i=y0-y; i<=y0+y; i++ ) 
		{
			my_setpixel( x0+x, i, color );
			my_setpixel( x0-x, i, color );
		} 
		for ( uint8_t i=y0-x; i<=y0+x; i++ ) 
		{
			my_setpixel( x0+y, i, color );
			my_setpixel( x0-y, i, color );
		}    
	}
}

//----------------------------------------------------------------------------
void 
ST7565::my_setpixel( uint8_t x, uint8_t y, uint8_t color ) 
{
	if ( ( x >= LCDWIDTH ) || ( y >= LCDHEIGHT ) )
		return;

	// x is which column
	if ( color ) 
		st7565_buffer[ x + ( y/8 )*128] |= _BV( 7-( y%8 ) );  
	else
		st7565_buffer[ x + ( y/8 )*128] &= ~_BV( 7-( y%8 ) ); 
}

//----------------------------------------------------------------------------
// the most basic function, set a single pixel
void 
ST7565::setpixel( uint8_t x, uint8_t y, uint8_t color ) 
{
	my_setpixel( x, y, color );
	updateBoundingBox( x, y, x, y );
}

//----------------------------------------------------------------------------
// the most basic function, get a single pixel
uint8_t 
ST7565::getpixel( uint8_t x, uint8_t y ) 
{
	if ( ( x >= LCDWIDTH ) || ( y >= LCDHEIGHT ) )
		return 0;

	return ( st7565_buffer[ x + ( y/8 )*128] >> ( 7-( y%8 ) ) ) & 0x1;  
}

//----------------------------------------------------------------------------
void 
ST7565::begin( uint8_t contrast ) 
{
	st7565_init();
	st7565_command( CMD_DISPLAY_ON );
	st7565_command( CMD_SET_ALLPTS_NORMAL );
	st7565_set_brightness( contrast );
}

//----------------------------------------------------------------------------
void 
ST7565::st7565_init( void ) 
{
	// set pin directions
	pinMode( sid, OUTPUT );
	pinMode( sclk, OUTPUT );
	pinMode( a0, OUTPUT );
	pinMode( rst, OUTPUT );
	pinMode( cs, OUTPUT );

	// toggle RST low to reset; CS low so it'll listen to us
	if ( cs > 0 )
		digitalWrite( cs, LOW );

	digitalWrite( rst, LOW );
	_delay_ms( 50 );
	digitalWrite( rst, HIGH );

	st7565_command( 0xA0 );
	st7565_command( 0xAE );
	st7565_command( 0xC0 );
	st7565_command( 0xA2 );
	st7565_command( 0x2F );
	st7565_command( 0x21 );
	st7565_command( 0x81 );
	st7565_command( 0x2F );
	st7565_command( CMD_SET_DISP_START_LINE );

	updateBoundingBox( 0, 0, LCDWIDTH-1, LCDHEIGHT-1 );
}

//----------------------------------------------------------------------------
void 
ST7565::st7565_command( uint8_t c ) 
{
	digitalWrite( a0, LOW );
	shiftOut( sid, sclk, MSBFIRST, c );
}

//----------------------------------------------------------------------------
void 
ST7565::st7565_data( uint8_t c ) 
{
	digitalWrite( a0, HIGH );
	shiftOut( sid, sclk, MSBFIRST, c );
}

//----------------------------------------------------------------------------
void 
ST7565::st7565_set_brightness( uint8_t val ) 
{
	st7565_command( CMD_SET_VOLUME_FIRST );
	st7565_command( CMD_SET_VOLUME_SECOND | ( val & 0x3f ) );
}

//----------------------------------------------------------------------------
void 
ST7565::display( void ) 
{
	for( uint8_t p = 0; p < NUM_PAGES; p++ ) 
	{
#ifdef enablePartialUpdate
		// check if this page is part of update
		if ( yUpdateMin >= ( ( p+1 )*8 ) ) 
			continue;   // nope, skip it!
		if ( yUpdateMax < p*8 )
			break;

		uint8_t col = xUpdateMin;
		uint8_t maxcol = xUpdateMax;
#else
		// start at the beginning of the row
		uint8_t col = 0;
		uint8_t maxcol = LCDWIDTH-1;
#endif

		st7565_command( CMD_SET_PAGE | pagemap[p] );
		st7565_command( CMD_SET_COLUMN_LOWER | ( ( col+ST7565_STARTBYTES ) & 0x0f ) );
		st7565_command( CMD_SET_COLUMN_UPPER | ( ( ( col+ST7565_STARTBYTES ) >> 4 ) & 0x0f ) );
		st7565_command( CMD_RMW );
		
		for( ; col <= maxcol; col++ )
			st7565_data( st7565_buffer[( 128*p )+col] );
	}

#ifdef enablePartialUpdate
	xUpdateMin = LCDWIDTH-1;
	xUpdateMax = 0;
	yUpdateMin = LCDHEIGHT-1;
	yUpdateMax = 0;
#endif
}

//----------------------------------------------------------------------------
// clear everything
void 
ST7565::clear( void ) 
{
	memset( st7565_buffer, 0, sizeof( st7565_buffer ) );
	updateBoundingBox( 0, 0, LCDWIDTH-1, LCDHEIGHT-1 );
}

//----------------------------------------------------------------------------
// this doesnt touch the buffer, just clears the display RAM - might be handy
void 
ST7565::clear_display( void ) 
{
	for( uint8_t p = 0; p < NUM_PAGES; p++ ) 
	{
		st7565_command( CMD_SET_PAGE | p );
		for( uint8_t c = 0; c < LCDWIDTH; c++ ) 
		{
			st7565_command( CMD_SET_COLUMN_LOWER | ( c & 0xf ) );
			st7565_command( CMD_SET_COLUMN_UPPER | ( ( c >> 4 ) & 0xf ) );
			st7565_data( 0x0 );
		}     
	}
}

//----------------------------------------------------------------------------
void sprinthex( const uint8_t * src, int slen, char * dst, int dlen )
{
	while( slen-- && dlen-- )
	{
		uint8_t l = 0x0f & *src;
		uint8_t h = (0xf0 & *src++) >> 4;
		*dst++ = HEX_CHARS[ h ];
		*dst++ = HEX_CHARS[ l ];
	}
	*dst = '\0';
}
*/

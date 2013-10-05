/*
	kuroBox / naniBox
	Copyright (c) 2013
	david morris-oliveros // naniBox.com

    This file is part of kuroBox / naniBox.

    kuroBox / naniBox is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    kuroBox / naniBox is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

//-----------------------------------------------------------------------------
#include "kb_util.h"

//-----------------------------------------------------------------------------
uint8_t
calc_checksum_8( uint8_t * buf, uint16_t buf_size )
{
	uint8_t xor = 0;
	uint16_t idx = 0;

	for ( ; idx < buf_size ; ++idx )
		xor ^= (uint8_t) buf[ idx ];

	return xor;
}

//-----------------------------------------------------------------------------
// the 8 bit fletcher algorithm (from uBlox datasheet)
// http://www.ietf.org/rfc/rfc1145.txt
// http://en.wikipedia.org/wiki/Fletcher's_checksum
uint16_t
calc_checksum_16( uint8_t * buf, uint16_t buf_size )
{
	uint8_t a = 0;
	uint8_t b = 0;

	while( buf_size-- )
	{
		a += *buf++;
		b += a;
	}

	return b<<8|a;
}


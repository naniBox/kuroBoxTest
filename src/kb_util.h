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

#ifndef _naniBox_kuroBox_nb_util
#define _naniBox_kuroBox_nb_util

#include "ch.h"
#include "hal.h"

//----------------------------------------------------------------------------
typedef struct PortPad PortPad;
struct PortPad
{
	ioportid_t port;
	uint16_t pad;
};

//----------------------------------------------------------------------------
typedef enum
{
	no_panic	= 0,
	unknown_panic = 1
} panic_msg_t;

//----------------------------------------------------------------------------
#define swap_u8(a,b) {uint8_t x=a;a=b;b=x;}
#define __PACKED__ __attribute__ ((packed))

// http://stackoverflow.com/questions/174356/ways-to-assert-expressions-at-build-time-in-c
#ifdef __GNUC__
#define STATIC_ASSERT_HELPER(expr, msg) \
    (!!sizeof(struct { unsigned int STATIC_ASSERTION__##msg: (expr) ? 1 : -1; }))
#define STATIC_ASSERT(expr, msg) \
    extern int (*assert_function__(void)) [STATIC_ASSERT_HELPER(expr, msg)]
#else
    #define STATIC_ASSERT(expr, msg)   						\
		extern char STATIC_ASSERTION__##msg[1]; 			\
		extern char STATIC_ASSERTION__##msg[(expr)?1:2]
#endif /* #ifdef __GNUC__ */

//----------------------------------------------------------------------------
#define KB_OK				0
#define KB_NOT_OK			1
#define KB_UNKNOWN_ERR		255

//-----------------------------------------------------------------------------
uint8_t  calc_checksum_8( uint8_t * buf, uint16_t buf_size );
uint16_t calc_checksum_16( uint8_t * buf, uint16_t buf_size );

#endif // _naniBox_kuroBox_nb_util

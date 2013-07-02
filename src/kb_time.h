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

#ifndef _naniBox_kuroBox_time
#define _naniBox_kuroBox_time

#include <ch.h>
#include <hal.h>
#include "kb_util.h"

//-----------------------------------------------------------------------------
struct __PACKED__ ltc_frame_t
{
	uint8_t frame_units:4;
	uint8_t user_bits_1:4;
	uint8_t frame_tens:2;
	uint8_t drop_frame_flag:1;
	uint8_t color_frame_flag:1;
	uint8_t user_bits_2:4;

	uint8_t seconds_units:4;
	uint8_t user_bits_3:4;
	uint8_t seconds_tens:3;
	uint8_t even_parity_bit:1;
	uint8_t user_bits_4:4;

	uint8_t minutes_units:4;
	uint8_t user_bits_5:4;
	uint8_t minutes_tens:3;
	uint8_t binary_group_flag_1:1;
	uint8_t user_bits_6:4;

	uint8_t hours_units:4;
	uint8_t user_bits_7:4;
	uint8_t hours_tens:2;
	uint8_t reserved:1;
	uint8_t binary_group_flag_2:1;
	uint8_t user_bits_8:4;

	uint16_t sync_word:16;
};
STATIC_ASSERT(sizeof(struct ltc_frame_t)==10, LTC_FRAME_SIZE); // 80bits

//-----------------------------------------------------------------------------
struct __PACKED__ smpte_timecode_t
{
	uint8_t hours;
	uint8_t minutes;
	uint8_t seconds;
	uint8_t frames;
};

//-----------------------------------------------------------------------------
void ltc_exti_cb(EXTDriver *extp, expchannel_t channel);
void ltc_icu_period_cb(ICUDriver *icup);
int kuroBoxTimeInit(void);

#endif // _naniBox_kuroBox_time

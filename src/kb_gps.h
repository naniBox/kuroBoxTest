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

#ifndef _naniBox_kuroBox_gps
#define _naniBox_kuroBox_gps

#include <hal.h>
#include "kb_util.h"

//-----------------------------------------------------------------------------
#define UBX_NAV_SOL_SIZE						60
struct __PACKED__ ubx_nav_sol_t
{
	uint16_t header;
	uint16_t id;
	uint16_t len;
	uint32_t itow;
	int32_t ftow;
	int16_t week;
	uint8_t gpsfix;
	uint8_t flags;
	int32_t ecefX;
	int32_t ecefY;
	int32_t ecefZ;
	uint32_t pAcc;

	int32_t ecefVX;
	int32_t ecefVY;
	int32_t ecefVZ;
	uint32_t sAcc;
	uint16_t pdop;
	uint8_t reserved1;
	uint8_t numSV;
	uint32_t reserved2;

	uint16_t cs;
};
STATIC_ASSERT(sizeof(struct ubx_nav_sol_t)==UBX_NAV_SOL_SIZE, UBX_NAV_SOL_SIZE);

//-----------------------------------------------------------------------------
void gps_timepulse_exti_cb(EXTDriver *extp, expchannel_t channel);
int kuroBoxGPSInit(void);
void ecef_to_lla(int32_t x, int32_t y, int32_t z, float * lat, float * lon, float * alt);

#endif // _naniBox_kuroBox_gps

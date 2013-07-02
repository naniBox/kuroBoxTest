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
#include "kb_gps.h"
#include "kb_util.h"
#include <string.h>
#include <math.h>

//-----------------------------------------------------------------------------
#define UBX_HEADER				0x62b5 //  little endian, so byte swapped
#define UBX_NAV_SOL_ID 			0x0601 //  little endian
uint8_t ubx_nav_sol_buffer[UBX_NAV_SOL_SIZE];
uint8_t ubx_nav_sol_idx;
uint32_t gps_pps;
uint32_t gps_pps_lastCount;
uint32_t gps_pps_diffCount;

//-----------------------------------------------------------------------------
static SerialConfig gps_cfg = {
	9600,
	0, 						// cr1;
	USART_CR2_STOP1_BITS,	// cr2;
	0 						// cr3;
};

//-----------------------------------------------------------------------------
void
ecef_to_lla(int32_t x, int32_t y, int32_t z, float * lat, float * lon, float * alt)
{
    float a = 6378137.0f;
    float e = 8.1819190842622e-2f;
    float b = 6356752.3142451793f; // sqrtf(powf(a,2) * (1-powf(e,2)));
    float ep = 0.082094437949695676f; // sqrtf((powf(a,2)-powf(b,2))/powf(b,2));
    float p = sqrt(pow(x,2)+pow(y,2));
    float th = atan2(a*z, b*p);
    *lon = atan2(y, x);
    *lat = atan2((z+ep*ep*b*pow(sin(th),3)), (p-e*e*a*pow(cos(th),3)));
    float n = a/sqrt(1-e*e*pow(sin(*lat),2));
    *alt = p/cos(*lat)-n;
    *lat = (*lat*180)/M_PI;
    *lon = (*lon*180)/M_PI;
}

//-----------------------------------------------------------------------------
static void
parse_and_store_nav_sol(void)
{
	struct ubx_nav_sol_t * nav_sol = (struct ubx_nav_sol_t*) ubx_nav_sol_buffer;

	if ( nav_sol->header == UBX_HEADER )
	{
		if ( nav_sol->id == UBX_NAV_SOL_ID )
		{
			uint16_t cs = calc_checksum_16( ubx_nav_sol_buffer+2, UBX_NAV_SOL_SIZE-4 );
			if ( nav_sol->cs == cs )
			{
				// valid packet!
				chSysLock();
					//kbs_setGpsEcef(nav_sol->ecefX, nav_sol->ecefY, nav_sol->ecefZ);
					//kbl_setGpsNavSol(nav_sol);
				chSysUnlock();
			}
		}
	}
	memset(ubx_nav_sol_buffer, 0, sizeof(ubx_nav_sol_buffer));
	ubx_nav_sol_idx = 0;
}

//-----------------------------------------------------------------------------
/*static Thread * gpsThread;*/
//-----------------------------------------------------------------------------
static WORKING_AREA(waGps, 128);
static msg_t
thGps(void *arg)
{
	(void)arg;
	chRegSetThreadName("Gps");

	memset(ubx_nav_sol_buffer, 0, sizeof(ubx_nav_sol_buffer));
	while( !chThdShouldTerminate() )
	{
		uint8_t c = 0;
		if ( sdRead(&SD6, &c, 1) != 1 )
			continue;

		if ( ( ubx_nav_sol_idx == 0 && c == (UBX_HEADER&0xff) ) ||
			 ( ubx_nav_sol_idx == 1 && c == ((UBX_HEADER>>8)&0xff) ) ||
			 ( ( ubx_nav_sol_idx > 1 ) &&
			   ( ubx_nav_sol_idx < UBX_NAV_SOL_SIZE ) ) )
			ubx_nav_sol_buffer[ubx_nav_sol_idx++] = c;
		else
			ubx_nav_sol_idx = 0;

		if ( ubx_nav_sol_idx == UBX_NAV_SOL_SIZE )
			parse_and_store_nav_sol();
	}
	return 0;
}

//-----------------------------------------------------------------------------
void
gps_timepulse_exti_cb(EXTDriver *extp, expchannel_t channel)
{
	(void)extp;
	(void)channel;

	gps_pps++;
	uint32_t gps_pps_thisCount = halGetCounterValue();
	gps_pps_diffCount = gps_pps_thisCount - gps_pps_lastCount;
	gps_pps_lastCount = gps_pps_thisCount;
}

//-----------------------------------------------------------------------------
int kuroBoxGPSInit(void)
{
	sdStart(&SD6, &gps_cfg);
	/*gpsThread = */chThdCreateStatic(waGps, sizeof(waGps), NORMALPRIO, thGps, NULL);
	return KB_OK;
}


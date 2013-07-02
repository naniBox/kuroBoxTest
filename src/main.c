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

#include <string.h>
#include <ch.h>
#include <hal.h>
#include <chprintf.h>
#include <memstreams.h>
#include <chrtclib.h>
#include <time.h>
#include "ST7565.h"
#include "kb_buttons.h"
#include "kb_time.h"
#include "kb_gps.h"

//-----------------------------------------------------------------------------
// static data
static uint8_t lcd_buffer[ST7565_BUFFER_SIZE];
extern struct smpte_timecode_t ltc_timecode;
extern uint32_t gps_pps;
extern uint32_t gps_pps_diffCount;
extern uint32_t real_seconds;

//-----------------------------------------------------------------------------
static SerialConfig serial1_cfg = {
	SERIAL_DEFAULT_BITRATE,
	0,
	USART_CR2_STOP1_BITS | USART_CR2_LINEN,
	0
};

//-----------------------------------------------------------------------------
static SerialConfig serial2_cfg = {
	SERIAL_DEFAULT_BITRATE,
	0,
	USART_CR2_STOP1_BITS | USART_CR2_LINEN,
	0
};

//-----------------------------------------------------------------------------
static const ST7565Config lcd_cfg = 
{
	{	// SPIConfig struct
		NULL,
		GPIOE,
		GPIOE_LCD_NSS,
		SPI_CR1_CPOL | SPI_CR1_CPHA
	},
	{ GPIOE, GPIOE_LCD_A0 },		// A0 pin
	{ GPIOE, GPIOE_LCD_RST }		// RST pin
};

//-----------------------------------------------------------------------------
static const EXTConfig extcfg = {
  {
	{EXT_CH_MODE_BOTH_EDGES | EXT_CH_MODE_AUTOSTART | EXT_MODE_GPIOA, btn_0_exti_cb},	// 0
	{EXT_CH_MODE_BOTH_EDGES | EXT_CH_MODE_AUTOSTART | EXT_MODE_GPIOA, btn_1_exti_cb},	// 1

    {EXT_CH_MODE_DISABLED, NULL},	// 2
	{EXT_CH_MODE_FALLING_EDGE | EXT_CH_MODE_AUTOSTART | EXT_MODE_GPIOC, gps_timepulse_exti_cb},	// 3
    {EXT_CH_MODE_DISABLED, NULL},	// 4
    {EXT_CH_MODE_DISABLED, NULL},	// 5
    {EXT_CH_MODE_DISABLED, NULL},	// 6
    {EXT_CH_MODE_DISABLED, NULL},	// 7
    {EXT_CH_MODE_DISABLED, NULL},	// 8
	{EXT_CH_MODE_BOTH_EDGES | EXT_CH_MODE_AUTOSTART | EXT_MODE_GPIOA, ltc_exti_cb},	// 9
    {EXT_CH_MODE_DISABLED, NULL},	// 10
    {EXT_CH_MODE_DISABLED, NULL},	// 11
    {EXT_CH_MODE_DISABLED, NULL},	// 12
    {EXT_CH_MODE_DISABLED, NULL},	// 13
    {EXT_CH_MODE_DISABLED, NULL},	// 14
    {EXT_CH_MODE_DISABLED, NULL},	// 15
    {EXT_CH_MODE_DISABLED, NULL},	// 16
    {EXT_CH_MODE_DISABLED, NULL},	// 17
    {EXT_CH_MODE_DISABLED, NULL},	// 18
    {EXT_CH_MODE_DISABLED, NULL},	// 19
    {EXT_CH_MODE_DISABLED, NULL},	// 20
    {EXT_CH_MODE_DISABLED, NULL},	// 21
    {EXT_CH_MODE_DISABLED, NULL}	// 22
  }
};

//-----------------------------------------------------------------------------
int
kuroBoxInit(void)
{
	palSetPad(GPIOB, GPIOB_LED1);
	palSetPad(GPIOB, GPIOB_LED2);
	palSetPad(GPIOA, GPIOA_LED3);

	// Serial
	sdStart(&SD1, &serial1_cfg);
	sdStart(&SD2, &serial2_cfg);

	// start the SPI bus, just use the LCD's SPI config since
	// it's shared with the eeprom
	spiStart(&SPID1, &lcd_cfg.spicfg);
	memset(lcd_buffer, 0, sizeof(lcd_buffer));
	st7565Start(&ST7565D1, &lcd_cfg, &SPID1, lcd_buffer);

	// gps uart
	kuroBoxGPSInit();

	// set initial button state.
	kuroBoxButtonsInit();

	// LTC's, though this is now driven purely through interrupts, and it's
	// VERY quick
	kuroBoxTimeInit();

	// indicate we're ready
	chThdSleepMilliseconds(100);
	palClearPad(GPIOB, GPIOB_LED1);
	palClearPad(GPIOB, GPIOB_LED2);
	palClearPad(GPIOA, GPIOA_LED3);

	// all external interrupts, all the system should now be ready for it
	extStart(&EXTD1, &extcfg);

	return KB_OK; 
}

//-----------------------------------------------------------------------------
int main(void) 
{
	halInit();
	chSysInit();
	kuroBoxInit();

	// wait X seconds to make sure the logger has started up...
	chThdSleepMilliseconds(2000);

	BaseSequentialStream * prnt = (BaseSequentialStream *)&SD1;
	static char charbuf[128];
	static MemoryStream msb;
	#define INIT_CBUF() \
		memset(charbuf,0,sizeof(charbuf));\
		msObjectInit(&msb, (uint8_t*)charbuf, 128, 0);
	BaseSequentialStream * bss = (BaseSequentialStream *)&msb;

	struct RTCTime rtc0;
	struct RTCTime rtc1;
	rtcGetTimeI(&RTCD1, &rtc0);
	rtcGetTimeI(&RTCD1, &rtc1);

	uint32_t rss0 = real_seconds;
	uint32_t rss1 = real_seconds;

	uint32_t gps0 = gps_pps;
	uint32_t gps1 = gps_pps;

	uint32_t ltc0 = ltc_timecode.seconds;
	uint32_t ltc1 = ltc_timecode.seconds;

	uint32_t hal_rtc = halGetCounterValue();
	uint32_t hal_gps = halGetCounterValue();
	uint32_t hal_rss = halGetCounterValue();
	uint32_t hal_ltc = halGetCounterValue();

	uint32_t hal_master = halGetCounterValue();

	uint32_t hal_rtc_diff = 0;
	uint32_t hal_rss_diff = 0;
	uint32_t hal_gps_diff = 0;
	uint32_t hal_ltc_diff = 0;

	int master_changed = 0;

	chprintf(prnt, "rtc,rss,ltc,gps,rtc_diff,rss_diff,ltc_diff,gps_diff,pps_diff\n\r");
	st7565_clear(&ST7565D1);
	while( 1 )
	{
		// get all counters
		rtcGetTimeI(&RTCD1, &rtc1);
		gps1 = gps_pps;
		ltc1 = ltc_timecode.seconds;
		rss1 = real_seconds;

		// calculate all crap
		if ( gps0 != gps1 )
		{
			hal_gps = halGetCounterValue();
			gps0 = gps1;
		}

		if ( ltc0 != ltc1 )
		{
			hal_ltc = halGetCounterValue();
			ltc0 = ltc1;
		}

		if ( rtc0.tv_time != rtc1.tv_time )
		{
			hal_rtc = halGetCounterValue();
			rtc0.tv_time = rtc1.tv_time;
		}

		if ( rss1 != rss0 )
		{
			hal_rss = halGetCounterValue();
			rss0 = rss1;
			master_changed = 1;
		}

		if ( master_changed )
		{
			hal_rtc_diff = hal_master - hal_rtc;
			hal_gps_diff = hal_master - hal_gps;
			hal_ltc_diff = hal_master - hal_ltc;
			hal_rss_diff = hal_master - hal_rss;
			hal_master = hal_rss;

			chprintf(prnt, "%d,%d,%d,%d,%d,%d,%d,%d,%d\n\r",
					rtc1.tv_time, rss1, ltc1, gps1,
					hal_rtc_diff, hal_rss_diff, hal_ltc_diff, hal_gps_diff, gps_pps_diffCount);

			if ( !is_btn_0_pressed() )
			{
				st7565_drawstring(&ST7565D1, 0, 0, "s");
				st7565_drawstring(&ST7565D1, 0, 1, "r");
				st7565_drawstring(&ST7565D1, 0, 2, "l");
				st7565_drawstring(&ST7565D1, 0, 3, "g");
				st7565_drawline(&ST7565D1, C2P(1), 0, C2P(1), 31, COLOUR_BLACK);

				INIT_CBUF();
				chprintf(bss,"%8d/%10d",
						rss1, hal_rss_diff);
				st7565_drawstring(&ST7565D1, C2P(1)+2, 0, charbuf);

				INIT_CBUF();
				chprintf(bss,"%8d/%10d",
						rtc1.tv_time, hal_rtc_diff);
				st7565_drawstring(&ST7565D1, C2P(1)+2, 1, charbuf);

				INIT_CBUF();
				chprintf(bss,"%8d/%10d",
						ltc1, gps_pps_diffCount);
				st7565_drawstring(&ST7565D1, C2P(1)+2, 2, charbuf);

				INIT_CBUF();
				chprintf(bss,"%8d/%10d",
						gps1, hal_gps_diff);
				st7565_drawstring(&ST7565D1, C2P(1)+2, 3, charbuf);

				st7565_display(&ST7565D1);
				st7565_clear(&ST7565D1);
			}

			master_changed = 0;
			palTogglePad(GPIOB, GPIOB_LED2);
		}
		palTogglePad(GPIOB, GPIOB_LED1);
	}
}


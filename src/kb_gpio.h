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
#ifndef _naniBox_kuroBox_gpio
#define _naniBox_kuroBox_gpio

//-----------------------------------------------------------------------------
#include <ch.h>
#include <hal.h>

//-----------------------------------------------------------------------------
#define kbg_setGPIO(on,port,pin) 	palWritePad(port,pin,on)
#define kbg_toggleGPIO(port,pin) 	palTogglePad(port,pin)
#define kbg_getGPIO(port,pin)		palReadPad(port,pin)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#define kbg_getBtn0()				(!kbg_getGPIO(GPIOA, GPIOA_BTN0))
#define kbg_getBtn1()				(!kbg_getGPIO(GPIOA, GPIOA_BTN1))

//-----------------------------------------------------------------------------
#define kbg_setLED1(on)				kbg_setGPIO(on, GPIOB, GPIOB_LED1)
#define kbg_toggleLED1()			kbg_toggleGPIO(GPIOB, GPIOB_LED1)
#define kbg_getLED1()				kbg_getGPIO(GPIOB, GPIOB_LED1)

#define kbg_setLED2(on)				kbg_setGPIO(on, GPIOB, GPIOB_LED2)
#define kbg_toggleLED2()			kbg_toggleGPIO(GPIOB, GPIOB_LED2)
#define kbg_getLED2()				kbg_getGPIO(GPIOB, GPIOB_LED2)

#define kbg_setLED3(on)				kbg_setGPIO(on, GPIOA, GPIOA_LED3)
#define kbg_toggleLED3()			kbg_toggleGPIO(GPIOB, GPIOB_LED3)
#define kbg_getLED3()				kbg_getGPIO(GPIOA, GPIOA_LED3)

//-----------------------------------------------------------------------------
#define kbg_setLCDBacklight(on)		kbg_setGPIO(!on, GPIOD, GPIOD_LCD_LED_DRIVE)
#define kbg_getLCDBacklight()		(!kbg_getGPIO(GPIOD, GPIOD_LCD_LED_DRIVE))

//-----------------------------------------------------------------------------
#define kbg_setSerial1Pwr(on)		kbg_setGPIO(!on, GPIOD, GPIOD_SERIAL1_PWR)
#define kbg_getSerial1Pwr()			(!kbg_getGPIO(GPIOD, GPIOD_SERIAL1_PWR))

#define kbg_setSerial2Pwr(on)		kbg_setGPIO(!on, GPIOD, GPIOD_SERIAL2_PWR)
#define kbg_getSerial2Pwr()			(!kbg_getGPIO(GPIOD, GPIOD_SERIAL2_PWR))

//-----------------------------------------------------------------------------
#define kbg_setL1Power(on)			kbg_setGPIO(!on, GPIOB, GPIOB_L1_PWR)
#define kbg_setL1PowerOn()			kbg_setL1Power(1)
#define kbg_setL1PowerOff()			kbg_setL1Power(0)

//-----------------------------------------------------------------------------
#endif // _naniBox_kuroBox_gpio

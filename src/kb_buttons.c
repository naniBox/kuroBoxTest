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

#include "kb_buttons.h"
#include "kb_util.h"

static bool_t btn_0_state;
static bool_t btn_1_state;

//-----------------------------------------------------------------------------
int kuroBoxButtonsInit(void)
{
	btn_0_state=palReadPad(GPIOA, GPIOA_BTN0);
	btn_1_state=palReadPad(GPIOA, GPIOA_BTN1);
	return KB_OK;
}

//-----------------------------------------------------------------------------
void btn_0_exti_cb(EXTDriver *extp, expchannel_t channel)
{
	(void)extp;
	(void)channel;
	btn_0_state=palReadPad(GPIOA, GPIOA_BTN0);
}

//-----------------------------------------------------------------------------
void btn_1_exti_cb(EXTDriver *extp, expchannel_t channel)
{
	(void)extp;
	(void)channel;
	btn_1_state=palReadPad(GPIOA, GPIOA_BTN1);
}

//-----------------------------------------------------------------------------
bool_t is_btn_0_pressed(void)
{
	return btn_0_state == 0;
}

//-----------------------------------------------------------------------------
bool_t is_btn_1_pressed(void)
{
	return btn_1_state == 0;
}

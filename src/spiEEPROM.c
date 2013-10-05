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

/*
	Usage example:

	uint8_t eeprombuf[SPIEEPROM_PAGE_SIZE];
	while( spiEepromWip(&spiEepromD1) )
	{}
	spiEepromReadPage(&spiEepromD1, 0, eeprombuf);
	for ( uint8_t idx = 0 ; idx < SPIEEPROM_PAGE_SIZE ; ++idx )
		chprintf((BaseSequentialStream *)&SD2, "Byte: %2d : 0x%02x\n\r", idx, eeprombuf[idx]);

	spiEepromEnableWrite??
	for ( uint8_t idx = 0 ; idx < SPIEEPROM_PAGE_SIZE ; ++idx )
		eeprombuf[idx] += idx;
	spiEepromWritePage(&spiEepromD1, 0, eeprombuf);

	volatile uint32_t count = 0;
	while( spiEepromWip(&spiEepromD1) )
	{count++;}
	chprintf((BaseSequentialStream *)&SD2, "Count: %d\n\r", count);

	spiEepromReadPage(&spiEepromD1, 0, eeprombuf);
	for ( uint8_t idx = 0 ; idx < SPIEEPROM_PAGE_SIZE ; ++idx )
		chprintf((BaseSequentialStream *)&SD2, "Byte: %2d : 0x%02x\n\r", idx, eeprombuf[idx]);

*/

//----------------------------------------------------------------------------
#include "spiEEPROM.h"
#include "ch.h"
#include "chprintf.h"

//----------------------------------------------------------------------------
spiEepromDriver spiEepromD1;

//----------------------------------------------------------------------------
#define OP_WREN			0x06	// Write Enable Latch
#define OP_WRDI			0x04	// Write Disable
#define OP_RDSR			0x05	// Read Status Register
#define OP_WRSR			0x01	// Write Status Register
#define OP_READ			0x03	// Read Data
#define OP_WRITE		0x02	// Write Data

//----------------------------------------------------------------------------
void 
spiEepromStart(spiEepromDriver * sedp, 
			   const spiEepromConfig * secp,
			   SPIDriver * spip)
{
	sedp->cfgp = secp;
	sedp->spip = spip;
}

//----------------------------------------------------------------------------
void
spiEepromReadPage(spiEepromDriver * sedp, uint16_t page, uint8_t * buf)
{
	uint32_t addr = page << SPIEEPROM_PAGE_SIZE_SHIFT;

	spiStart(sedp->spip, &sedp->cfgp->spicfg);
	spiSelect(sedp->spip);
	spiPolledExchange(sedp->spip, OP_READ);
#ifdef SPIEEPROM_24BIT_ADDRESS
	spiPolledExchange(sedp->spip, (addr>>16)&0xff);
#endif
	spiPolledExchange(sedp->spip, (addr>>8)&0xff);	
	spiPolledExchange(sedp->spip, addr&0xff);		
	for ( uint16_t idx = 0 ; idx < SPIEEPROM_PAGE_SIZE ; ++idx )
		*buf++ = spiPolledExchange(sedp->spip, 0);
	spiUnselect(sedp->spip);
}

//----------------------------------------------------------------------------
void
spiEepromWritePage(spiEepromDriver * sedp, uint16_t page, const uint8_t * buf)
{	
	uint32_t addr = page << SPIEEPROM_PAGE_SIZE_SHIFT;

	spiStart(sedp->spip, &sedp->cfgp->spicfg);
	spiSelect(sedp->spip);

	spiPolledExchange(sedp->spip, OP_WRITE);
#ifdef SPIEEPROM_24BIT_ADDRESS
	spiPolledExchange(sedp->spip, (addr>>16)&0xff);
#endif
	spiPolledExchange(sedp->spip, (addr>>8)&0xff);
	spiPolledExchange(sedp->spip, addr&0xff);
	for ( uint16_t idx = 0 ; idx < SPIEEPROM_PAGE_SIZE ; ++idx )
		spiPolledExchange(sedp->spip, *buf++);

	spiUnselect(sedp->spip);
}

//----------------------------------------------------------------------------
void
spiEepromEnableWrite(spiEepromDriver * sedp)
{
	spiStart(sedp->spip, &sedp->cfgp->spicfg);
	spiSelect(sedp->spip);
	spiPolledExchange(sedp->spip, OP_WREN);
	spiUnselect(sedp->spip);
}

//----------------------------------------------------------------------------
void
spiEepromDisableWrite(spiEepromDriver * sedp)
{
	spiStart(sedp->spip, &sedp->cfgp->spicfg);
	spiSelect(sedp->spip);
	spiPolledExchange(sedp->spip, OP_WRDI);
	spiUnselect(sedp->spip);
}

//----------------------------------------------------------------------------
uint8_t 
spiEepromReadSR(spiEepromDriver * sedp)
{
	spiStart(sedp->spip, &sedp->cfgp->spicfg);
	spiSelect(sedp->spip);
	spiPolledExchange(sedp->spip, OP_RDSR);
	uint8_t sr = spiPolledExchange(sedp->spip, 0x00);
	spiUnselect(sedp->spip);
	return sr;
}

//----------------------------------------------------------------------------
void 
spiEepromWriteSR(spiEepromDriver * sedp, uint8_t sr)
{
	spiStart(sedp->spip, &sedp->cfgp->spicfg);
	spiSelect(sedp->spip);
	spiPolledExchange(sedp->spip, OP_WRSR);
	spiPolledExchange(sedp->spip, sr);
	spiUnselect(sedp->spip);
}

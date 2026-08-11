#include <avr/io.h>
#include "std_macros.h"

void EEPROM_write (unsigned short address , unsigned char data)
{
	// assign address to EEAR
	
	EEARL=(char) address;
	EEARH =(char) (address>>8);
	
	// assign data to EEDR
	
	EEDR=data;
	
	// enable location write
	
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR,EEWE);
	
	
	// wait until the writing process finish
	
	while(READ_BIT(EECR,EEWE)==1);
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

unsigned char EEPROM_read(unsigned short address)
{
	// assign address to EEAR
	
	EEARL=(char) address;
	EEARH=(char)(address>>8);
	
	// enable location read
	
	SET_BIT(EECR,EERE);
	
    // return the data in that location
	
	return EEDR;
}	
	
	
	

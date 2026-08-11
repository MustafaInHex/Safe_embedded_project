#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "std_macros.h"
#include "DIO.h"
#include "LED.h"
#include "BUTTON.h"
#include "SEVENSEGMENT.h"
#include "EEPROM.h"
#include "LCD.h"
#include "KEYPAD.h"

#define LOC1 0X20
#define LOC2 0X21
#define LOC3 0X22
#define LOC4 0X23
#define LOC5 0X24

int main()
{
KEYPAD_initialize();
LCD_initialize();
LED_initialize('C',0);
LED_initialize('C',1);
BUZZER_initialize('c',2);


unsigned char check=0;
unsigned char trials=3;
unsigned char x;
int i;

while(EEPROM_read(LOC5)==0XFF)
{

LCD_writestring("Put pass:");	
	
	for(i=0;i<5;i++)
	{
		
	do{
		x=KEYPAD_read();
	}while(x==0xff);	
	
	EEPROM_write(LOC1+i,x);
	LCD_writecharacter(x);
	_delay_ms(500);
	LCD_movecursor(1,10+i);
	LCD_writecharacter('*');
	}
	}
	
	unsigned char arr[5];
	arr[0]=arr[1]=arr[2]=arr[3]=arr[4]=0xff;
	
	while(check==0 && trials>0)
	{
		LCD_clearscreen();
		LCD_writestring("pass:");
		
		for(i=0;i<5;i++)
		{
			do{
				arr[i]=KEYPAD_read();
		}while(arr[i]==0xff);
		
		LCD_writecharacter(arr[i]);
		LCD_movecursor(1,6+i);
		LCD_writecharacter('*');
		_delay_ms(500);
			}
			
			if (  arr[0]==EEPROM_read(LOC1) &&      arr[1]==EEPROM_read(LOC2)  &&  arr[2]==EEPROM_read(LOC3) &&    arr[3]==EEPROM_read(LOC4) &&  arr[4]==EEPROM_read(LOC5) )
			{
				check=1;
				LCD_clearscreen();
				LCD_writestring("CORRECT PASS");
				LCD_movecursor(2,1);
				LCD_writestring("SAFE OPENED");
				LED_on('C',0);
				_delay_ms(2000);
				LED_off('C',0);
			}
			
			else{
				trials--;
				if(trials==0)
				{
					LCD_clearscreen();
					LCD_writestring("SAFE CLOSED");
					LED_on('c',1);
					BUZZER_on('c',2);
					LCD_movecursor(2,1);
					LCD_writestring("WAIT 5 SEC TRY");
					_delay_ms(5000);
					LED_off('c',1);
					BUZZER_off('c',2);
					trials=1;
				}
				else{
				LCD_clearscreen();
				LCD_writestring("WRONG PASS");
				LCD_movecursor(2,1);
				LCD_writestring("TRIALS LEFT:");
				LCD_writecharacter(trials+48);
				LED_on('c',1);
				BUZZER_on('c',2);				
				_delay_ms(1000);
				LED_off('C',1);
				BUZZER_off('c',2);
				}
			}
		}		
		}												
	


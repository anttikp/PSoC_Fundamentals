/* 
create: 08.4.2019
autor: Miriam Nold
PSoC Fundamentals
Exercise 1

works fine, code ok

*/

#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules

char myName[] = "Miriam Nold";   // Define RAM string
char counter = 0;

void main(void)
{
	M8C_EnableGInt ;  // Turn on interrupts
	
	LED_Start();
	LED_Switch(1);         // Turn on LED

	SleepTimer_Start();
	SleepTimer_SetInterval(SleepTimer_8_HZ);   // Set interrupt to a
	SleepTimer_EnableInt(); // 8 Hz rate
	
  	LCD_Start();                  // Initialize LCD
   	LCD_Position(0,0);            // Place LCD cursor at row 0, col 0.
   	LCD_PrString(myName);         // Print "Miriam Nold" on the LCD
	

	
	while(1) {
		if (Button_Data_ADDR & Button_MASK){ // is the button pressed?
			counter++;
			SleepTimer_SyncWait(4, SleepTimer_WAIT_RELOAD); // wait for 0,5s
			LED_Invert();       // Flash LED
		}
		LCD_Position(1,0);           
   		LCD_PrHexByte(counter);		//Print the variable counter in hex
		
	}
}

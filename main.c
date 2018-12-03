/*
 * main.c
 *
 *  Created on: Apr 16, 2018
 *      Author: Mahmoud Mohamed Younis
 */

#include <avr/io.h>
#include "TIMER0_Delay.h"

int main(void)
{
	DDRD = 0xFF;
	PORTD = 0x00;
	while(1)
	{
		Timer0_delay_ms(250);
		PORTD ^= 0xFF;
	}
	return 0;
}

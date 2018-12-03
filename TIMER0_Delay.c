/*
 * Timer0_delay.c
 *
 *  Created on: Apr 16, 2018
 *      Author: Mahmoud Mohamed Younis
 */

/* To generate 1 msec
 * prescaler = 1:64
 * timer clock period = 0.125 * 64 = 8 µs
 * number of clocks = 1*1000/8 = 125
 * initial value  = 256 - 125 = 131 in decimal = 0x83
 */

#include "TIMER0_Delay.h"

void Timer0_delay_ms(unsigned int time)
{
	unsigned int count = 0;
	while(count != time)
	{
		TCCR0 |= (1<<CS00) | (1<<CS01);       // Prescaler = 1:64
		TCNT0  =  0x83;                       // Initial value
		while( (TIFR & (1<<TOV0)) == 0 );     // Wait until TIMER0 overflow
		TCCR0 = 0;                            // Stop counting
		TIFR |= (1<<TOV0);                    // Clear TOV0
		count++;
	}
}

/* To generate 1 µs
 * prescaler = 1:8
 * timer clock period = 0.125 * 8 = 1 µs
 * number of clocks = 1/1 = 1
 * initial value  = 256 - 1 = 255 in decimal = 0xFF
 */

void Timer0_delay_us(unsigned int time)
{
	unsigned int count = 0;
	while(count != time)
	{
		TCCR0 |=   (1<<CS01);                 // Prescaler = 1:64
		TCCR0 &=  ~(1<<CS00);
		TCNT0  =  0xFF;                       // Initial value
		while( (TIFR & (1<<TOV0)) == 0 );     // Wait until TIMER0 overflow
		TCCR0 = 0;                            // Stop counting
		TIFR |= (1<<TOV0);                    // Clear TOV0
		count++;
	}
}

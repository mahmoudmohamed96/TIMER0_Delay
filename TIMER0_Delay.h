/*
 * Timer0_delay.h
 *
 *  Created on: Apr 16, 2018
 *      Author: Mahmoud Mohamed Younis
 */

#ifndef TIMER0_DELAY_H_
#define TIMER0_DELAY_H_

/* To generate delay time using any timer:-
 * 1- choose prescaler using TCCRx register {CS00, CS01 and CS02} bits.
 * 2- get timer clock period = (1/F_CPU) * (1/prescaler factor).
 * 3- get number of clocks   = (time delay) / (timer clock period) then get initial value.
 * 4- wait untill TOVx to roll over time.
 * 5- stop counting.
 * 6- clear TOVx
 */

#include <avr/io.h>

void Timer0_delay_ms(unsigned int time);
void Timer0_delay_us(unsigned int time);

#endif /* TIMER0_DELAY_H_ */

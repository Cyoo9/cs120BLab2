/*	Author: tyoo002
 *  Partner(s) Name: Microcontroller [atmega1284]:
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB= 0x00;
    DDRC = 0xFF; PORTC = 0x00;

    unsigned char cntavail;

    while (1) {
	//PORTC = 0x00;
        cntavail = 0x04;

        if(PINA & 0x01) { cntavail--; }
        if(PINA & 0x02) { cntavail--; }
        if(PINA & 0x04) { cntavail--; }
        if(PINA & 0x08) { cntavail--; }

	
        if(cntavail == 0x00) { PORTC = 0x80; }
        else { PORTC = cntavail; }
    }
    return 0;
}


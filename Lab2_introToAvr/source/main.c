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
/*
int main(void) {
    
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0x00; PORTB= 0xFF;
    DDRC = 0x00; PORTC = 0xFF;
    DDRD = 0xFF; PORTD = 0x00;

    unsigned char maxWeight;
    unsigned char maxWeightDiff;
    //unsigned char finalWeight;

    while (1) {
	maxWeight = 0x8C; //1000 1100 represents 140kg 
	maxWeightDiff = 0x50; // 0101 0000 represents 80kg
	//finalWeight = 0x00;

	if(PINA + PINB + PINC > maxWeight) {
	    PORTD = 0x01; 
	}

	if((PINA - PINC) > maxWeightDiff || PINC - PINA > maxWeightDiff) {
	    PORTD = PORTD | 0x02;
	}
	
 	// mask the last 2 bits since it's reserved for above cases
	PORTD = PORTD | ((PINA + PINB + PINC) & 0xFC);  	
	
    }
    return 0;
} */

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


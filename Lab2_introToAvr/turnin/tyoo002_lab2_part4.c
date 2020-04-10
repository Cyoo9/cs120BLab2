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

    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0x00; PORTB= 0xFF;
    DDRC = 0x00; PORTC = 0xFF;
    DDRD = 0xFF; PORTD = 0x00;

    unsigned char maxWeight;
    unsigned char maxWeightDiff; 
    unsigned char tempD;

    while (1) {
	tempD = 0x00;	
        maxWeight = 0x8C; //140kg 
        maxWeightDiff = 0x50; //80kg

        if(PINA + PINB + PINC > maxWeight) {
            tempD = 0x01;
        }

        if(((PINA - PINC) > maxWeightDiff) || ((PINC - PINA) > maxWeightDiff)) {
            tempD = tempD | 0x02;
        }

        tempD = tempD | ((PINA + PINB + PINC) & 0xFC); //zero out PD1 and PD0 since they are reserved, then OR it with the reserved vals
	PORTD = tempD;
    }
    return 0;
}


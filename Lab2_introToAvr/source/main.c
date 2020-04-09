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
    DDRB = 0x00; PORTB= 0xFF;
    DDRC = 0x00; PORTC = 0xFF;
    DDRC = 0xFF; PORTD = 0x00; 

    unsigned char maxWeight;
    unsigned char maxWeightDiff;
    unsigned char weightDiff;

    while (1) {
	maxWeight = 0x8C; //1000 1100 represents 140kg 
	maxWeightDiff = 0x50; // 0101 0000 represents 80kg

	if(PINA > maxWeight || PINB > maxWeight || PINC > maxWeight) {
	    PORTD = 0x01; 
	}
	
	weightDiff = PINA - PINB;

	if(weightDiff > maxWeightDiff) {
	    PORTD = PORTD | 0x02;
	}
	
		
	
    }
    return 0;
}

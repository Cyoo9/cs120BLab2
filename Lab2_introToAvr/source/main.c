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
    DDRA = 0x00;
    PORTA = 0xFF;
    DDRB = 0xFF; 
    PORTB= 0x00;
    
    unsigned char tempB = 0x00; //LED light temp var
    unsigned char tempA = 0x00; //input 

    while (1) {
	tempA = PINA & 0x03;
	if(tempA == 0x01) {
		tempB = 0x01;
	}
    	PORTB = tempB;
    }
    return 0;
}

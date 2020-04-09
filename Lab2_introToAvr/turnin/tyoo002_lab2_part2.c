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
   
    //unsigned char tempB = 0x00; //LED light temp var
    //unsigned char tempA = 0x00; //input 

    while (1) {
	///tempA = PINA & 0x03;
	cntavail = 0x04;

	/*if(tempA == 0x01) {
		tempB = 0x01;
	}*/
	
	if(PINA & 0x01) { cntavail--; }
	if(PINA & 0x02) { cntavail--; }
	if(PINA & 0x04) { cntavail--; }
	if(PINA & 0x08) { cntavail--; }
	
	//if(cntavail == 0) { PORTC = PORTC | 0x8F; }

    	//PORTB = tempB; //LED port (ex 1)
	

	PORTC = cntavail; //available spaces (ex 2)
    }
    return 0;
}

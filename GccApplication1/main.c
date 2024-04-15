/*
 * GccApplication1.c
 *
 * Created: 4/14/2024 8:01:04 PM
 * Author : lukas-pc
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include "util/delay.h"
#include <avr/interrupt.h>

char QUARTER = 16;
char EIGHT = 8;
char SIXTEENTH = 4;

void custom_delay_ms(unsigned int ms) {
	unsigned int i;
	for (i = 0; i < ms; i++) {
		_delay_ms(1); // Use built-in delay function for 1 millisecond
	}
}

void playNote(float BPM,char noteDuration){
	
	float n = (60000.0 / BPM) / 16 * noteDuration; // Calculate total duration in milliseconds
	PORTD |= (1<<0);
	custom_delay_ms(n/2);
	PORTD &= ~(1<<0);
	custom_delay_ms(n/2);
	
	}
	
int main(void)
{
    while (1) 
    {
		DDRD = 0xFF;
		playNote(100,QUARTER); //dont use the sixteenth note it will break the realy
		playNote(100,QUARTER);
		playNote(100,QUARTER);
		playNote(100,QUARTER);
		
		playNote(100,EIGHT);
		playNote(100,EIGHT);
		playNote(100,EIGHT);
		playNote(100,EIGHT);
		playNote(100,EIGHT);
		playNote(100,EIGHT);
		playNote(100,EIGHT);
		playNote(100,EIGHT);
		
		}
		
		
		
}




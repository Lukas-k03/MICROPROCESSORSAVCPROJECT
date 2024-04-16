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

//hi paul the code rn only reflects the first c being played PORTD PIN1
// After you solder all the buttons and conncet them to the 8 realys
//youll have to modify this code so that the Shifted bit is given by what note it is C-C
// so like portD |= (1<<D) where D would be 1 cause its bit 1
//please im begging you dont break the realys, they are rated for 100,000 cycles

void custom_delay_ms(unsigned int ms) {
	unsigned int i;
	for (i = 0; i < ms; i++) {
		_delay_ms(1); // Use built-in delay function for 1 millisecond
	}
}

void playNote(float BPM,char noteDuration, char port){
	
	float n = (60000.0 / BPM) / 16 * noteDuration; // Calculate total duration in milliseconds
	PORTD |= (1<<port);
	custom_delay_ms(n/2);
	PORTD &= ~(1<<port);
	custom_delay_ms(n/2);
	
	}
	
int main(void)
{
    while (1) 
    {
		DDRD = 0xFF;
		playNote(100,QUARTER,0);
		playNote(100,QUARTER,1); //dont use the sixteenth note it will break the realy
		playNote(100,QUARTER,2);
		playNote(100,QUARTER,3);
		playNote(100,QUARTER,4);
		playNote(100,QUARTER,5); //dont use the sixteenth note it will break the realy
		playNote(100,QUARTER,6);
		playNote(100,QUARTER,7);
		
		}
		
		
		
}




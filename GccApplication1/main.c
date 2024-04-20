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

char QUARTER = 4;
char EIGHT = 2;
char SIXTEENTH = 1;

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



void shiftOutPORTD(char DATAP, char CLKP, char data){
		for (char i = 0; i < 8; i++) {
			// Output the current bit on the data pin
			if (data & (1 << (7 - i))) {
				PORTD |= (1 << DATAP);  // Set data pin high
				} else {
				PORTD &= ~(1 << DATAP); // Set data pin low
			}
			
			// Pulse the clock pin to shift the next bit
			PORTD |= (1 << CLKP);    // Set clock pin high
			PORTD &= ~(1 << CLKP);   // Set clock pin low
		}
	}
void shiftRegisterDisplay(char bar){
		//data pin SER (1<<0);
		//update clock latch SRCLK (1<<1);
		//Output pin RCLK (1<<2);
		
		PORTD &= ~(1 << 1); // CLKP low
		PORTD &= ~(1 << 2); // RCLK low
		
		PORTD &= ~(1<<2);
		shiftOutPORTD(0,1,bar);
		PORTD |= (1<<2);
		
	}
void playNote(float BPM,char noteDuration, char note){
	char shift;
	char octave;
	
	switch(note){
		case 0: shift = 0; octave = 0;
		case 1: shift = 1; octave = 0;
		case 2: shift = 2; octave = 0;
		case 3: shift = 3; octave = 0;
		case 4: shift = 4; octave = 0;
		case 5: shift = 5; octave = 0;
		case 6: shift = 6; octave = 0;
		case 7: shift = 7; octave = 0;
		case 8: shift = 0; octave = 1;
		case 9: shift = 1; octave = 1;
		case 10: shift = 2; octave = 1;
		case 11: shift = 3; octave = 1;
		case 12: shift = 4; octave = 1;
		case 13: shift = 5; octave = 1;
		case 14: shift = 6; octave = 1;
		case 15: shift = 7; octave = 1;
		case 16: shift = 0; octave = 2;
		case 17: shift = 1; octave = 2;
		case 18: shift = 2; octave = 2;
		case 19: shift = 3; octave = 2;
		case 20: shift = 4; octave = 2;
		case 21: shift = 5; octave = 2;
        case 22: shift = 6; octave = 2;
		case 23: shift = 7; octave = 2;
		case 24: shift = 0; octave = 3;
		case 25: shift = 1; octave = 3;
		case 26: shift = 2; octave = 3;
		case 27: shift = 3; octave = 3;
		case 28: shift = 4; octave = 3;
		case 29: shift = 5; octave = 3;
		case 30: shift = 6; octave = 3;
		case 31: shift = 7; octave = 3;
	
	}
	
	float n = ((60000.0 / BPM) / 4) * noteDuration; // Calculate total duration in milliseconds
	PORTD |= (1<<octave);
	shiftRegisterDisplay(1<<shift);
	custom_delay_ms(n/2); // hey dont remove the delay - spencer
	PORTD &=~(1<<octave);
	shiftRegisterDisplay(0);
	custom_delay_ms(n/2);
	}
int main(void)
{
    while (1) 
    {
		DDRD = 0xFF;
		//starts on E3 Goes until C6 each half step is one incrament 
		
		
		playNote(100,QUARTER,0);
		_delay_ms(1000);
		
		}
		
		//the problem is the SIPO is taking time to rese
		
}
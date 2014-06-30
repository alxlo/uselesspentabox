#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>
#include <stdlib.h>

#define ever (;;)



static void reset_hw(void) {

	DDRB = 0b00000100; //PB2=Output, others Input
	PORTB = 0x00;

}

int main(void) {

	reset_hw();

	//16 but fast PWM (mode 15) with OCR1A as TOP, 

	// prescaler clk/8 and TOP=10000 gives us a 100 Hz PWM signal
	// and a range of 1000...2000 for the 1-2ms control impulse that definines the servo position
	// This range povides a sufficient resolution and is very convenient to work with.

	OCR1A = 10000;                  // TOP = 10000 --> 100 Hz; --> 1000 steps = 1 ms

	TCCR1A = (1<<WGM10)|(1<<WGM11)  // FAST PWM (Mode 15)
			|(1<<COM1B1);           // OC1A disconnected, clear OC1B on compare match

    TCCR1B = (1<<WGM12)|(1<<WGM13)  // FAST PWM (Mode 15), Input capture not relevant
            |(1<<CS11);             // prescaler clk/8

    
    OCR1B = 1000;                   // nominal right position
    //OCR1B = 2000;                 // nominal left position


	for ever {

	}
	/* never  return 0; */
	return 0;
}

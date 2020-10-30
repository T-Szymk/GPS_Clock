/* Script to test using various timers on ATMegaX28p
 *
 */

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER0_COMPA_vect) {
	PORTD ^= (1 << 2); // for some reason this does not seem to flick the LED
}

ISR(TIMER0_COMPB_vect) {
	PORTD ^= (1 << 3);
}

ISR(TIMER1_OVF_vect) {
	PORTB ^= 1;
}

int main() {

	TCCR1A = 0x00;
	TCCR1B = 0x05; // 1:1024 prescaler
	TCCR1C = 0x00;
	TCNT1L  = 0x00;
	TCNT1H  = 0x00;
	OCR1AL  = 0x00;
	OCR1AH  = 0x00;
	OCR1BL  = 0x00;
	OCR1BH  = 0x00;

	TIFR1  = 0x00;
	TIMSK1 = 0x01;
	sei(); // set global interrupts
	DDRB = 0xFF;
	PORTB = 0x00;

	while(1) {}

	return 0;
}
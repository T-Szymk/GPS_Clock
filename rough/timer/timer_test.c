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

ISR(TIMER0_OVF_vet) {
	PORTB ^= (1 << 7);
}

int main() {

	TIMSK0 = 0x07;
	TCCR0A = 0x50;
	TCCR0B = 0x05;
	TCNT0  = 0x00;
	OCR0A  = 0x7F;
	OCR0B  = 0x7F;

	TIFR0  = 0x00;
	sei();
	DDRD = 0xFF;
	DDRB = 0xFF;
	PORTD = 0x00;
	PORTB = 0x00;

	while(1) {}

	return 0;
}
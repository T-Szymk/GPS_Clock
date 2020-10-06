/*
Script to test direct memory addressing of ports for atmegaxx8p MCUs
*/

#include <stdint.h>

int main(void) {

  volatile uint8_t* DDRB  = (volatile uint8_t*)(0x0024); 
  volatile uint8_t* PORTB = (volatile uint8_t*)(0x0025); 

  *DDRB  = 0x01; // sets memory address of DDRB; PORTB,Pin1 = output
  *PORTB = 0x01;

  uint32_t iter = 0;

  while(1) {

    for (iter = 40000; iter > 0; iter--) {
      // do nothing
    }

    *PORTB ^= 0x01; // toggle PORTB
  }

  return 0;
}
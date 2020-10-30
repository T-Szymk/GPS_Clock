/* Testing use of the AVR UART by creating a loopback. 
 * Polls status of Rx register, if not empty, copy to Tx
 * 
 * For async normal mode, 9600 BAUD, UBRR = (f_osc / 16 * 9600) - 1 ~ 6 (ceil val)
 * 
 * Frame format set by UCSZn2:0 (number of bits), UPM1:0 (parity), USBSn (stops bits) (UCSRnB)
 * 
 * Tx
 * ===
 * wait until UDREn is set (buffer is empty) and then write to UDRn
 * 
 * Rx
 * ===
 * wait until RXCn is clear and then read from UDRn
 */

#include <stdint.h>
#include <avr/io.h>
// #include "USART.h"

#define BAUD 9600
#define F_CPU 1000000
#define MYUBRR (F_CPU / (8 * BAUD)) - 1 // equation when using double speed

typedef uint8_t u8;

void uart_init(void) {
  // double speed, 9600 Baud
  UBRR0H = 0x00;
  UBRR0L = 0x0c;
  
  UCSR0B = (1 << RXEN0) | (1 << TXEN0); // tx/rx enable
  UCSR0C = (3 << UCSZ00); // 8-bit character size
  UCSR0A |= (1 << U2X0); // double speed
}

void tx_blocking(u8 data) {
  while ( !(UCSR0A & (1 << UDRE0)));
  UDR0 = data;
}

u8 rx_blocking(void) {
  while ( !(UCSR0A & (1 << RXC0)));
  return UDR0;
}

int main(void) {

  u8 data_val = 0;

  uart_init();

  while(1) {

    data_val = rx_blocking();

    tx_blocking(data_val); 
  }

  return 0;
}
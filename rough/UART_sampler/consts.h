
#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdint.h> 

#define BAUD 9600
#define F_CPU 1000000
#define MYUBRR (F_CPU / (8 * BAUD)) - 1

typedef uint8_t U8;
typedef uint16_t U6;
typedef uint32_t U32;

#endif

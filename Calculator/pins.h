#ifndef PINS_H_
#define PINS_H_
#include "tm4c123gh6pm.h"
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

///////////for port A

#define PA0 (*((volatile unsigned long *)(0x400043FC+0x0004)))
#define PA1 (*((volatile unsigned long *)(0x400043FC+0x0008)))
#define PA2 (*((volatile unsigned long *)(0x400043FC+0x0010)))
#define PA3 (*((volatile unsigned long *)(0x400043FC+0x0020)))
#define PA4 (*((volatile unsigned long *)(0x400043FC+0x0040)))
#define PA5 (*((volatile unsigned long *)(0x400043FC+0x0080)))
#define PA6 (*((volatile unsigned long *)(0x400043FC+0x0100)))
#define PA7 (*((volatile unsigned long *)(0x400043FC+0x0200)))	
	

///////////for port B

#define PB0 (*((volatile unsigned long *)(0x400053FC+0x0004)))
#define PB1 (*((volatile unsigned long *)(0x400053FC+0x0008)))
#define PB2 (*((volatile unsigned long *)(0x400053FC+0x0010)))
#define PB3 (*((volatile unsigned long *)(0x400053FC+0x0020)))
#define PB4 (*((volatile unsigned long *)(0x400053FC+0x0040)))
#define PB5 (*((volatile unsigned long *)(0x400053FC+0x0080)))
#define PB6 (*((volatile unsigned long *)(0x400053FC+0x0100)))
#define PB7 (*((volatile unsigned long *)(0x400053FC+0x0200)))	
	
///////////for port C

#define PC0 (*((volatile unsigned long *)(0x400063FC+0x0004)))
#define PC1 (*((volatile unsigned long *)(0x400063FC+0x0008)))
#define PC2 (*((volatile unsigned long *)(0x400063FC+0x0010)))
#define PC3 (*((volatile unsigned long *)(0x400063FC+0x0020)))
#define PC4 (*((volatile unsigned long *)(0x400063FC+0x0040)))
#define PC5 (*((volatile unsigned long *)(0x400063FC+0x0080)))
#define PC6 (*((volatile unsigned long *)(0x400063FC+0x0100)))
#define PC7 (*((volatile unsigned long *)(0x400063FC+0x0200)))	
	
///////////for port D

#define PD0 (*((volatile unsigned long *)(0x400073FC+0x0004)))
#define PD1 (*((volatile unsigned long *)(0x400073FC+0x0008)))
#define PD2 (*((volatile unsigned long *)(0x400073FC+0x0010)))
#define PD3 (*((volatile unsigned long *)(0x400073FC+0x0020)))
#define PD4 (*((volatile unsigned long *)(0x400073FC+0x0040)))
#define PD5 (*((volatile unsigned long *)(0x400073FC+0x0080)))
#define PD6 (*((volatile unsigned long *)(0x400073FC+0x0100)))
#define PD7 (*((volatile unsigned long *)(0x400073FC+0x0200)))	

///////////for port E

#define PE0 (*((volatile unsigned long *)(0x400243FC+0x0004)))
#define PE1 (*((volatile unsigned long *)(0x400243FC+0x0008)))
#define PE2 (*((volatile unsigned long *)(0x400243FC+0x0010)))
#define PE3 (*((volatile unsigned long *)(0x400243FC+0x0020)))
#define PE4 (*((volatile unsigned long *)(0x400243FC+0x0040)))
#define PE5 (*((volatile unsigned long *)(0x400243FC+0x0080)))
#define PE6 (*((volatile unsigned long *)(0x400243FC+0x0100)))
#define PE7 (*((volatile unsigned long *)(0x400243FC+0x0200)))	

///////////for port F

#define PF0 (*((volatile unsigned long *)(0x400253FC+0x0004)))
#define PF1 (*((volatile unsigned long *)(0x400253FC+0x0008)))
#define PF2 (*((volatile unsigned long *)(0x400253FC+0x0010)))
#define PF3 (*((volatile unsigned long *)(0x400253FC+0x0020)))
#define PF4 (*((volatile unsigned long *)(0x400253FC+0x0040)))
#define PF5 (*((volatile unsigned long *)(0x400253FC+0x0080)))
#define PF6 (*((volatile unsigned long *)(0x400253FC+0x0100)))
#define PF7 (*((volatile unsigned long *)(0x400253FC+0x0200)))	

#endif
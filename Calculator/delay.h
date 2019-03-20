#ifndef DELAY_H
#define DELAY_H
#include "types.h"
#include "tm4c123gh6pm.h"
#define bus_frequency 80000000
void delay_init(void);
void delay_us(u32 delay);
void delay_ms(u32 delay);
void delay_s (u32 delay);
void delay_min (u32 delay);
void delay_hr (u32 delay);
#endif
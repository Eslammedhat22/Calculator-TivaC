#include "delay.h"

void delay_init(void)
{
	NVIC_ST_CTRL_R=0;
	NVIC_ST_RELOAD_R=0x00FFFFFF;
	NVIC_ST_CURRENT_R=0;
	NVIC_ST_CTRL_R=0x5;
}
void wait(u32 delay)
{
	NVIC_ST_RELOAD_R=delay-1;
	NVIC_ST_CURRENT_R=0;
	while((NVIC_ST_CTRL_R&0x10000)==0){;}
}
void delay_us(u32 delay)
{
  u32 i;
	for(i=0;i<delay;i++)
		{
        wait((bus_frequency/1000000));	
		}
	
}
void delay_ms(u32 delay)
{
  u32 i;
	for(i=0;i<delay;i++)
		{
        wait((bus_frequency/1000));	
		}
	
}
void delay_s (u32 delay)
{
  u32 i;
	for(i=0;i<delay;i++)
		{
        wait(bus_frequency);	
		}
	
}
void delay_min (u32 delay)
{
  u32 i;
	for(i=0;i<delay;i++)
		{
        delay_s(60);	
		}
	
}
void delay_hr (u32 delay)
{
  u32 i;
	for(i=0;i<delay;i++)
		{
        delay_min(60);	
		}
}
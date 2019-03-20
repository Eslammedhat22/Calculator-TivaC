#include "gpio.h"

u8 internal_Configuration(u8 PortName, u32 Mask,u32 Mask1,u8 State)
{
	volatile u8 delay=0;
	switch (PortName)
	{
	case 'A':
	case 'a':
		
	
		SYSCTL_RCGC2_R|=0x01;
	  delay=1;
	  delay=2;
    GPIO_PORTA_AMSEL_R &= ~(Mask); 	
    GPIO_PORTA_PCTL_R  &=~(Mask1);
	  if(State) 
			{
				GPIO_PORTA_DIR_R |= (Mask);
				GPIO_PORTA_PUR_R |= (Mask);
			}
	  else GPIO_PORTA_DIR_R &= ~(Mask);
	  GPIO_PORTA_AFSEL_R &= ~(Mask);
		GPIO_PORTA_DEN_R |= (Mask);
    
			
		break;
	case 'B' :
	case 'b':
		
		SYSCTL_RCGC2_R|=0x02;
	  delay=1;
	  delay=2;
    GPIO_PORTB_AMSEL_R &= ~(Mask); 	
    GPIO_PORTB_PCTL_R  &=~(Mask1);
	  if(State) 
			{
				GPIO_PORTB_DIR_R |= (Mask);
				GPIO_PORTB_PUR_R |= (Mask);
			}
	  else GPIO_PORTB_DIR_R &= ~(Mask);
	  GPIO_PORTB_AFSEL_R &= ~(Mask);
		GPIO_PORTB_DEN_R |= (Mask);
    
		break;
	case 'C':
	case 'c':
		
	  SYSCTL_RCGC2_R|=0x04;
	  delay=1;
	  delay=2;
	  GPIO_PORTC_LOCK_R=0x4c4f434b;
	  GPIO_PORTC_CR_R |= (Mask);
    GPIO_PORTC_AMSEL_R &= ~(Mask); 	
    GPIO_PORTC_PCTL_R  &=~(Mask1);
	  if(State) 
			{
				GPIO_PORTC_DIR_R |= (Mask);
				GPIO_PORTC_PUR_R |= (Mask);
			}
	  else GPIO_PORTC_DIR_R &= ~(Mask);
	  GPIO_PORTC_AFSEL_R &= ~(Mask);
		GPIO_PORTC_DEN_R |= (Mask);
    
	
		break;
	case 'D':
	case 'd':

		SYSCTL_RCGC2_R|=0x08;
		delay=1;
		delay=2;
		GPIO_PORTD_LOCK_R=0x4c4f434b;
		GPIO_PORTD_CR_R |= (Mask);
		GPIO_PORTD_AMSEL_R &= ~(Mask); 	
		GPIO_PORTD_PCTL_R  &=~(Mask1);
		if(State) 
			{
				GPIO_PORTD_DIR_R |= (Mask);
				GPIO_PORTD_PUR_R |= (Mask);
			}
		else GPIO_PORTD_DIR_R &= ~(Mask);
		GPIO_PORTD_AFSEL_R &= ~(Mask);
		GPIO_PORTD_DEN_R |= (Mask);
	
	break;
  case 'E':
	case 'e':
		
	
    SYSCTL_RCGC2_R|=0x010;
	  delay=1;
	  delay=2;
	  GPIO_PORTE_AMSEL_R &= ~(Mask); 	
    GPIO_PORTE_PCTL_R  &=~(Mask1);
	  if(State) 
			{
				GPIO_PORTE_DIR_R |= (Mask);
				GPIO_PORTE_PUR_R |= (Mask);
			}
	  else GPIO_PORTE_DIR_R &= ~(Mask);
	  GPIO_PORTE_AFSEL_R &= ~(Mask);
		GPIO_PORTE_DEN_R |= (Mask);
    
	break;
	case 'F':
	case 'f':
		
    SYSCTL_RCGC2_R|=0x020;
	  delay=1;
	  delay=2;
	  GPIO_PORTF_LOCK_R=0x4c4f434b;
	  GPIO_PORTF_CR_R |= (Mask);
    GPIO_PORTF_AMSEL_R &= ~(Mask); 	
    GPIO_PORTF_PCTL_R  &=~(Mask1);
	  if(State) 
			{
				GPIO_PORTF_DIR_R |= (Mask);
				GPIO_PORTF_PUR_R |= (Mask);
			}
	  else GPIO_PORTF_DIR_R &= ~(Mask);
	  GPIO_PORTF_AFSEL_R &= ~(Mask);
		GPIO_PORTF_DEN_R |= (Mask);		
		break;
	default: return error; 
	}
	return success;
}







u8 GPIO_Digital_PinConfiguration(u8 PortName, u8 PinIndex,u8 State)
{
	if(PinIndex>=no_of_pins_on_port) return error;
	volatile u32 Mask=1<<PinIndex;
	volatile u32 Mask1=0xf<<(PinIndex*4);
	return internal_Configuration(PortName,Mask,Mask1,State);
}





u8 GPIO_Digital_PinsConfiguration(u8 PortName, u8 StartPinIndex,u8 EndPinIndex ,u8 State)
{
	if(StartPinIndex>=no_of_pins_on_port || EndPinIndex>=no_of_pins_on_port || EndPinIndex < StartPinIndex) return error;
	volatile u32 Mask=~0;
	volatile u32 Mask1=~0;
	Mask=(Mask<<StartPinIndex)&(Mask>>(31-EndPinIndex));
	Mask1=(Mask1<< (StartPinIndex*4) ) & ( Mask1 >>( 31-(EndPinIndex*4)));
	return internal_Configuration(PortName,Mask,Mask1,State);
	
}



u8 GPIO_Digital_PortConfiguration(u8 PortName,u8 State)
{
	
	return GPIO_Digital_PinsConfiguration(PortName,0,no_of_pins_on_port-1 ,State);
}


u8 internal_read(u8 PortName, u32 Mask,u32* OutputValue)
{
	switch (PortName)
	{
	case 'A':
	case 'a':
		  *OutputValue=GPIO_PORTA_DATA_R & Mask;
		break;
	case 'B' :
	case 'b':
		*OutputValue=GPIO_PORTB_DATA_R & Mask;
		break;
	case 'C':
	case 'c':
		*OutputValue=GPIO_PORTC_DATA_R & Mask;
		break;
	case 'D':
	case 'd':
    *OutputValue=GPIO_PORTD_DATA_R & Mask;
	  break;
  case 'E':
	case 'e':
		*OutputValue=GPIO_PORTE_DATA_R & Mask;
	  break;
	case 'F':
	case 'f':
		*OutputValue=GPIO_PORTF_DATA_R & Mask;
		break;
	default: return error; 
	}
	return success;
}

u8 GPIO_Digital_ReadPinVal(u8 PortName, u8 PinIndex,u32* OutputValue)
{
	if(PinIndex>=no_of_pins_on_port) return error;
	volatile u32 Mask=1<<PinIndex;
  u8 state=internal_read(PortName,Mask,OutputValue);
	*OutputValue>>=PinIndex;
	return state;
}
u8 GPIO_Digital_ReadPinsVal(u8 PortName, u8 StartPinIndex,u8 EndPinIndex ,u32* OutputValue)
{
	if(StartPinIndex>=no_of_pins_on_port || EndPinIndex>=no_of_pins_on_port || EndPinIndex < StartPinIndex) return error;
	volatile u32 Mask=~0;
	Mask=(Mask<<StartPinIndex)&(Mask>>(31-EndPinIndex));
	u8 state=internal_read(PortName,Mask,OutputValue);
	*OutputValue>>=StartPinIndex;
	return state;
	
}
u8 GPIO_Digital_ReadPortVal(u8 PortName ,u32* OutputValue)
{
	return GPIO_Digital_ReadPinsVal(PortName, 0,no_of_pins_on_port-1 ,OutputValue);
}

#ifndef GPIO_H_
#define GPIO_H_


#include "types.h"
#include "tm4c123gh6pm.h"
#define success  1
#define error 0
#define input 0
#define output 1
#define High 1
#define Low  0
#define no_of_pins_on_port  8

u8 GPIO_Digital_PinConfiguration(u8 PortName, u8 PinIndex,u8 State);

u8 GPIO_Digital_PinsConfiguration(u8 PortName, u8 StartPinIndex,u8 EndPinIndex ,u8 State);

u8 GPIO_Digital_PortConfiguration(u8 PortName,u8 State);

u8 GPIO_Digital_ReadPinVal(u8 PortName, u8 PinIndex,u32* OutputValue);

u8 GPIO_Digital_ReadPinsVal(u8 PortName, u8 StartPinIndex,u8 EndPinIndex ,u32* OutputValue);

u8 GPIO_Digital_ReadPortVal(u8 PortName ,u32* OutputValue);

u8 GPIO_Digital_WritePinVal(u8 PortName, u8 PinIndex,u32* InputValue);

u8 GPIO_Digital_WritePinsVal(u8 PortName, u8 StartPinIndex,u8 EndPinIndex ,u32* InputValue);


u8 GPIO_Digital_WritePortVal(u8 PortName ,u32* OutputValue);

#endif
#ifndef CALCULATIONS_H
#define CALCULATIONS_H
#include "types.h"
#include <string.h>
s8 GetOperatorWeight(u8 op);
u8 Isoperator(char a);
u8 InfixToPostfix(s8* infix,u8 size,s8* postfix);
#endif
#include "calculations.h"

// Function to get weight of an operator. An operator with higher weight will have higher precedence.
s8 GetOperatorWeight(u8 op)
{
	s8 weight = -1;
	switch(op)
	{
  case '+':
	case '-':
		{weight = 1;

		break;}
	case '*':
	case '/':
    case '%':
		{weight = 2;
		break;}
	case '^':
	case '\'':
		{weight = 3;
		break;}
	}
	return weight;
}

u8 Isoperator(char a)
{
	if(a=='+'||a=='-'||a=='*'||a=='/'||a=='%'||a=='^')return 1;
	else return 0;
}

u8 InfixToPostfix(s8* infix,u8 size,s8* postfix)
{
   s8 stack[100];
	 u8 stackcounter=0;
	 u8 counter=0;
   s8 i=0;
	 for(i=0;i<size;i++)
		{
			if(Isoperator(infix[i]))
				{
					if(stackcounter==0)
						{
							stack[stackcounter]=infix[i];
							stackcounter++;
						}
					else
						{
							if(GetOperatorWeight(stack[stackcounter-1]) < GetOperatorWeight(infix[i]) )
								{
									stack[stackcounter]=infix[i];
									stackcounter++;
								}
							else if (GetOperatorWeight(stack[stackcounter-1]) > GetOperatorWeight(infix[i]))
								{
									postfix[counter]=stack[stackcounter-1];
					        counter++;
									stackcounter--;
									i--;
								}
							else
								{
									if(infix[i]=='^')
										{
											stack[stackcounter]=infix[i];
									    stackcounter++;
										}
									else
										{
											postfix[counter]=stack[stackcounter-1];
											counter++;
											stackcounter--;
											i--;
										}
								}
								
						}
				}
				else 
				{
					postfix[counter]=infix[i];
					counter++;
				}
		}
  while(stackcounter!=0)
				{
					postfix[counter]=stack[stackcounter-1];
					counter++;
					stackcounter--;
				}
	 if(counter==size)return 1;
	 else return 0;
}
s8 Index(u8 varName, u8* varibleNames, u8 NVar)
{

	for (int i = 0; i < NVar; i++)
	{


		if (varName == varibleNames[i])
		{



			return i;
		}

	}
	return (-1);

}

f32 calculate(f32* variables, u8* names,u8 Vsize,s8* infix,u8 Ssize)
{
	s8 postfix[100];
	f32 result[100];
	u8 counter=0;
	InfixToPostfix(infix,Ssize,postfix);
	u8 i=0;
	for(i=0;i<Ssize;i++)
		{
			if(Isoperator(postfix[i]))
			{
				switch(postfix[i])
					{
					case '+':
						       result[counter-2]+=result[counter-1];
					         counter--;
					         break;
					case '-':
									 result[counter-2]-=result[counter-1];
					         counter--;
					         break;
					case '*':
									 result[counter-2]*=result[counter-1];
					         counter--;
					         break;
					case '/':
									 result[counter-2]/=result[counter-1];
					         counter--;
					         break;	
					}
			}
			else
      {
				result[counter]=variables[Index(postfix[i],names, Vsize)];
				counter++;
			}
		}
		return result[0];
}
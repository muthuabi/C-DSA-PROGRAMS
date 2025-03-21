#include <stdio.h>
#include <stdlib.h>
#include "mystrlen.c"
#include "StackStruct.c"
int postFixEval(char *expr,int len)
{
	stack *s; // with character array
	int v1,v2,i;
	s=initStack(len);
	//expr=(char*)realloc(expr,len);
	for(i=0;expr[i];i++)
	{
		switch(expr[i])
		{
			case '+':
				v1=pop(s)-'0';
				v2=pop(s)-'0';
				push(s,(v1+v2)+'0');
				break;
			case '-':
				v1=pop(s)-'0';
				v2=pop(s)-'0';
				push(s,(v1-v2)+'0');
				break;
			case '*':
				v1=pop(s)-'0';
				v2=pop(s)-'0';
				push(s,(v1*v2)+'0');
				break;
			case '/':
				v1=pop(s)-'0';
				v2=pop(s)-'0';
				if(v2==0)
				{
					printf("Infinity Expression\n");
					return 0;
				}
				push(s,(v1/v2)+'0');
				break;
			default:
				push(s,expr[i]);
		}
	}
	i=pop(s)-'0';
	printf("Result is %d",i);
	return i;
}

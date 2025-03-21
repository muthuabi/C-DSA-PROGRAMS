#include <stdio.h>
#include <stdlib.h>
#include "mystrlen.c"
#include "StackStruct.c"
int main()
{
	stack *s; // with character array
	int len,v1,v2,i;
	char *expr=(char*)malloc(1024);
	printf("Enter the Postfix Notation:\n");
	scanf("%s",expr);
	len=mylen(expr);
	s=initStack(len);
	expr=(char*)realloc(expr,len);
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
	printf("Result is %d",pop(s)-'0');
	return 0;
}

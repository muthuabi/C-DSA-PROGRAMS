#include <stdio.h>
#include <stdlib.h>
#include "mystrlen.c"
#include "StackStructInt.c"
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
//	printf("Length is %d",len);
	for(i=0;expr[i];i++)
	{
		switch(expr[i])
		{
			case '+':
				v1=pop(s);
				v2=pop(s);
//				printf("\nV1 is %d\n",v1);
//				printf("\nV2 is %d\n",v2);
				push(s,v1+v2);
				break;
			case '-':
				v1=pop(s);
				v2=pop(s);
				push(s,v1-v2);
				break;
			case '*':
				v1=pop(s);
				v2=pop(s);
				push(s,v1*v2);
				break;
			case '/':
				v1=pop(s);
				v2=pop(s);
				if(v2==0)
				{
					printf("Infinity Expression\n");
					exit(0);
				}
				push(s,v1/v2);
				break;
			default:
//				printf("\nElement pushing %c %d\n",expr[i],expr[i]);
				push(s,expr[i]-'0');
		}
	}
	printf("Result is %d",pop(s));
	return 0;
}

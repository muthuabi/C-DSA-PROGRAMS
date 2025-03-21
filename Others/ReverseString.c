#include<stdio.h>
#include<stdlib.h>
#include "mystrlen.c"
#include "StackStruct.c"
int main()
{
	stack *s;
	char c;
	int len,i=0;
	char* str=(char*)malloc(1024);
	printf("Enter the String:\n");
	scanf("%[^\n]s",str);
	len=mylen(str);
	str=(char*)realloc(str,len);
    s=initStack(len);
	while(i<len)
		push(s,str[i++]);
	printf("After Reversing:\n");
	while(c=pop(s))
		printf("%c",c);
		
	return 0;
}

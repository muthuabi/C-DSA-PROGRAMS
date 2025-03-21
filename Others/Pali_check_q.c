#include <stdio.h>
#include <stdlib.h>
#include "mystrlen.c"
#include "Queue_Traditional.c"
int isPaliQ(char *c,int len)
{
	queue *q=initQueue(len);
	int i=0;
	while(i<len)
	{
		enQueue(q,c[i]);
		i++;
	}
	while(q->front<=q->rear) // OR q->front<q->rear
	{
		if(q->arr[q->front++]!=q->arr[--q->rear])
			return 0;
		//printf(" front %c rear %c\n",q->arr[q->front++],q->arr[--q->rear]);
	}
	return 1;
}
int main()
{
	int len;
	char *c=(char *)malloc(1024);
	printf("Enter the String:");
	scanf("%s",c);
	len=mylen(c);
	c=(char*)realloc(c,len);
	printf("%s is %s",c,isPaliQ(c,len)?"PALINDROME":"NOT PALINDROME");
	return 0;
	
}

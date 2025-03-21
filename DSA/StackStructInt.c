#include<stdio.h>
#include<stdlib.h>
typedef struct Stack
{
	int top;
	unsigned int n;
	int *arr;
}stack;
stack* initStack(int n)
{
	//stack *s=(stack*)calloc(n,sizeof(stack));
	stack *s=(stack*)malloc(n*sizeof(stack));
	s->n=n;
	s->top=-1;
	s->arr=(int*)calloc(n,sizeof(int));
	return s;
}
int isFull(stack *s)
{
	return s->top==s->n-1;
}
int isEmpty(stack *s)
{
	return s->top<=-1;
}
int push(stack *s,int x)
{
	if(isFull(s))
	{
		//printf("\nStack Overflow\n");
		return 0;
	}
	else
	{
		s->arr[++s->top]=x;
		//printf("\nElement %c pushed in the Stack\n",x);
		return 1;
	}
}
int pop(stack *s)
{
	if(isEmpty(s))
	{	
		return 0;
	}
	return s->arr[s->top--];
}
int peek(stack *s)
{
	if(isEmpty(s))
	{	
		printf("\nStack Underflow\n");
		return 0;
	}
	return s->arr[s->top-1];
}
void printStack(stack *s,int rev)
{
	int i;
	printf("\nStack Elements\n");
	if(isEmpty(s))
		printf("\nStack is Empty\n");
	else
	{
		if(rev==0)
			for(i=0;i<=s->top;i++)
				printf("%d\n",s->arr[i]);
		else
			for(i=(s->top);i>=0;i--)
				printf("%d\n",s->arr[i]);	
	}
}
	

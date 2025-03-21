//COMPLETE INFIX TO POSTFIX CONVERSION + EVALUATION OF POSTFIX USING STACK
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int mylen(char* s)
{
	int i=0;
	while(s[i]!='\0')
		i++;
	return i;
}
typedef struct Stack
{
	int top;
	unsigned int n;
	char *arr;
}stack;
stack* initStack(int n)
{
	//stack *s=(stack*)calloc(n,sizeof(stack));
	stack *s=(stack*)malloc(n*sizeof(stack));
	s->n=n;
	s->top=-1;
	s->arr=(char*)calloc(n,sizeof(char));
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
int push(stack *s,char x)
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
char pop(stack *s)
{
	if(isEmpty(s))
	{	
		return '\0';
	}
	return s->arr[s->top--];
}
int peek(stack *s)
{
	if(isEmpty(s))
	{	
		//printf("\nStack Underflow\n");
		return 0;
	}
	return s->arr[s->top];
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
				printf("%c\n",s->arr[i]);
		else
			for(i=(s->top);i>=0;i--)
				printf("%c\n",s->arr[i]);	
	}
}
int priority(char c)
{
	switch(c)
	{
		
		case '^':
			return 3;
		case '*':
		case '/':
			return 2;
		case '+':
		case '-':
			return 1;
		default:
			return 0;
	}
}
char* infixToPostfix(char *arr,int len,int *p_len)
{
	int i,j=0;
	stack *s=initStack(len);
	char *postfix=(char*)malloc(len);
	for(i=0;i<len;i++)
	{
		//printf("%d th Iteration Element %c\n",i,arr[i]);
		switch(arr[i])
		{
			case '^':
			case '+':
			case '-':
			case '*':
			case '/':
			case '(':
				if(isEmpty(s) || arr[i]=='(')
					//printf("%d th iteration %c\n",i,arr[i]);
					push(s,arr[i]);
					//printStack(s,0);
					//peek(s) is equals to arr[s->top]
				else
				{
					//printf("%dth %c (%d) <= %c (%d)\n",i,arr[i],priority(arr[i]),peek(s),priority(peek(s)));
					while(priority(arr[i])<=priority(peek(s)))
						postfix[j++]=pop(s);
					push(s,arr[i]);
				}
				break;
			case ')':
				while(peek(s)!='(')
					postfix[j++]=pop(s);
				pop(s);
				break;
			default:
				postfix[j++]=arr[i];
				
		}
	}
	//printStack(s,0);
	while(!isEmpty(s))
		postfix[j++]=pop(s);
//	for(i=0;i<j;i++)
//		printf("%c ",postfix[i]);
	*p_len=j;
	return postfix;
}
int postFixEval(char *expr,int len)
{
	// We have to Either -'0' or -48 to change character to integer equivalent
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
			case '^':
				v1=pop(s)-'0';
				v2=pop(s)-'0';
				push(s,((int)pow(v2,v1))+'0');
				break;
			default:
				push(s,expr[i]);
		}
	}
	i=pop(s)-'0'; //i=pop(s)-48;
	//printf("Result is %d",i);
	return i;
}
int main()
{
	char *arr=(char*)malloc(1024),*postfix;
	int len,i,j=0,result,p_len;
	printf("Enter the Valid Expression:\n");
	scanf("%s",arr);
	len=mylen(arr);
	arr=(char*)realloc(arr,len);
	postfix=infixToPostfix(arr,len,&p_len);
	printf("INFIX: %s\nPOSTFIX: %s",arr,postfix);
	result=postFixEval(postfix,p_len);
	printf("\nThe Result is %d",result);
	return 0;
}

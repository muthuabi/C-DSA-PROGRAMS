#include<stdio.h>
#include<stdlib.h>
int mylen(char* s)
{
	int i=0;
	while(s[i]!='\0')
		i++;
	return i;
}
typedef struct Node 
{
	char data;
	struct Node* next;	
}node;

node* initNode(char c)
{
	node* n=(node*)malloc(sizeof(node));
	n->data=c;
	n->next=NULL;
	return n;
}
void insertBegin(node **head,char c)
{
	node *n=initNode(c);
	if(*head)
		n->next=*head;
	*head=n;
		
}
char deleteBegin(node **head)
{
	if(*head)
	{
		node *ptr=*head;
		*head=(*head)->next;
		return ptr->data;
	}
	return '\0';
}
void display(node *head)
{
	node *ptr=head;
	while(ptr)
	{
		printf("%c\t",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

typedef struct Stack
{
	node *top;
}stack;

int isEmpty(stack *s)
{
	return s->top==NULL;
}
stack* initStack()
{
	stack *s=(stack*)malloc(sizeof(stack));
	s->top=NULL;
	return s;
}
void push(stack *s,char x)
{
	insertBegin(&s->top,x);
}

char pop(stack *s)
{
	if(isEmpty(s))
		return '\0';
	return deleteBegin(&s->top);
}
char peek(stack *s)
{
	if(isEmpty(s))
		return '\0';
	return s->top->data;
}
void displayStack(stack *s)
{
	display(s->top);
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
char* infixToPostfix(char *expr,int len,int *post_len)
{
	int i,j=0;
	stack *s=initStack();
	char *post=(char*)malloc(sizeof(len));
	for(i=0;i<len;i++)
	{
		switch(expr[i])
		{
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
			case '(':
				if(isEmpty(s) || expr[i]=='(')
					push(s,expr[i]);
				else
				{
					while(priority(expr[i])<=priority(peek(s)))
						post[j++]=pop(s);
					push(s,expr[i]);
				}
				break;
			case ')':
				while(peek(s)!='(')
					post[j++]=pop(s);
				pop(s);
				break;
			default:
				post[j++]=expr[i];
				
		}
	}
	while(!isEmpty(s))
		post[j++]=pop(s);
	*post_len=j;
	return post;
}
char* reverseArrayStack(char *arr,int len)
{
	int i;
	stack *s=initStack();
	for(i=0;i<len;i++)
	{
		if(arr[i]=='(')
			push(s,')');
		else if(arr[i]==')')
			push(s,'(');
		else
			push(s,arr[i]);
	}
	i=0;
	while(!isEmpty(s))
		arr[i++]=pop(s);
	return arr;
}
int main()
{
	char *expr=(char*)malloc(sizeof(1024)),*post,*pre;
	int i,j,len,post_len,pre_len;
//	stack *s=initStack();
//	push(s,'+');
//	push(s,'a');
//	pop(s);
//	displayStack(s);
	printf("Enter the Expression:");
	scanf("%s",expr);
	len=mylen(expr);
	expr=(char*)realloc(expr,len);
//	post=infixToPostfix(expr,len,&post_len);  //It is Postfix
// 	printf("%s",post);
	expr=reverseArrayStack(expr,len);
	printf("%s",expr);
	pre=infixToPostfix(expr,len,&pre_len);
	pre=reverseArrayStack(pre,pre_len);
	printf("\n");
	printf("%s",pre);
	return 0;
	
}
// NO NEEDED LOOP AS WE CAN PRINT USING %S
//	for(i=0;i<post_len;i++)
//		printf("%c",post[i]);
//	printf("\n");


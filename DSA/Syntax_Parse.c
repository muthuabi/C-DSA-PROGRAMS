#include <stdio.h>
#include <stdlib.h>
int mylen(char* s)
{
	int i=0;
	while(s[i]!='\0')
		i++;
	return i;
}
typedef struct Node {
    int data;
    struct Node *next;
} node;

node* initNode(char data) {
    node *n = (node*)malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}
int insertNodeAtBegin(node **head, char data) {
    node *n = initNode(data);
    n->next = *head;
    *head = n; 
    return 1;
}
char deleteNodeAtBegin(node **head)
{
	if(*head)
	{
		node *t=*head;
		*head=(*head)->next;
		return t->data;
	}
	return '\0';
}
typedef struct Stack
{
	node *top;
}stack;
int isEmpty(stack *s)
{
	return s->top==NULL;
}
int push(stack *s,char v)
{
	node *n=initNode(v);
	if(insertNodeAtBegin(&s->top,v))
			return 1;
	return 1;
}
char pop(stack *s)
{
	if(isEmpty(s))
	{
		return '\0';
	}
	return deleteNodeAtBegin(&s->top);
}
int main()
{
	stack *s=(stack*)malloc(sizeof(stack));
	char *arr=(char*)malloc(1024);
	int len,i,j;
	s->top=NULL;
	printf("Enter the Expression:");
	scanf("%s",arr);
	len=mylen(arr);
	int flag=1;
	for(i=0;i<len;i++)
	{
		switch(arr[i])
		{
			case '{':
			case '(':
			case '[':
				push(s,arr[i]);
				break;
			case '}':
				if(pop(s)!='{')
					flag=0;
				break;
			case ']':
				if(pop(s)!='[')
					flag=0;
				break;
			case ')':
				if(pop(s)!='(')
					flag=0;
		}
	}
	if(!isEmpty(s))
		flag=0;
	if(flag)
		printf("Valid");
	else
		printf("INVALID");
	return 0;
}

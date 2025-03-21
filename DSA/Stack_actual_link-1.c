#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
} node;
node* initNode(int data) {
    node *n = (node*)malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}
int insertNodeAtBegin(node **head, int data) {
	
    node *n = initNode(data);
    n->next = *head;
    *head = n; 
    return 1;
}
int deleteNodeAtBegin(node **head)
{
	if(*head)
	{
		node *t=*head;
		*head=(*head)->next;
		return t->data;
	}
	return 0;
}
void display(node *head) {
    node *ptr = head;
    int i=0;
    while (ptr) {
    	printf("%d\t",ptr->data);
    	i++;
        ptr = ptr->next;
    }
}
typedef struct Stack
{
	node *top;
}stack;
int isEmpty(stack *s)
{
	return s->top==NULL;
}
int push(stack *s,int v)
{
	node *n=initNode(v);
	if(insertNodeAtBegin(&s->top,v))
		printf("Element %d Inserted into the Stack\n",v);
	return 1;
}
int pop(stack *s)
{
	if(isEmpty(s))
	{
		printf("Stack is Empty");
		return 0;
	}
	return deleteNodeAtBegin(&s->top);
}
int main()
{
	stack *s=(stack*)malloc(sizeof(stack));
	int n,i,x;
	s->top=NULL;
	printf("Enter the no of elements to push:");
	scanf("%d",&n);
	printf("Enter the Elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		push(s,x);
	}
	printf("\nStack Elements are:\n\n");
	display(s->top);
	printf("\n");
	printf("Enter the no of elements to pop:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		printf("\nPopped element is %d\n",pop(s));
	printf("\nStack Elements are:\n\n");
	display(s->top);
	return 0;	
}

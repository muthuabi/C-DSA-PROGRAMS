#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node *next;
}node;
node *head=NULL;

node* initNode(int data)
{
	node *n=(node*)malloc(sizeof(node));
	n->data=data;
	n->next=NULL;
	return n;

}
void insertNodeAtBegin(int data)
{
	node *n=initNode(data);
	if(head==NULL)
	{
		head=n;
		n->next=head;
		return;
	}
	n->next=head;
	head=n;
}
void display()
{
	node *ptr=head;
	// printf("head %d \n",head->data);
	int count=0;
	while(ptr->next!=head)
	{
		printf("%d\t",ptr->data);
		// printf("%d",ptr->next->data);
		printf("%p %p %p\n",ptr->next,head,head->next);
		ptr=ptr->next;
		if(count>10)
			break;
			count++;
	}
	printf("\n");
}
int main()
{
	 insertNodeAtBegin(5);
	 insertNodeAtBegin(9);
	 insertNodeAtBegin(7);
	 insertNodeAtBegin(10);
	 display();

}

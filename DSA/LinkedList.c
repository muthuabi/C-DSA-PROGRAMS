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
	n->next=head;
	head=n;
}
void insertNodeAtEnd(int data)
{
	node *n=initNode(data);
	node *ptr=head;
	//printf("head %d head next %d \t",head->data,head->next->data);
	if(head)
	{
		while(ptr->next)
		{
		//printf("%d \t \t",ptr->data);
			ptr=ptr->next;
		}
		ptr->next=n;
		n->next=NULL;
	}
	else
	{
		n->next=NULL;
		head=n;
	}
}
void insertNodeAtSpec(int target,int data)
{
	node *n=initNode(data);
	node *t,*ptr=head;
	if(head)
	{
		while(ptr)
		{
		//printf("%d \t \t",ptr->data);
			if(ptr->data==target)
			{
				
				t=ptr->next;
				ptr->next=n;
				n->next=t;
				break;
			}
			ptr=ptr->next;
		}
	
	}
	else
	{
		n->next=NULL;
		head=n;
	}
}
void deleteNodeAtBegin()
{
	if(head)
		head=head->next;
}
void deleteNodeAtEnd()
{
	if(head)
	{
		node *pr,*cur;
		pr=cur=head;
		while(cur->next)
		{
			pr=cur;
			cur=cur->next;
		}
		//pr->next=cur->next;
		pr->next=NULL;

	}
}
void deleteNodeAtSpec(int target)
{
	if(head)
	{
		node *pr,*cur;
		pr=cur=head;
		while(cur->next)
		{
			if(cur->data==target && pr==cur)
			{
				deleteNodeAtBegin();
				break;
			}
			else if(cur->data==target)
			{
				pr->next=cur->next;
				break;
			}
			pr=cur;
			cur=cur->next;
		}
	}

}
void display()
{
	node *ptr=head;
	// printf("head %d \n",head->data);
	while(ptr)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}
int main()
{
	 insertNodeAtBegin(5);
	 insertNodeAtBegin(9);
	
	 insertNodeAtEnd(11);
	 insertNodeAtEnd(10);
	 display();
	 insertNodeAtBegin(18);
	 insertNodeAtBegin(7);
	 insertNodeAtSpec(9,4);
	 display();
	 deleteNodeAtBegin();
	 deleteNodeAtEnd();
	 deleteNodeAtSpec(99);

	 display();
	 printf("\n");
	return 0;
}
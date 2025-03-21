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
int insertNodeAtEnd(node **head, int data) {
    node *n = initNode(data);
    if (*head == NULL) {
        *head = n;  
    }
	 else
	  {
        node *ptr = *head;
        while (ptr->next) 
            ptr = ptr->next;
        ptr->next = n; 
        *head=n;
    }
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
typedef struct Queue
{
	node *front;
	node *rear;
}queue;
int isEmpty(queue *q)
{
	return q->front==q->rear;
}
void enQueue(queue *q,int v)
{
	node *n=initNode(v);
	insertNodeAtEnd(&q->rear,v);
	if(q->front==NULL)
	{
		q->front=q->rear;
	}	
}
void deQueue(queue *q)
{
	if(q->front!=NULL)
	 deleteNodeAtBegin(&q->front);
	else
	printf("QUEUE IS EMPTY");
}
void qDisplay(queue *q)
{
	node *ptr=q->front;
	while(ptr!=NULL)
	{
		printf("%d \t",ptr->data);
		ptr=ptr->next;
	}
}
int main()
{
	queue *q=(queue*)malloc(sizeof(q));
	int i,n,x;
	q->front=NULL;
	q->rear=NULL;
	printf("Enter the no of elements to enQueue:");
	scanf("%d",&n);
	printf("Enter the Elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		enQueue(q,x);
	}
	printf("\nQueue Elements are:\n");
	qDisplay(q);
	printf("\nEnter the no of elements to deQueue:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		deQueue(q);
	printf("\nQueue Elements are:\n");
	qDisplay(q);
	return 0;
}

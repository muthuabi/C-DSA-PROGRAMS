#include<stdio.h>
#include<stdlib.h>
typedef struct Queue
{
	int front,rear,n;
	char *arr;	
}queue; 
queue* initQueue(int n)
{
	queue* q=(queue*)malloc(sizeof(queue));
	q->front=0;
	q->rear=0;
	q->n=n;
	q->arr=(char*)calloc(n,sizeof(char));
	return q;
}
int isEmpty(queue *q)
{
	return (q->front>=q->rear);
}
int isFull(queue *q)
{
	return q->rear==(q->n);
}
int enQueue(queue* q,char x)
{
	if(isFull(q))
	{
 		printf("\nQueue IS FULL\n");	
		return 0;
	}
	else
	{
		q->arr[q->rear++]=x;
//		printf("\nElement %d is Enqued\n",x);
		return 1;
	}
	
}
int deQueue(queue* q)
{
	int i;
	if(isEmpty(q))
	{
        printf("\nQueue is Empty On Dequeue");
		return 0;
	}
	else
	{
		q->arr[q->front++];
//		for(i=0;i<q->rear;i++)
//		{
//			
//			q->arr[i]=q->arr[i+1];
//		}
//		q->rear--;
		return 1;
	}
}
void display(queue* q)
{
	int i;
	if(isEmpty(q))
		printf("\nQueue is Empty");
	else
	{
		printf("\nQueue Elements\n");
		for(i=q->front;i<q->rear;i++)
			printf("%c\t",q->arr[i]);
	}
}
int main()
{
	queue *q=initQueue(5);
	enQueue(q,'5');
	enQueue(q,'5');
	enQueue(q,'5');
//	enQueue(q,'5');
//	enQueue(q,'5');
	//enQueue(q,'5');
	deQueue(q);
	deQueue(q);
	deQueue(q);
		enQueue(q,'5');
	enQueue(q,'5');
	display(q);
}

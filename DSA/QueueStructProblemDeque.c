#include<stdio.h>
#include<stdlib.h>
typedef struct Queue
{
	int front,rear,n;
	int *arr;	
}queue; 
queue* initQueue(int n)
{
	queue* q=(queue*)malloc(sizeof(queue));
	q->front=0;
	q->rear=0;
	q->n=n;
	q->arr=(int*)calloc(n,sizeof(int));
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
int enQueue(queue* q,int x)
{
	if(isFull(q))
	{
		printf("\nQueue IS FULL\n");	
		return 0;
	}
	else
	{
		q->arr[q->rear++]=x;
		printf("\nElement %d is Enqued\n",x);
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
		printf("\nElement %d is Dequed\n",q->arr[q->front++]);
		for(i=0;i<(q->rear-1);i++)
		{
			
			q->arr[i]=q->arr[i+1];
			printf("\n i %d i+1 %d\n",q->arr[i],q->arr[i+1]);
		}
		q->rear--;
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
			printf("%d\t",q->arr[i]);
	}
}
int main()
{
	queue *q;
	int n;
	int ch,c,no,i,x;
						printf("Enter the Capacity:");
					scanf("%d",&n);
					q=initQueue(n);
					if(q)
						printf("\nInitialized\n");

//	do 
//	{
//		printf("\n--------MENU----------\n");
//		printf("\n0. Init\n1. Print Queue \n2. EnQueue\n3. DeQueue\n5. Exit\n");
//		printf("\nEnter your choice:");
//		scanf("%d",&ch);
//		switch(ch)
//		{
//			case 0:
//					printf("Enter the Capacity:");
//					scanf("%d",&n);
//					q=initQueue(n);
//					if(q)
//						printf("\nInitialized\n");
//					break;
//			case 1:
//				display(q);
//				break;
//			case 2:
//				printf("\nEnter the number of elements to Enqueue:\n");
//				scanf("%d",&no);
//				printf("\nEnter the Elements:\n");
//				for(i=0;i<no;i++)
//				{
//					scanf("%d",&x);
//					if(!enQueue(q,x))
//						break;	
//				}
//				break;
//			case 3:
//				printf("\nEnter the number of elements to pop:\n");
//				scanf("%d",&no);
//				for(i=0;i<no;i++)
//				{
//				 	if(!deQueue(q))
//				 		break;
//				}
//				break;
//			case 5:
//				printf("\nExit\n");
//				break;
//			default:
//				printf("\n INVALID CHOICE \n");
//			    	
//		}
//		getchar();
//		getchar();	
//	}while(ch!=5);
	enQueue(q,1);
	enQueue(q,2);
	enQueue(q,3);
//	enQueue(q,4);	
//	enQueue(q,5);
//	enQueue(q,6);
	display(q);
	printf("\nFront %d and rear %d \n",q->front,q->rear);
	deQueue(q);
		printf("\nFront %d and rear %d \n",q->front,q->rear);
	deQueue(q);
	deQueue(q);
//	deQueue(q);
//	deQueue(q);
//	display(q);
	printf("\nFront %d and rear %d \n",q->front,q->rear);
	enQueue(q,6);
	printf("\nFront %d and rear %d \n",q->front,q->rear);
    display(q);
	return 0;
}

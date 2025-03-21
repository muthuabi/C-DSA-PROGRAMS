#include<stdio.h>
#include<stdlib.h>
typedef struct Heap
{
	int size;
	int *data;
}heap;

heap* initHeap(int n)
{
	heap *h=(heap*)malloc(sizeof(heap));
	h->data=(int*)calloc(n,sizeof(int));
	h->size=0;
}
int max(int x,int y)
{
	return (x>y?x:y);
}
void swap(int *arr,int i,int j)
{
	int t=arr[i];
	arr[i]=arr[j];
	arr[j]=t;
}
void heapify(heap *h,int i)
{
	int p;
	if(i==0)
		return;
	p=(i-1)/2;
	if(h->data[i]>h->data[p])
		swap(h->data,i,p);
	heapify(h,i-1);
}

void deleteheapify(heap *h,int i)
{
	if(i>=h->size)
		return;
	if((2*i+1)<h->size)
	{
		if(h->data[2*i+1]>h->data[i])
			swap(h->data,2*i+1,i);
		deleteheapify(h,2*i+1);
	}
	if((2*i+2)<h->size)
	{
		if(h->data[2*i+2]>h->data[i])
			swap(h->data,2*i+2,i);
		deleteheapify(h,2*i+2);
	}

}
void display(heap *h)
{
	int i,j=2,k;
	for(i=0;i<h->size;i++)
	{
		for(k=i;k<(h->size+1)/2;k++)
			printf(" ");
		printf("%d ",h->data[i]);
		if(i==(j-2))
		{
			printf("\n\n");
			j=j*2;
		}
	}
}
void insertHeap(heap *h,int x)
{
	h->data[h->size++]=x;
	heapify(h,h->size-1);
}
int deleteHeap(heap *h)
{
	int t=h->data[0];
	h->data[0]=h->data[--h->size];
	deleteheapify(h,0);
	return t;
}

int main()
{
	int n=100;
	heap *h=initHeap(n); //MAX HEAP
	insertHeap(h,400);
	insertHeap(h,300);
	insertHeap(h,600);
	insertHeap(h,10);
	insertHeap(h,20);
	insertHeap(h,30);
	deleteHeap(h);
	deleteHeap(h);
	deleteHeap(h);
	deleteHeap(h);
	display(h);
	return 0;
}

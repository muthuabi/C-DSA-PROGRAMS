#include<stdio.h>
void swap(int *a,int *b)
{
   int t;
   t=*a;
   *a=*b;
   *b=t;
}
int main()
{
	int a,b,*t;
	printf("Enter a and b:\n");
	scanf("%d",&a);
	scanf("%d",&b);
	printf("Before Swap:\n a:%d b:%d\n",a,b);
	printf("Address of a:%p\n",&a);
	printf("Address of b:%p\n\n",&b);
	swap(&a,&b);
	printf("After Swap:\n a:%d b:%d\n",a,b);
	printf("Address of a:%p\n",&a);
	printf("Address of b:%p\n\n",&b);
	return 0;
}
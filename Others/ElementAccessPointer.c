#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *a,i,n,target;
	printf("Enter the Size of Array:\n");
	scanf("%d",&n);
	a=calloc(n,sizeof(int));
	printf("Enter the Elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nArray Elements:\n\n");
	while(*a)
	{
		printf("%d\t",*a);
		a++;
	}
	a=(a-n);
	printf("\nEnter the Target Index:");
	scanf("%d",&target);
	if(target>=n)
		printf("\nYou have given Index out of Element count so you don't get what you want\n");
	printf("\nThe target element is %d\n",*(a+target));
	return 0;



}
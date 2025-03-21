#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *a,i,n;
	printf("Enter the Size of Array:\n");
	scanf("%d",&n);
	a=calloc(n,sizeof(int));
	printf("Enter the Elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nArray Elements Iterated using Pointers:\n");
	while(*a)
	{
		printf("%d\t",*a);
		a++;
	}
	printf("\n");
	return 0;
}
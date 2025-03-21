#include "ListManip.c"
int main() //All Combinations
{
	int *a,n,t,i,j;
	a=initList(&n);
	printf("Enter the Target:");
	scanf("%d",&t);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if((a[i]+a[j])==t)
			{
				printf("%d + %d = %d\n",a[i],a[j],t);
			}
		}

	}
	return 0;
}

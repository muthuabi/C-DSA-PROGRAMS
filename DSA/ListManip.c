#include<stdio.h>
#include<stdlib.h>
//int *list,n;

// int* initList(int *list,int *n)
// {
// 	int i;
// 	printf("Enter the Number of Elements to add:");
// 	scanf("%d",n);
// 	list=(int*)calloc(*n,sizeof(int));
// 	for(i=0;i<*n;i++)
// 	{
// 		scanf("%d",&list[i]);
// 	}
// 	return list;
// }
int* initList(int *n)
{
	int i,*list;
	printf("Enter the Number of Elements to add:");
	scanf("%d",n);
	list=(int*)calloc(*n,sizeof(int));
	printf("Enter the Elements:\n");
	for(i=0;i<*n;i++)
	{
		scanf("%d",&list[i]);
	}
	return list;
}
void insertElement(int *list,int *n)
{
	int i,x,pos,ch;
	printf("Enter the Position to Insert (1-%d):",*n);
	scanf("%d",&pos);
	pos=pos-1;
	if(pos>=*n || pos<0)
	{
		printf("Sorry: Index out of Existing List Bound\n");
		printf("If you insist, I can add this element at the Last or First Element(1 - YES|0 - NO):");
		scanf("%d",&ch);
		if(!ch)
			return;
		printf("First or Last: (1 - FIRST | 0 - LAST):");
		scanf("%d",&ch);
		if(ch)
			pos=0;
		else
			pos=*n;

	}
	list=realloc(list,(*n+1)+sizeof(int));
	//list=realloc(list,sizeof(list)+sizeof(int));
	printf("One Space Added\n");
	for(i=(*n-1);i>=pos;i--)
	{
		list[i+1]=list[i];
	}
	printf("Enter the Data Now:");
	scanf("%d",&x);
	list[pos]=x;
	*n=(*n+1);
	printf("\nData Inserted\n");


}
void deleteElement(int *list,int *n)
{
	int i,pos;
	printf("Enter the Position to delete(1-%d):",*n);
	scanf("%d",&pos);
	pos=pos-1;
	if(pos>=*n || pos<0)
	{
		printf("Sorry: Index out of Existing List Bound\n");
		return;
	}
	for(i=pos;i<*n;i++)
		list[i]=list[i+1];
	*n-=1;
	printf("\nElement Removed\n");
	list=realloc(list,(*n)*sizeof(int));
}
void deleteElementIndex(int *list,int *n,int pos)
{
	int i;
	pos=pos-1;
	if(pos>=*n || pos<0)
	{
		printf("Sorry: Index out of Existing List Bound\n");
		return;
	}
	for(i=pos;i<*n;i++)
		list[i]=list[i+1];
	*n-=1;
	printf("\nElement Removed\n");
	list=realloc(list,(*n)*sizeof(int));
}
int searchElement(int *list,int *n,int order) // SEARCH DOESN'T NEED PASS BY REFERENCE
{

	int i,target;
	printf("\nEnter the target value:");
	scanf("%d",&target);
	if(order==2)
	{
		for(i=(*n-1);i>=0;i--)
			if(list[i]==target)
				return (i+1);
	}
	else
	{
		for(i=0;i<*n;i++)
			if(list[i]==target)
				return (i+1);
	}
	return 0;
}
int searchElementTarget(int *list,int *n,int order,int target) // SEARCH DOESN'T NEED PASS BY REFERENCE
{
	int i;
	if(order==2)
	{
		for(i=(*n-1);i>=0;i--)
			if(list[i]==target)
				return (i+1);
	}
	else
	{
		for(i=0;i<*n;i++)
			if(list[i]==target)
				return (i+1);
	}
	return 0;
}
void displayList(int *list,int *n)
{
	int i;
	if(*n==0)
	{
		printf("List Empty");
		return;

	}
	for(i=0;i<*n;i++)
		printf("%d\t",list[i]);
	printf("\n");
}
void fullDupDetect(int *list,int *n) // DOESN'T NEED PASS BY REFERENCE
{
	// int i,j,count;
	// for(i=0;i<*n;i++)
	// {
	// 	count=0;
	// 	for(j=i+1;j<*n;j++)
	// 	{
	// 		if(i==j)
	// 			continue;
	// 		if(list[i]==list[j])
	// 			count++;

	// 	}
	// 	if(count)
	// 		printf("%d\n",list[i]);

	// }
	int i,j=0,count=0;
	int t[*n];
	for(i=0;i<*n;i++)
	{

		if(i!=(searchElementTarget(list,n,2,list[i])-1) && !searchElementTarget(t,&count,1,list[i]))
			t[count++]=list[i];
	}
	printf("Duplicate Count %d And Duplicate IDs are \n",count);
	for(i=0;i<count;i++)
		printf("%d\n",t[i]);
}
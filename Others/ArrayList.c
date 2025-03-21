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
	for(i=0;i<*n;i++)
	{
		scanf("%d",&list[i]);
	}
	return list;
}
void insertElement(int *list,int *n)
{
	int i,x,pos;
	printf("Enter the Position to Insert (1-%d):",*n);
	scanf("%d",&pos);
	pos=pos-1;
	if(pos>=*n || pos<0)
	{
		printf("Sorry: Index out of Existing List Bound\n");
		return;
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
int searchElement(int *list,int *n,int order)
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
int main()
{
	int *list,n,ch,temp;
	//list=initList(list,&n);
	list=initList(&n);
	do 
	{
		printf("\n-----MENU-----\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
		printf("YOUR CHOICE:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insertElement(list,&n);
				break;
			case 2:
				deleteElement(list,&n);
				break;
			case 3:
				printf("\n1. Firt to Last Search\n2. Last to First Search\nYour Choice:");
				scanf("%d",&temp);
				temp=searchElement(list,&n,temp);
				temp?printf("Element Found at %d\n",temp):printf("Element Not Found\n");
				break;
			case 4:
				displayList(list,&n);
				break;
			case 5:
				printf("\nThank You!\n");
				break;
			default:
				printf("\nINVALID CHOICE\n");

		}
		getchar();
	}while(ch!=5);
	// displayList(list,&n);
	// insertElement(list,&n);
	// printf("\nAfter insert spec\n");
	// displayList(list,&n);
	// deleteElement(list,&n);
	// printf("\n After Delete Spec\n");
	// displayList(list,&n);
	return 0;
}
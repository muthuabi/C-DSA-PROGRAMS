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
int searchElementTarget(int *list,int *n,int order,int target)
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
int main()
{
	int *list,n,ch,temp,t,in1,in2;
	//list=initList(list,&n);
	list=initList(&n);
	do 
	{
		printf("\n-----MENU-----\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Find Duplicate\n6. Exit\n");
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
				printf("NOTE: We Only Check two values at maximum to check for duplication\nEnter the target:");
				scanf("%d",&temp);
				in1=searchElementTarget(list,&n,1,temp);
				in2=searchElementTarget(list,&n,2,temp);
				if(in1!=in2)
				{
					printf("There is a Duplicate for %d found at general index %d and %d\n",temp,in1,in2);
					printf("shall i delete the duplicate?(1 - YES | 0 - NO)");
					scanf("%d",&t);
					if(!t)
						break;
					printf("\nWhich element shall I delete FIRST(DEF.) OR LAST?\n1. First\n2. Last\nYour Choice:");
					scanf("%d",&t);
					if(t==2)
						deleteElementIndex(list,&n,in2);
					else
						deleteElementIndex(list,&n,in1);
					
				}
				else
					printf("\nThere is NO Duplicate or No Element at all\n");
				break;
			case 6:
				printf("\nThank You!\n");
				break;
			default:
				printf("\nINVALID CHOICE\n");

		}
		getchar();
		printf("\nPress again to go further....\n");
		getchar();
	}while(ch!=6);
	// displayList(list,&n);
	// insertElement(list,&n);
	// printf("\nAfter insert spec\n");
	// displayList(list,&n);
	// deleteElement(list,&n);
	// printf("\n After Delete Spec\n");
	// displayList(list,&n);
	return 0;
}

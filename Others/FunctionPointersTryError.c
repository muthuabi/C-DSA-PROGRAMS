#include<stdio.h>
//#include<stdlib.h>
int add(int a,int b)
{
	return a+b;
}
int sub(int a,int b)
{
	return a-b;
}
int mul(int a,int b)
{
	return a*b;
}
int div(int a,int b)
{
	return a/b;
}
int main()
{
	int a,b;
	char ch;
	printf("Enter a and b:\n");
	scanf("%d",&a);
	scanf("%d",&b);
	do
	{
		printf("\n\n1.Addtion(+)\n2.Subtraction(-)\n3.Multiplication(*)\n4.Division(/)5.Exit\n\n");
		printf("Your Choice:");
		scanf("%c",&ch);
		switch(ch)
		{
			case '+':
			case 1:
				int (*my_function)(int,int)=add;
				printf("The Addition of %d and %d is :%d\n",a,b,(*my_function)(a,b));
				break;
			case '-':
			case 2:
				int (*my_function)(int,int)=sub;
				printf("The Subtraction of %d and %d is :%d\n",a,b,(*my_function)(a,b));
				break;
			case '*':
			case 3:
				int (*my_function)(int,int)=mul;
				printf("The Multiplication of %d and %d is :%d\n",a,b,(*my_function)(a,b));
				break;
			case '/':
			case 4:
				int (*my_function)(int,int)=div;
				printf("The Division of %d and %d is :%d\n",a,b,(*my_function)(a,b));
				break;
			case 5:
				printf("\nThank You\n");
				break;
			default:
				printf("\nINVALID CHOICE\n");

		}
		
	}while(ch!=5);
	return 0;
}
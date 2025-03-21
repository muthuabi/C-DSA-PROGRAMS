#include<stdio.h>
#include<stdlib.h>
typedef struct Op
{	
	int (*int_func)(int ,int);
	float (*float_func)(float,float);
}op;
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
int dvd(int a,int b)
{
	return a/b;
}
int main()
{
	int a,b;
	op op;
	int ch;
	printf("Enter a and b:\n");
	scanf("%d",&a);
	scanf("%d",&b);
	do
	{
		
		printf("\n\n------MENU------\n");
		printf("1. Addition\n");
		printf("2. Subtraction\n");
		printf("3. Multiplication\n");
		printf("4. Division\n");
		printf("5. Change Inputs\n");
		printf("6. Exit\n");
		printf("Your Choice:");
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1:
				op.int_func=add;
				printf("The Additon of two numbers is %d",op.int_func(a,b));
				break;
			case 2:
				op.int_func=sub;
				printf("The Subtraction of two numbers is %d",op.int_func(a,b));
				break;
			case 3:
				op.int_func=mul;
				printf("The Multiplication of two numbers is %d",op.int_func(a,b));
				break;
			case 4:
				op.int_func=dvd;
				printf("The Division of two numbers is %d",op.int_func(a,b));
				break;
			case 5:
				printf("Enter a and b:\n");
				scanf("%d",&a);
				scanf("%d",&b);
				break;
			case 6:
				printf("\nThank You\n");
				break;
			default:
				printf("\nInvalid Option\n");

		}
		getchar();
		getchar();

	}while(ch!=6);
	
}
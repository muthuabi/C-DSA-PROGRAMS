#include<stdio.h>
#include<stdlib.h>
typedef struct Complex
{
	float real;
	float imag;
}complex;

complex addComplex(complex *c1,complex *c2)
{
	complex res;
	res.real=c1->real+c2->real;
	res.imag=c1->imag+c2->imag;
	return res;
}
complex subComplex(complex *c1,complex *c2)
{
	complex res;
	res.real=c1->real-c2->real;
	res.imag=c1->imag-c2->imag;
	return res;
}
complex mulComplex(complex *c1,complex *c2)
{
	complex res;
	res.real=(c1->real*c2->real)-(c1->imag*c2->imag);
	res.imag=(c1->real*c2->imag)+(c1->imag*c2->real);
	return res;
}
complex divComplex(complex *c1,complex *c2)
{
	complex res;
	float denom=(c2->real * c2->real)+(c2->imag * c2->imag);
	res.real=((c1->real * c2->real)+(c1->imag * c2->imag))/denom;
	res.imag=((c1->imag * c2->real)-(c1->real * c2->imag))/denom;
	return res;
}
void printComplex(complex c)
{

	printf("\n   %.0f%+.0fi ",c.real,c.imag);
	printf("\nReal Part: %.2f",c.real);
	printf("\nImaginary Part: %+.2fi\n",c.imag);
}
void getComplex(complex *c1,complex *c2)
{
	printf("Real part of c1:");
	scanf("%f",&c1->real);
	printf("Imaginary Part of c1:");
	scanf("%f",&c1->imag);
	printf("Real part of c2:");
	scanf("%f",&c2->real);
	printf("Imaginary part of c2:");
	scanf("%f",&c2->imag);
}
int main()
{
	complex c1,c2,res;
	int ch;
	getComplex(&c1,&c2);
	printf("\nComplex Number 1:\n");
	printComplex(c1);
	printf("\nComplex Number 2:\n");
	printComplex(c2);
	do
	{
		
		printf("\n\n------MENU------\n");
		printf("1. Addition\n");
		printf("2. Subtraction\n");
		printf("3. Multiplication\n");
		printf("4. Division\n");
		printf("5. Change Values\n");
		printf("6. Exit\n");
		printf("Your Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:

			    res=addComplex(&c1,&c2);
			    printf("\nAddition of Two Complex:\n");
			    printComplex(res);
				break;
			case 2:
				res=subComplex(&c1,&c2);
			    printf("\nSubtraction of Two Complex:\n");
			    printComplex(res);
				break;
			case 3:
				res=mulComplex(&c1,&c2);
			    printf("\nMultiplication of Two Complex:\n");
			    printComplex(res);
				break;
			case 4:
	 			res=divComplex(&c1,&c2);
			    printf("\nDivision of Two Complex:\n");
			    printComplex(res);
				break;
			case 5:
				getComplex(&c1,&c2);
				printf("\nComplex Number 1:\n");
				printComplex(c1);
				printf("\nComplex Number 2:\n");
				printComplex(c2);
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
	return 0;
}
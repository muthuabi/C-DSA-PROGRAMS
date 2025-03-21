#include<stdio.h>
#include<string.h>
int mylen(char* x)
{
	int i=0;
	while(x[i]!='\0')
		i++;
	return i;
}
void mycat(char *a,char *b)
{
	int a_len=mylen(a);
    int b_len=mylen(b);
    a+=(a_len);
    while(*b!='\0')
    {
       *a=*b;
        a++;
        b++;
    }
    *a='\0';
    a-=(a_len+b_len);
    b-=b_len;
}
int main()
{
	char *a,*b;
	int a_len,b_len,i;
    printf("Enter the a:");
    scanf("%s",a);
    printf("Enter the b:");
    scanf("%s",b);
    printf("Before Concate\n A is %s B is %s",a,b);
    mycat(a,b);
    printf("\nAfter Concat\n A is %s B is %s\n",a,b);
}
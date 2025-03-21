#include<stdio.h>
#include<stdlib.h>
int mylen(char *s)
{
	int i=0;
	while(s[i]!='\0')
		i++;
	return i;
}
typedef struct Stack
{
	int n;
	int top;
	char **arr;
}stack;
stack* initStack(int n)
{
	int i,nn;
	nn=n*2;
	stack* s=(stack*)malloc(sizeof(stack));
	s->n=n;
	s->top=-1;
	s->arr=(char**)malloc(n*sizeof(char*));
	for(i=0;i<n;i++)
	{
		s->arr[i]=(char*)malloc(nn);
		s->arr[i][0]='\0';
	}
	return s;
}
int isFull(stack *s)
{
	return s->top==(s->n-1);
}
int isEmpty(stack *s)
{
	return s->top==-1;
}

int push(stack *s,char *x)
{
	if(isFull(s))
		return 0;
	s->arr[++s->top]=x;
	return 1;	
}
char* pop(stack *s)
{
	if(isEmpty(s))
		return NULL;
	return s->arr[s->top--];
}
char* peek(stack *s)
{
	if(isEmpty(s))
		return NULL;
	return s->arr[s->top];
}
void display(stack *s)
{
	int i;
	for(i=0;i<=s->top;i++)
		printf("%s ",s->arr[i]);
}
void concator(char *s,char c)
{
	int len=mylen(s);
	s[len]=c;
	s[len+1]='\0';
}
char* postfixToInfix(char *post,int len,int *in_len)
{
	int i,j=0;
	stack *s=initStack(len);
	char *v1=(char*)malloc(100),*v2=(char*)malloc(100),*t;
	int v1_len,v2_len;
	for(i=0;i<len;i++)
	{
		
		switch(post[i])
		{
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
				v2=pop(s);
				v1=peek(s);
				v1_len=mylen(v1);
				v2_len=mylen(v2);
				//printf("%s %s",v2,v1);
				s->arr[s->top]=(char*)malloc((s->n)*(s->n));
				s->arr[s->top][0]='\0';
				concator(s->arr[s->top],'(');
				for(j=0;j<v1_len;j++)
					concator(s->arr[s->top],v1[j]);
				concator(s->arr[s->top],post[i]);
				for(j=0;j<v2_len;j++)
					concator(s->arr[s->top],v2[j]);
				concator(s->arr[s->top],')');
				//printf("%s",s->arr[s->top]);
				break;
			default:
				t=(char*)malloc(100);
				t[0]=post[i];
				t[1]='\0';
				push(s,t);
				
		}
	}
	//display(s);
	return pop(s);	
}
int main()
{
	int len,i,j,in_len;
	char *post=(char*)malloc(1024),*infix;
	printf("Enter the Postfix Expression:");
	scanf("%s",post);
	len=mylen(post);
	post=(char*)realloc(post,len);
	infix=(char*)malloc(sizeof(1024));
	infix=postfixToInfix(post,len,&in_len);
	printf("%s",infix);
	return 0;
}

#include "StackStruct.c"
#include "mystrlen.c"
int priority(char c)
{
	switch(c)
	{
		
		case '^':
			return 3;
		case '*':
		case '/':
			return 2;
		case '+':
		case '-':
			return 1;
		default:
			return 0;
	}
}
int main()
{
	char *arr=(char*)malloc(1024),*postfix;
	int len,i,j=0;
	printf("Enter the Valid Expression:\n");
	scanf("%s",arr);
	len=mylen(arr);
	arr=(char*)realloc(arr,len);
	stack *s=initStack(len);
	postfix=(char*)malloc(len);
	for(i=0;i<len;i++)
	{
		//printf("%d th Iteration Element %c\n",i,arr[i]);
		switch(arr[i])
		{
			case '^':
			case '+':
			case '-':
			case '*':
			case '/':
			case '(':
				if(isEmpty(s) || arr[i]=='(')
					//printf("%d th iteration %c\n",i,arr[i]);
					push(s,arr[i]);
					//printStack(s,0);
					//peek(s) is equals to arr[s->top]
				else
				{
					//printf("%dth %c (%d) <= %c (%d)\n",i,arr[i],priority(arr[i]),peek(s),priority(peek(s)));
					while(priority(arr[i])<=priority(peek(s)))
						postfix[j++]=pop(s);
					push(s,arr[i]);
				}
				break;
			case ')':
				while(peek(s)!='(')
					postfix[j++]=pop(s);
				pop(s);
				break;
			default:
				postfix[j++]=arr[i];
				
		}
	}
	//printStack(s,0);
	while(!isEmpty(s))
		postfix[j++]=pop(s);
	printf("%s",postfix);
	return 0;
}

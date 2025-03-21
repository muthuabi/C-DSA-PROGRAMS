#include<stdio.h>
#include<stdlib.h>
int mylen(char *s)
{
	int i=0;
	while(s[i]!='\0')
		i++;
	return i;
}
void concator(char *s,char c)
{
	int len=mylen(s);
	s[len]=c;
	s[len+1]='\0';
}
int main()
{
	char **arr=(char**)malloc(5*sizeof(char*));
	int i;
	for(i=0;i<5;i++)
	{
		arr[i]=(char*)malloc(10);
		arr[i][0]='\0';
	}
	printf("%s\n",arr[0]);
	concatar(arr[0],'H');
	concatar(arr[0],'H');
	concatar(arr[0],'H');
	printf("%s",arr[0]);
	
	return 0;
}

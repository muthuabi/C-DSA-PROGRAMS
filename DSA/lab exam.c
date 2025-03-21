#include<stdio.h>
int main(){
	int N,D,i,n,value,arr[10];
	printf("Enter the value of N and D:\n");
	scanf("%d %d",&N,&D);
	n=D;
	for(i=n;i>0;i--){
		value=N-i;
		arr[i]=value;
		
		N=N-i;
	}
for(i=n;i>0;i--){
	printf("%d\t",arr[i]);
}
	return 0;
}


#include<stdio.h>
int main(){
	int n,x,i;
	printf("Enter the value of n and x :");
	scanf("%d %d",&n,&x);
	for(i=n;i>=1;i--){
		if(i%x==0){
			printf("%d \t",i);
		}
	}
	return 0;
}

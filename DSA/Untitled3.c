#include<stdio.h>
struct details{
	char title[20];
	char author[20];
	int price;
};
int main(){
	int n,i;
	printf("Enter the value of n:");
	scanf("%d",&n);
	struct details s[n];
	for(i=1;i<=n;i++){
		scanf("%s",&s[i].title);
		scanf("%s",&s[i].author);
		scanf("%d",&s[i].price);
	}
	for(i=1;i<=n;i++){
		printf("%s\n",s[i].title);
		printf("%s\n",s[i].author);
		printf("%d\n",s[i].price);
	}
	return 0;
}

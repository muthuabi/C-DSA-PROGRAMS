#include<stdio.h>
struct details{
	char title[20];
	char author[20];
	float price;
};
int main(){
	int n,i;
	printf("Enter the value of n:");
	scanf("%d",&n);
	struct details s[n];
	for(i=0;i<n;i++){
		scanf("%s",s[i].title);
		scanf("%s",s[i].author);
		scanf("%f",s[i].price);
	}
	for(i=0;i<n;i++){
		printf("%s",s[i].title);
		printf("%s",s[i].author);
		printf("%.2f",s[i].price);
	}
	return 0;
}

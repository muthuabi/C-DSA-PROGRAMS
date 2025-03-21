#include<stdio.h>
struct Employee{
	char name[50];
	int id;
	float salary;
};
int main(){
 int i;
struct Employee *s[i];
for(i=0; i<=2;i++){
	printf("NAME:");
	scanf("%s",&s[i]->name);
		printf("ID:");
		scanf("%d",&s[i]->id);
			printf("SALARY:");
			scanf("%f",&s[i]->salary);
}
 

for( i=0; i<=2;i++){
	printf("%s\n",s[i]->name);
		printf("%d\n",s[i]->id);	
			printf("%f\n",s[i]->salary);
}
return 0;
}


#include<stdio.h>
#include<stdlib.h>
int n=0,i;
typedef struct Employee
{
	char* name;
	int empid;
	int salary;
	char* department;
}Employee;
// void setEmployeeDetails(Employee *s,char* name,int empid,int salary,char* department)
// {
// 	s->name=name;
// 	s->empid=empid;
// 	s->salary=salary;
// 	s->department=department;
// }
Employee *s;
int checkID(int id)
{ int i;
	for(i=0;i<n;i++)
	{
		if(s[i].empid==id)
			return 1;
	}
	return 0;
}
int setEmployeeDetails(Employee *s,int i)
{
	char* name=malloc(1024);
	char* department=malloc(1024);
	int empid;
	int salary;
	printf("\nS.No:%d\n",(i+1));
	printf("Enter the Name:\n");
	scanf("%s",name);
	printf("Enter empid:\n");
	scanf("%d",&empid);
	printf("Enter salary:\n");
	scanf("%d",&salary);
	printf("Enter the department:\n");
	scanf("%s",department);
	while(checkID(empid))
	{
		printf("empid already exists!\nPlease Enter empid again:\n");
		scanf("%d",&empid);
	}
	s->name=name;
	s->empid=empid;
	s->salary=salary;
	s->department=department;
	return 1;
}
Employee* fetchEmployee(int empid)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(s[i].empid==empid)
			return &s[i];
	}
	
}

int printEmployeeDetails(Employee *s,int i)
{

	printf("S.No:%d\n",(i+1));
	printf("Name:%s\n",s->name);
	printf("Employee ID:%d\n",s->empid);
	printf("Mark:%d\n",s->salary);
	printf("Department:%s\n\n",s->department);

}
int deleteEmployee(int empid)
{
	int j;
	Employee *t=fetchEmployee(empid);
	Employee *s_temp;
	if(t)
	{
		 j=0;
       for(i=0;i<n;i++)
       {

       	if(s[i].empid==empid)
       	{
       		//j--;
       		continue;
       	}
       	s_temp[j++]=s[i];
       }
       n=j;
       s=s_temp;
       return 1;
	}
	else
		return 0;

}
int updateEmployee(int empid)
{
   Employee *t=fetchEmployee(empid);
   int c;
   char *name=malloc(1024);
   char *department=malloc(1024);
   int nempid;
   int salary;
   printf("What to Change\n1.Name\n2.Empid\n3.Salary\n4.Department\nYour Choice:");
   scanf("%d",&c);
   printf("\n");
   switch(c)
   {
   	case 1:
   		printf("Enter the Name:");
   		scanf("%s",name);
   		t->name=name;
   		break;
   	case 2:
   		printf("Enter new empid:");
   		scanf("%d",&nempid);
   		while(checkID(nempid))
			{
				printf("empid already exists!\nPlease Enter empid again:\n");
				scanf("%d",&nempid);
			}
   		t->empid=nempid;
   		break;
   	case 3:
   		printf("Enter new salary:");
   		scanf("%d",&salary);
   		t->salary=salary;
   		break;
   	case 4:
   		printf("Enter new Department:");
   		scanf("%s",department);
   		t->department=department;
   		break;
   	default:
   		printf("No Field");
   }
   return 1;

}
int printAllEmployeeDetails()
{
	//printf("%d",structLength(s));
	if(n<=0)
		return 0;
	for(int i=0;i<n;i++)
		printEmployeeDetails(&s[i],i);
	return 1;

}
int main()
{
   // int n,i;
   int ch;
   int flag;
   do
   {

   	printf("\n------- MENU ---------\n\n");
   	printf("1. Add Employee\n");
   	printf("2. Show Employee\n");
   	printf("3. Show All Employees\n");
   	printf("4. Update Employee\n");
   	printf("5. Delete Employee\n");
   	printf("6. Exit\n");
   	printf("-------------------------\n");
   	printf("\nYour Choice:");
   	scanf("%d",&ch);
   	switch(ch)
   	{
   		case 1:
   			//Consider n is 2 already
   			int t_n;
   			printf("Enter the No of Employees:\n");
   			scanf("%d",&t_n);
   			n+=t_n;
   			s=realloc(s,n*sizeof(Employee));
   			// if(n-t_n!=0)
   			//    realloc(s,n*sizeof(Employee));
   			flag=1;
   			for(i=(n-t_n);i<n;i++)
   			{

   				if(!setEmployeeDetails(&s[i],i))
   				{
   					flag=0;
   					break;
   				}
   			}
   			if(flag)
   				printf("\nSuccessfully Inserted\n");
   			break;
   		case 2:
   				int empid;
   				printf("Enter the Employee ID:");
   				scanf("%d",&empid);
   				Employee *t=fetchEmployee(empid);
   				if(t)
   				printEmployeeDetails(t,1);
   				else 
   				printf("\nRecord Not Found\n");
   			break;
   		case 3:
   			printf("All Employees list\n\n");
				if(!printAllEmployeeDetails())
  					printf("\n\t***No Records***\t\n");
   			break;
   		case 4:
   			
   			printf("Enter the Employee ID:");
   			scanf("%d",&empid);
   			if(updateEmployee(empid))
   				printf("\nUpdated Successfully\n");
   			else
   				printf("\nUpdate Failed\n");
   			break;
   		case 5:
   			printf("\nEnter the ROll Number:");
   			scanf("%d",&empid);
   			if(deleteEmployee(empid))
   				printf("\nDeleted Successfully\n");
   			else
   				printf("\nDeletion Failed\n");
   			break;
   		case 6:
   			printf("Thank You!");
   			free(s);
   			break;
   		default:
   			printf("Invalid Option");
   	}
   	getchar();
   	getchar();

   }while(ch!=6);
   


   return 0;	
}
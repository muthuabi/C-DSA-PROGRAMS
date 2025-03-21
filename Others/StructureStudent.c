#include<stdio.h>
#include<stdlib.h>
int n=0,i;
typedef struct Student
{
	char* name;
	int rollno;
	int marks;
}Student;
// void setStudentDetails(Student *s,char* name,int rollno,int marks)
// {
// 	s->name=name;
// 	s->rollno=rollno;
// 	s->marks=marks;
// }
Student *s;
int checkID(int id)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(s[i].rollno==id)
			return 1;
	}
	return 0;
}
int setStudentDetails(Student *s,int i)
{
	char* name=malloc(1024);
	int rollno;
	int marks;
	printf("\nS.No:%d\n",(i+1));
	printf("Enter the Name:\n");
	scanf("%s",name);
	printf("Enter RollNo:\n");
	scanf("%d",&rollno);
	printf("Enter Marks:\n");
	scanf("%d",&marks);
	while(checkID(rollno))
	{
		printf("rollno already exists!\nPlease Enter rollno again:\n");
		scanf("%d",&rollno);
	}
	s->name=name;
	s->rollno=rollno;
	s->marks=marks;
	return 1;
}
Student* fetchStudent(int rollno)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(s[i].rollno==rollno)
			return &s[i];
	}
	
}
int printStudentDetails(Student *s,int i)
{

	printf("S.No:%d\n",(i+1));
	printf("Name:%s\n",s->name);
	printf("Roll No:%d\n",s->rollno);
	printf("Mark:%d\n\n",s->marks);

}
int deleteStudent(int rollno)
{
	int j;
	Student *t=fetchStudent(rollno);
	Student *s_temp;
	if(t)
	{
		 j=0;
       for(i=0;i<n;i++)
       {

       	if(s[i].rollno==rollno)
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
int updateStudent(int rollno)
{
   Student *t=fetchStudent(rollno);
   int c;
   char *name=malloc(1024);
   int nrollno;
   int marks;
   printf("What to Change\n1.Name\n2.RollNo\n3.Marks\nYour Choice:");
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
   		printf("Enter new RollNo:");
   		scanf("%d",&nrollno);
   		while(checkID(nrollno))
			{
				printf("rollno already exists!\nPlease Enter rollno again:\n");
				scanf("%d",&nrollno);
			}
   		t->rollno=nrollno;
   		break;
   	case 3:
   		printf("Enter new Marks:");
   		scanf("%d",&marks);
   		t->marks=marks;
   		break;
   	default:
   		printf("No Field");
   }
   return 1;

}
int printAllStudentDetails()
{
	//printf("%d",structLength(s));
	if(n<=0)
		return 0;
	for(int i=0;i<n;i++)
		printStudentDetails(&s[i],i);
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
   	printf("1. Add Student\n");
   	printf("2. Show Student\n");
   	printf("3. Show All Students\n");
   	printf("4. Update Student\n");
   	printf("5. Delete Student\n");
   	printf("6. Exit\n");
   	printf("-------------------------\n");
   	printf("\nYour Choice:");
   	scanf("%d",&ch);
   	switch(ch)
   	{
   		case 1:
   			//Consider n is 2 already
   			int t_n;
   			printf("Enter the No of Students:\n");
   			scanf("%d",&t_n);
   			n+=t_n;
   			s=realloc(s,n*sizeof(Student));
   			// if(n-t_n!=0)
   			//    realloc(s,n*sizeof(Student));
   			flag=1;
   			for(i=(n-t_n);i<n;i++)
   			{

   				if(!setStudentDetails(&s[i],i))
   				{
   					flag=0;
   					break;
   				}
   			}
   			if(flag)
   				printf("\nSuccessfully Inserted\n");
   			break;
   		case 2:
   				int rollno;
   				printf("Enter the Roll No:");
   				scanf("%d",&rollno);
   				Student *t=fetchStudent(rollno);
   				if(t)
   				printStudentDetails(t,1);
   				else 
   				printf("\nRecord Not Found\n");
   			break;
   		case 3:
   			printf("All Students list\n\n");
				if(!printAllStudentDetails())
  					printf("\n\t***No Records***\t\n");
   			break;
   		case 4:
   			
   			printf("Enter the Roll No:");
   			scanf("%d",&rollno);
   			if(updateStudent(rollno))
   				printf("\nUpdated Successfully\n");
   			else
   				printf("\nUpdate Failed\n");
   			break;
   		case 5:
   			printf("\nEnter the ROll Number:");
   			scanf("%d",&rollno);
   			if(deleteStudent(rollno))
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
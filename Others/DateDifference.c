#include<stdio.h>
typedef struct Date
{
	int day;
	int month;
	int year;
}Date;
void getDate(Date *d)
{
	do
	{
	printf("Day:");
	scanf("%d",&d->day);
	}while(d->day>31 || d->day<1);
	do
	{
	printf("Month:");
	scanf("%d",&d->month);
	}while(d->month>12 || d->month<1);
	do{
	printf("Year:");
	scanf("%d",&d->year);
	}while(d->year<1000 || d->year>2024);
}
void printDate(Date d)
{
	printf("\n%02d/%02d/%d\n",d.day,d.month,d.year);
}
int leapornot(int year)
{
	if(year%100==0)
	{
		if(year%400==0)
			return 1;
		else
			return 0;
	}
	else 
	{
		if(year%4==0)
			return 1;
		else 
			return 0;
	}
}
int daysOfMonth(int month,int year)
{
	month--;
	int days_m[]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(leapornot(year))
		days_m[1]=29;
	return days_m[month];
}
void calcDifference(Date from,Date to)
{ 	int i;
    int f_day=from.day;
    int f_month=from.month;
    int f_year=from.year;
    int t_day=to.day;
    int t_month=to.month;
    int t_year=to.year;
    int days=0;
    int month=0;
    int year=0;
   	while(f_month<t_month || f_year<t_year)
   	{
   		printf("Month %d Year %d\n",f_month,f_year);
   		f_month++;
   		if(f_month>12)
   		{
   			f_month=1;
   			f_year++;
   		}
   		days+=daysOfMonth(f_month,f_year);
   		month++;
   	}
	days=(days-f_day+t_day);
	printf("Date Difference\n--------------------\nDays: %d\nMonths: %d\nYear: %.1f\n",days,month,(float)month/12);
	printf("Totally %d Day(s) %d Year(s) %d Month(s)",days,month/12,month%12);

}
int main()
{
	Date from,to;
	printf("------From Date-----\n");
	getDate(&from);
	printf("------To Date-----\n");
	getDate(&to);

	printDate(from);
	printDate(to);
	calcDifference(from,to);
	printf("\n");
	return 0;

}
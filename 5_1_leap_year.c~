#include <stdio.h>
int is_leap_year(int year);

int main(void)
{
	int year;
	int i=1;
	while(i==1)
	{
		printf("\n\nplease input a year:");
		scanf("%d",&year);
		if(is_leap_year(year))
			printf("\n %d is leap year",year);
		else
			printf("\n %d is not leap year",year);
		printf("\nwhat do you want to do next?");
		printf("\n1.go on\t2.stop\n");
		scanf("%d",&i);
	}
	return 0;
}

int is_leap_year(int year)
{
	if( (year%400)==0 || ((year%100)!=0 && (year%4)==0) )
		return 1;
	else
		return 0;
}



#include <stdio.h>
#include <math.h>

double myround(double x);

int main(void)
{
	int i=1;
	double x;
	double result;
	
	while(i==1)
	{
		printf("\n\nplease input a number:");
		scanf("%lf",&x);
		result=myround(x);
		printf("\nthe result of round is:%lf",result);
		printf("\nwhat do you want to do next?");
		printf("\n1.go on\t2.stop\n");
		scanf("%d",&i);
	}
	return 0;
}

double myround(double x)
{
	int buff=abs((int)(x*10))%10;
	if(x>=0)
	{
		if(buff>=5)	return ceil(x);
		else		return floor(x);
	}
	else
	{
		if(buff>=5)	return floor(x);
		else		return ceil(x);
	}
}

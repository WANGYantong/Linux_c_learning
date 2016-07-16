#include <stdio.h>
#include "7_2_rational.h"
int main(void)
{
	RATIONAL_STRUCT x,y,buff;
	int j;
	int select;
	int i=1;
	while(i==1)
	{
		printf("\n/***********************************************");
		printf("\nYOU ARE WANTED TO INPUT tWO FRACTION\n");
		for(j=1;j<3;j++)
			{
				printf("\nplease input number %d fraction\n",j);
				printf("please input the numerator\n");
				scanf("%d",&buff.numerator);
				printf("please input the denominator\n");
				scanf("%d",&buff.denominator);
				if(j==1)
					x=buff;
				if(j==2)
					y=buff;
			}
		printf("\n/***********************************************");
		printf("\nselect the opeartion:\n");
		printf("1,add\t2,sub\t3,mul\t4,div\n");
		scanf("%d",&select);
		switch(select)
		{
			case(1): buff=add_rational(x,y);break;
			case(2): buff=sub_rational(x,y);break;
			case(3): buff=mul_rational(x,y);break;
			case(4): buff=div_rational(x,y);break;
			default: goto error;
		}
		print_rational(buff);
		printf("\n/***********************************************");
		printf("\nwhat do you want to do next?\n");
		printf("1,go on\t2,stop\n");
		scanf("%d",&i);
	}
	return 0;
error:
	printf("\nIllegal input!\n");
	return 0;
}

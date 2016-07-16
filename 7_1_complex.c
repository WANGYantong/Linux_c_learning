#include <stdio.h>
#include "7_1_complex.h"

int main(void)
{
	COMPLEX_STRUCT z1,z2,buff;
	int i=1;
	int select;
	int j;
	while(i==1)
	{
		printf("\n*********************************************************");
		printf("\nNOW YOU ARE WANTED TO INPUT TWO COMPLEX NUMBER");
		printf("\n************************STEP 1***************************");
		for(j=1;j<3;j++)
		{
			printf("\nplease select the number %d format:\n",j);
			printf("1,real_imag\t2,mag_ang\n");
			scanf("%d",&select);
			switch(select)
			{
				case(1):	printf("\nplease input the real part:\n");
						scanf("%lf",&buff.x);
						printf("\nplease input the ima part:\n");
						scanf("%lf",&buff.y);
						break;
				case(2):	printf("\nplease input the mag part:\n");
						scanf("%lf",&buff.x);
						printf("\nplease input the ang part:\n");
						scanf("%lf",&buff.y);
						buff=make_from_mag_ang(buff.x,buff.y);
						break;
				default:	goto error_solve;
					
			}
			if(j==1)	z1=buff;
			if(j==2)	z2=buff;
		}
		printf("\n************************STEP 2***************************");
		printf("\nplease select the opeartion:\n");
		printf("1,add\t2,sub\t3,mul\t4,div\n");
		scanf("%d",&select);
			switch(select)
			{
				case(1):	buff=add_complex(z1,z2);
						break;
				case(2):	buff=sub_complex(z1,z2);
						break;
				case(3):	buff=mul_complex(z1,z2);
						break;
				case(4):	buff=div_complex(z1,z2);
						break;
				default:	goto error_solve;
					
			}
		print_complex(buff);
		printf("\n************************STEP 3***************************");
		printf("\nwhat do you want to do next?\n");
		printf("1,go on\t2,stop\n");
		scanf("%d",&i);
	}	
	return 0;

error_solve:
	printf("\nIllegal number input\n");
	return 0;
}

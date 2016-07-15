#include <stdio.h>

int main(void)
{
	int dividend,divisor,result;
	int i=1;
	while(i==1)
	{ 
		printf("please input dividend:");
		scanf("%d",&dividend);

		printf("please input divisor:");
		scanf("%d",&divisor);

		result=(dividend+divisor-1)/divisor;
		printf("the ceiling result is %d\n",result);

		printf("\nwhat do you want to do next?\n");
		printf("1.go on\t2.stop\n");
		scanf("%d",&i);
	}
	return 0;
}

#include <stdio.h>

int fibonacci(int n);

int main(void)
{
	int num;
	int i=1;
	while(i==1)
	{
		printf("\n\nplease input a positive number:\n");
		scanf("%d",&num);
		if(num<0)
		{

			printf("error!\n");
			break;
		}
		printf("the fibonacci of number %d is %d\n",num,fibonacci(num));
		
		printf("what do you want to do next?\n");
		printf("1.go on\t2.stop\n");
		scanf("%d",&i);
	}
	return 0;
}

int fibonacci(int n)
{
	switch(n)
	{
		case 0: return 1; break;
		case 1: return 1; break;
		default: return fibonacci(n-1)+fibonacci(n-2);
	}
}


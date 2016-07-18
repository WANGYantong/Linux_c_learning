#include <stdio.h>
#include <stdlib.h>
#define N 20

int a[N];

void gen_random(int upper_bound)
{
	int i;
	for (i=0;i<N;i++)
	{
		a[i]=rand()%upper_bound;
	}
}

int main(void)
{
	int i,j,histogram[10]={0};
	int max;
	gen_random(10);
	for(i=0;i<N;i++)
	{
		histogram[a[i]]++;
	}
	max=histogram[0];
	for(i=1;i<10;i++)
	{
		if(max<histogram[i])
			max=histogram[i];
	}
	for(i=0;i<10;i++)
	{
		printf("\t%d",i);
	}
	printf("\n");
	for(i=0;i<max;i++)	
	{
		for(j=0;j<10;j++)
		{

			if(histogram[j]-->0)	printf("\t*");
			else			printf("\t");
		}
		printf("\n");
	}		
	return 0;
}

#include <stdio.h>
#include <math.h>

void diamond(int num, char form);

int main(void)
{
	int num;
	char form;
	int i=1;
	while(i==1)
	{
		printf("\n\nplease input odd number of diamond and the form,just like 3,*:");
		scanf("%d,%c",&num,&form);
		if(num%2==0)
		{
			printf("\nerror!the number must be odd!\n");
			break;
		}
		diamond(num,form);
		printf("\nwhat do you want to do next :");
		printf("\n1,go on\t2,stop\n");
		scanf("%d",&i);
	}
	return 0;
}
//此处参考网上做法，将菱形中间图形为坐标原点建立直角坐标系，凡是带星星图案的坐标的绝对值之和一定小于等于num/2
void diamond(int num, char form)
{
	int i,j,m;
	m=num/2;
	printf("\n");
	for(i=-m;i<=m;i++)	
	{
		for(j=-m;j<=m;j++)
			{
				if((abs(i)+abs(j))<=m)
					printf("%c\t",form);
				else
					printf("\t");
			}
		printf("\n");
	}	
}


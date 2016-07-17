#include <stdio.h>
#define N 5

void permutation(int a[],int m,int n);
void swap(int i,int j);
void print(int a[]);
void init(void);
int a[N];

int main(void)
{
	int select,m,n;
	init();
	print(a);
	do{
		printf("please input the start and end number,like 0,2\n");
		scanf("%d,%d",&m,&n);
		permutation(a,m,n);
		printf("\nwhat do you want to do next?\n");
		printf("1,go on\t2,stop\n");
		scanf("%d",&select);
	}while(select==1);
	return 0;
}

void init(void)
{
	int i;
	for(i=0;i<N;i++)
		a[i]=i;
}

void swap(int i,int j)
{
	int temp;
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}

void print(int a[])
{
	int i;
	printf("\n");
	for(i=0;i<N;i++)
		printf("%d\t",a[i]);
	printf("\n");
}

void permutation(int a[],int m,int n)
{
	int i;
	if(m==n)
		{
			print(a);
			return;
		}
	else
		{
			for(i=m;i<=n;i++)
				{
					swap(m,i);
					permutation(a,m+1,n);
					swap(m,i);
				}
		}
}


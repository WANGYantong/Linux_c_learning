#include <stdio.h>
#define N 5
#define M 3

void combination(int array1[], int array2[], int m, int n);
void permutation(int array1[], int m, int n);
void swap(int i, int j);
void print(int array[], int number);
void init(int array[], int number);

int a[N];
int b[M];

int main(void)
{
	int select, m, n;
	do {
		printf("\nplease select the mode:\n");
		printf("1,permutation\t2,combination\n");
		scanf("%d", &select);

		init(a, N);
		print(a, N);

		switch (select) {
		case (1):
			printf
			    ("\nplease input the start and end number,like 0,2\n");
			scanf("%d,%d", &m, &n);
			permutation(a, m, n);
			break;
		case (2):
			combination(a, b, M, N);
			break;
		default:
			break;
		}
		printf("\nwhat do you want to do next?\n");
		printf("1,go on\t2,stop\n");
		scanf("%d", &select);
	} while (select == 1);

	return 0;
}

void init(int array[], int number)
{
	int i;
	for (i = 0; i < number; i++)
		array[i] = i;
}

void swap(int i, int j)
{
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void print(int array[], int number)
{
	int i;
	printf("\n");
	for (i = 0; i < number; i++)
		printf("%d\t", array[i]);
	printf("\n");
}

void permutation(int array1[], int m, int n)
{
	int i;
	if (m == n) {
		print(array1, N);
		return;
	} else {
		for (i = m; i <= n; i++) {
			swap(m, i);
			permutation(array1, m + 1, n);
			swap(m, i);
		}
	}
}

void combination(int array1[], int array2[], int m, int n)
{
	int i;
	if (m == 0) {
		print(array2, M);
		return;
	} else {
		for (i = n - 1; i >= 0; i--) {
			array2[m - 1] = array1[i];
			combination(array1, array2, m - 1, i);
		}
	}
}

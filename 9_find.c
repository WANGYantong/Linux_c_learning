#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 10
#define NUM 3

int a[LEN];
int origin[LEN];

void initial(void);
void print(int array[]);
void backup(void);

void quick_sort(int start, int end);
int partition(int start, int end);
int order_statistic(int start, int end, int k);

int main(void)
{
	int result;

	initial();
	print(origin);
//Comparing, to see the result is correct or not
	backup();
	quick_sort(0, LEN - 1);
	printf("%d\n", a[NUM - 1]);

	backup();
	result = order_statistic(0, LEN - 1, NUM - 1);
	printf("%d\n", result);
	return 0;
}

void initial(void)
{
	int i;
	srand(time(NULL));
	for (i = 0; i < LEN; i++) {
		origin[i] = rand() % 100;
	}
}

void print(int array[])
{
	int i;
	for (i = 0; i < LEN; i++)
		printf("%d\t", array[i]);
	printf("\n");
}

void backup(void)
{
	int i;
	for (i = 0; i < LEN; i++) {
		a[i] = origin[i];
	}

}

void quick_sort(int start, int end)
{
	int mid;

	if (start < end) {
		mid = partition(start, end);
		quick_sort(start, mid - 1);
		quick_sort(mid + 1, end);
	}
}

int partition(int start, int end)
{
	int pivot;
	int i, j;
	int buffer;

	pivot = a[start];
	i = start;
	j = end;

	while (i != j) {
		while (a[j] >= pivot && j > i)
			j--;
		while (a[i] <= pivot && i < j)
			i++;
		if (i < j) {
			buffer = a[j];
			a[j] = a[i];
			a[i] = buffer;
		}
	}

	a[start] = a[i];
	a[i] = pivot;

	return i;
}

int order_statistic(int start, int end, int k)
{
	int i;

	i = partition(start, end);

	if (i == k)
		return a[i];
	else if (k > i)
		return order_statistic(i + 1, end, k);
	else
		return order_statistic(start, i, k);
}

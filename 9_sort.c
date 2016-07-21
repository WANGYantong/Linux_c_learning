#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 10

int a[LEN];

void initial(void);
void print(void);
void insertion_sort(void);
/* void quick_sort(int start, int end); */
/* void merge_sort(int start, int end); */

int main(void)
{
	initial();
	print();
	insertion_sort();
	print();

	return 0;
}

void initial(void)
{
	int i;
	srand(time(NULL));
	for (i = 0; i < LEN; i++)
		a[i] = rand() % 100;
}

void print(void)
{
	int i;
	for (i = 0; i < LEN; i++)
		printf("%d\t", a[i]);
	printf("\n");
}

void insertion_sort(void)
{
	int i, j, temp;
	for (j = 1; j < LEN; j++) {
		temp = a[j];
		for (i = j - 1; i >= 0 && a[i] > temp; i--) {
			a[i + 1] = a[i];
		}
		a[i + 1] = temp;
	}
}

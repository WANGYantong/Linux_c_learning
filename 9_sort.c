#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define LEN 1000
#define TAKE_TIME

int a[LEN];
int origin[LEN];

void initial(void);
void backup(void);
void print(int array[]);

void insertion_sort(void);

void quick_sort(int start, int end);
int partition(int start, int end);

void merge_sort(int start, int end, int temp[]);
void merge(int start, int mid, int end, int temp[]);

int main(void)
{
#ifdef TAKE_TIME
	struct timeval start1, end1, start2, end2, start3, end3;
	int interval1, interval2, interval3;
#endif
	int temp[LEN] = { 0 };

	initial();
	backup();
	/* print(origin); */

#ifdef TAKE_TIME
	gettimeofday(&start1, NULL);
#endif
	insertion_sort();
#ifdef TAKE_TIME
	gettimeofday(&end1, NULL);
	interval1 =
	    1000000 * (end1.tv_sec - start1.tv_sec) + (end1.tv_usec -
						       start1.tv_usec);
	printf("the time of insertion sort is %f\n", interval1 / 1000.0);
#endif
	/* printf("insertion_sort:\n"); */
	/* print(a); */

	backup();

#ifdef TAKE_TIME
	gettimeofday(&start2, NULL);
#endif
	merge_sort(0, LEN - 1, temp);
#ifdef TAKE_TIME
	gettimeofday(&end2, NULL);
	interval2 =
	    1000000 * (end2.tv_sec - start2.tv_sec) + (end2.tv_usec -
						       start2.tv_usec);
	printf("the time of merge sort is %f\n", interval2 / 1000.0);
#endif
	/* printf("merge_sort:\n"); */
	/* print(a); */

	backup();

#ifdef TAKE_TIME
	gettimeofday(&start3, NULL);
#endif
	quick_sort(0, LEN - 1);
#ifdef TAKE_TIME
	gettimeofday(&end3, NULL);
	interval3 =
	    1000000 * (end3.tv_sec - start3.tv_sec) + (end3.tv_usec -
						       start3.tv_usec);
	printf("the time of quick sort is %f\n", interval3 / 1000.0);
#endif
	/* printf("quick_sort:\n"); */
	/* print(a); */

	return 0;
}

void initial(void)
{
	int i;
	srand(time(NULL));
	for (i = 0; i < LEN; i++)
		origin[i] = rand() % 10000;
}

void backup(void)
{
	int i;
	for (i = 0; i < LEN; i++)
		a[i] = origin[i];
}

void print(int array[])
{
	int i;
	for (i = 0; i < LEN; i++)
		printf("%d\t", array[i]);
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


void merge_sort(int start, int end, int temp[])
{
	int mid;
	if (start < end) {
		mid = (start + end) / 2;
		merge_sort(start, mid, temp);
		merge_sort(mid + 1, end, temp);
		merge(start, mid, end, temp);
	}
}

void merge(int start, int mid, int end, int temp[])
{
	int i, j, k;
	int lenth1, lenth2;

	lenth1 = mid;
	lenth2 = end;
	i = start;
	j = mid + 1;
	k = start;

	while (i <= lenth1 && j <= lenth2) {
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	while (i <= lenth1)
		temp[k++] = a[i++];

	while (j <= lenth2)
		temp[k++] = a[j++];

	for (i = start; i <= end; i++)
		a[i] = temp[i];
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

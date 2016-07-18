
#include <stdio.h>

int to[50];
int from[50];
void send(int *to, int *from, int count);

int main(void)
{
	int i;
	int count;
	for (i = 0; i < 50; i++) {
		from[i] = i;
		to[i] = 0;
	}
	printf("\n\nplease input a number(must between 1 and 50):");
	scanf("%d", &count);
	send(to, from, count);
	printf("\nthe result is:\n");
	printf("Array to is:\n");
	for (i = 0; i < 50; i++) {
		printf("%d\t", to[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}

	return 0;
}

//Duff's device, see more on Wiki.
void send(int *to, int *from, int count)
{
	int n = (count + 7) / 8;
	switch (count % 8) {
	case 0:
		do {
			*to++ = *from++;
	case 7:
			*to++ = *from++;
	case 6:
			*to++ = *from++;
	case 5:
			*to++ = *from++;
	case 4:
			*to++ = *from++;
	case 3:
			*to++ = *from++;
	case 2:
			*to++ = *from++;
	case 1:
			*to++ = *from++;
		} while (--n > 0);
	}
}

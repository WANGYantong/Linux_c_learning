#include <stdio.h>

//find the greatest common divisor between a and b by using EUCLID
int gcb(int a, int b);

int main(void)
{
	int a, b;
	int buffer;
	int i = 1;
	while (i == 1) {
		printf
		    ("\n\nplease input two number,just like this: 25,40\n");
		scanf("%d,%d", &a, &b);

		if (a < b) {
			buffer = a;
			a = b;
			b = buffer;
		}

		buffer = gcb(a, b);
		printf
		    ("the greatest common divisor between %d and %d is %d\n",
		     a, b, buffer);

		printf("what do you want to do next?\n");
		printf("1.go on\t2.stop\n");
		scanf("%d", &i);
	}
	return 0;
}

int gcb(int a, int b)
{
	int i;
	if (a % b == 0)
		return b;
	else {
		i = a;
		a = b;
		b = i % b;
		return gcb(a, b);
	}
}

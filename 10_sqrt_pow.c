#include <stdio.h>
#include <math.h>


float mysqrt(float y, float precision);
float mypow(float x, int n);

int main(void)
{
	float num, precision = 0.001;
	int i = 1;
	int select, power;

	while (i == 1) {
		printf("\nwhat do you want to do?");
		printf("\n1,sqrt\t2,power\n");
		scanf("%d", &select);

		switch (select) {
		case (1):
			printf("\ninput a number:\n");
			scanf("%f", &num);
			printf("\nsqrt:%f\n", mysqrt(num, precision));
			break;
		case (2):
			printf("\ninput a number:\n");
			scanf("%f", &num);
			printf("\ninput a power:\n");
			scanf("%d", &power);
			printf("\npower:%f\n", mypow(num, power));
			break;
		default:
			break;
		}

		printf("what do you want to do next?");
		printf("\n1.go on\t2.stop\n");
		scanf("%d", &i);

	}
	return 0;
}

float mysqrt(float y, float precision)
{
	float start, mid, end;
	float buff;

	start = 0.0;
	end = y;

	while (1) {
		mid = (start + end) / 2;
		buff = mid * mid;
		if (fabs(buff - y) < precision)
			break;
		else if (buff < y)
			start = mid;
		else
			end = mid;
	}
	return mid;

}

float mypow(float x, int n)
{
	float result;

	if (n == 0)
		result = 1;
	if (n == 1)
		result = x;
	else if (n % 2 == 0)
		result = mypow(x, n / 2) * mypow(x, n / 2);
	else
		result = mypow(x, n - 1) * x;

	return result;
}

#include <stdio.h>
#include <math.h>


float mysqrt(float y, float precision);
/* float mypow(float x, int n); */

int main(void)
{
	float num, precision = 0.001;
	int i = 1;

	while (i == 1) {
		printf("\ninput a number:\n");
		scanf("%f", &num);
		printf("\nsqrt:%f\n", mysqrt(num, precision));

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

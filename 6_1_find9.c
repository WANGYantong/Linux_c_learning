
#include <stdio.h>

int main(void)
{
	int i, sum;
	int gewei, shiwei;
	i = 1;
	sum = 0;
	while (i < 100) {
		gewei = i % 10;
		if (i < 10)
			shiwei = 0;
		else
			shiwei = ((i - gewei) / 10) % 10;
		if (gewei == 9)
			sum += 1;
		if (shiwei == 9)
			sum += 1;
		i++;
	}
	printf("there are %d '9' between 1 and 100\n", sum);
	return 0;
}

#ifndef _7_2_RATIONAL
#define _7_2_RATIONAL

typedef struct rational_struct {
	int numerator;
	int denominator;
} RATIONAL_STRUCT;

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

RATIONAL_STRUCT reduction(RATIONAL_STRUCT z)
{
	int cd;			//cd is short for common divisor
	cd = gcb(z.numerator, z.denominator);
	z.numerator = z.numerator / cd;
	z.denominator = z.denominator / cd;
	return z;
}

RATIONAL_STRUCT add_rational(RATIONAL_STRUCT x, RATIONAL_STRUCT y)
{
	RATIONAL_STRUCT z;
	z.denominator = x.denominator * y.denominator;
	z.numerator =
	    x.numerator * y.denominator + x.denominator * y.numerator;
	z = reduction(z);
	return z;
}

RATIONAL_STRUCT sub_rational(RATIONAL_STRUCT x, RATIONAL_STRUCT y)
{
	RATIONAL_STRUCT z;
	z.denominator = x.denominator * y.denominator;
	z.numerator =
	    x.numerator * y.denominator - x.denominator * y.numerator;
	z = reduction(z);
	return z;
}

RATIONAL_STRUCT mul_rational(RATIONAL_STRUCT x, RATIONAL_STRUCT y)
{
	RATIONAL_STRUCT z;
	z.denominator = x.denominator * y.denominator;
	z.numerator = x.numerator * y.numerator;
	z = reduction(z);
	return z;
}

RATIONAL_STRUCT div_rational(RATIONAL_STRUCT x, RATIONAL_STRUCT y)
{
	RATIONAL_STRUCT z;
	z.denominator = x.denominator * y.numerator;
	z.numerator = x.numerator * y.denominator;
	z = reduction(z);
	return z;
}

void print_rational(RATIONAL_STRUCT z)
{
	printf("\nthe result is %d/%d\n", z.numerator, z.denominator);
}
#endif

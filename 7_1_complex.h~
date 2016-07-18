#ifndef _7_1_COMPLEX
#define _7_1_COMPLEX

#include <math.h>
enum coordinate_type {RECTANGULAR, POLAR};
typedef struct complex_struct
{
	enum coordinate_type t;
	double x;
	double y;
}COMPLEX_STRUCT;

COMPLEX_STRUCT make_from_real_img(double x,double y)
{
	COMPLEX_STRUCT z;
	z.t=RECTANGULAR;
	z.x=x;
	z.y=y;
	return z;	
}

COMPLEX_STRUCT make_from_mag_ang(double r,double angle)
{
	COMPLEX_STRUCT z;
	z.t=POLAR;
	z.x=r;
	z.y=angle;
	return z;	
}

double real_part(COMPLEX_STRUCT z)
{
	if(z.t==RECTANGULAR)
		return z.x;
	else
		return z.x*cos(z.y);
}

double ima_part(COMPLEX_STRUCT z)
{
	if(z.t==RECTANGULAR)
		return z.y;
	else
		return z.x*sin(z.y);
}

double magnitude(COMPLEX_STRUCT z)
{
	if(z.t==RECTANGULAR)
		return sqrt(z.x*z.x+z.y*z.y);
	else
		return z.x;
}

double angle(COMPLEX_STRUCT z)
{
	if(z.t==RECTANGULAR)
		return atan2(z.y,z.x);
	else
		return z.y;
}

COMPLEX_STRUCT add_complex(COMPLEX_STRUCT z1, COMPLEX_STRUCT z2)
{
	return make_from_real_img(real_part(z1)+real_part(z2),ima_part(z1)+ima_part(z2));
}

COMPLEX_STRUCT sub_complex(COMPLEX_STRUCT z1, COMPLEX_STRUCT z2)
{
	return make_from_real_img(real_part(z1)-real_part(z2),ima_part(z1)-ima_part(z2));
}

COMPLEX_STRUCT mul_complex(COMPLEX_STRUCT z1, COMPLEX_STRUCT z2)
{
	return make_from_mag_ang(magnitude(z1)*magnitude(z2),angle(z1)+angle(z2));
}

COMPLEX_STRUCT div_complex(COMPLEX_STRUCT z1, COMPLEX_STRUCT z2)
{
	return make_from_mag_ang(magnitude(z1)/magnitude(z2),angle(z1)-angle(z2));
}

void print_complex(COMPLEX_STRUCT z)
{
	double real,ima;
	real = real_part(z);
	ima  = ima_part(z);
	if(real==0 && ima==0)	printf("the result is ZERO.\n");
	else	if(real==0)	printf("the result is %fi\n",ima);
		else	if(ima==0)	printf("the result is %f\n",real);
		        else	if(ima>0)	printf("the result is %f+%fi\n",real,ima);
				else 		printf("the result is %f-%fi\n",real,-ima);

}
#endif

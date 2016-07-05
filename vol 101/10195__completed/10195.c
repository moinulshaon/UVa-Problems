#include <stdio.h>
#include <math.h>


int main()
{
	double a,b,c,s,area;

	while (scanf("%lf %lf %lf",&a,&b,&c)==3)
	{
		s=(a+b+c)/2;
		area=sqrt(s*(s-a)*(s-b)*(s-c));

		if (s==0)
			printf("The radius of the round table is: 0.000\n");
		else 
			printf("The radius of the round table is: %.3lf\n",area/s);

	}
	return 0;
}
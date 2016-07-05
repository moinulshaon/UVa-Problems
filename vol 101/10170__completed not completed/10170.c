#include <stdio.h>
#include <math.h>

int main()
{
	long s,d;
	double result;

	while (scanf("%ld %ld",&s,&d)==2)
	{
		result=(-1+sqrt(1-4*(s-s*s-2*d)))/2;
		printf("%.0lf\n",ceil(result));
	}
	return 0;
}
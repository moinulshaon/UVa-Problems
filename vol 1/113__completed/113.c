#include <stdio.h>
#include <math.h>

int main ()
{
	double k,n;
	while (scanf("%lf",&n)!=EOF)
	{
		scanf("%lf",&k);
		printf("%.0f\n",exp(log(k)/n));
	}
	return (0);
}
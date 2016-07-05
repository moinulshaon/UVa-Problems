#include <stdio.h>
#include <math.h>
double min(double a,double b)
{
	return (a<b)?a:b;
}
double func(double x,double y,double d)
{
	return 1/sqrt(x*x-d*d) + 1/sqrt(y*y-d*d);
}
int main()
{
	double recip,hi,lo,mid,x,y,c;
	while(scanf("%lf %lf %lf",&x,&y,&c)==3)
	{
		lo = 0;
		hi = min(x,y);
		recip = 1 / c;
		while(hi-lo>1e-4)
		{
			mid = (hi + lo) / 2;
			if(func(x,y,mid)<recip)
				lo = mid;
			else
				hi = mid;
		}
		printf("%.3lf\n",(hi+lo)/2);
	}
	return 0;
}

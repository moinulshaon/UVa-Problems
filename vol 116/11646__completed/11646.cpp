#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int i;
	long double x,y,theta,a,b,temp;

	for (i=1;scanf("%llf : %llf",&a,&b)==2;++i)
	{

		theta=atan(b/a);
		x=200/(1+theta*sqrt(1+(b*b)/(a*a)));
		y=b/a*x;
		printf("Case %d: %llf %llf\n",i,x,y);
	}

	return (0);
}

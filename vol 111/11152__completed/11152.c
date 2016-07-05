#include <stdio.h>
#include <math.h>

int main()
{
	double a,b,c,s,areaT,areaS,areaR,pi,temp;

	pi=2*acos(0);
	while (scanf("%lf %lf %lf",&a,&b,&c)==3)
	{
		s=(a+b+c)/2;
		areaT=sqrt(s*(s-a)*(s-b)*(s-c));

		temp=(a*b*c)/(4*areaT);
		areaS=pi*temp*temp-areaT;
		temp=areaT/s;
		areaR=temp*temp*pi;
		

		printf("%.4lf %.4lf %.4lf\n",areaS,areaT-areaR,areaR);

	}
	return (0);
}
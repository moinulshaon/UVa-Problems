#include <stdio.h>
#include <math.h>

int main()
{
	double a,b,s,m,n,vx,vy,angle,velocity,pi=acos(-1);

	while (1)
	{
		scanf("%lf %lf %lf %lf %lf",&a,&b,&s,&m,&n);
		if ( a==0 && b==0 && s==0 && m==0 && n==0)
			return 0;
		vy=n*b/s;
		vx=m*a/s;
		
		velocity=sqrt(vx*vx+vy*vy);
		if (vx!=0)
			angle=atan(vy/vx)*180/pi;
		else 
			angle=90;
		
		printf("%.2lf %.2lf\n",angle,velocity);
	}
}
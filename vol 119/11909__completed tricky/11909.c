#include <stdio.h>
#include <math.h>
int main()
{
		int l,w,h,theta;
		double result,temp,pi=acos(-1);

		while (scanf("%d %d %d %d",&l,&w,&h,&theta)==4)
		{
			if (l*tan(theta*pi/180)>h)
			{
				temp=cos(theta*pi/180)/sin(theta*pi/180);
				result=.5*h*h*w*temp;
			}
			else 
			{
				temp=.5*l*l*tan(theta*pi/180);
				result=(l*h-temp)*w;
			}
			printf("%.3lf mL\n",result);
		}
		return 0;
}
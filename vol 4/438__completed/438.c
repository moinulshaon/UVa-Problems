#include <stdio.h>
#include <math.h>

int main()
{
	long double a,b,c,area,x1,x2,x3,y1,y2,y3,s;

	while (scanf("%Lf %Lf %Lf %Lf %Lf %Lf",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF)
	{
		a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
		c=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));

		s=(a+b+c)/2;
		area=sqrt(s*(s-a)*(s-b)*(s-c));

		printf("%.2Lf\n",3.141592653589793*(a*b*c)/(2*area));
		
	}
	return (0);
}
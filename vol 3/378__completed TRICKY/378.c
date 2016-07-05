#include <stdio.h>
#include <math.h>
int main()
{
	double x1,y1,x2,y2,x3,y3,x4,y4,a1,a2,b1,b2,c1,c2,x,y,temp;
	int test;

	scanf("%d",&test);
	printf("INTERSECTING LINES OUTPUT\n");
	while (test--)
	{
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
		a1=y1-y2;
		b1=x2-x1;
		c1=(x1-x2)*y1-(y1-y2)*x1;
		a2=y3-y4;
		b2=x4-x3;
		c2=(x3-x4)*y3-(y3-y4)*x3;
		
		temp=a1*b2-a2*b1;
		if (temp==0 )
		{
			if (b1*c2-b2*c1==0  && a2*c1-a1*c2==0)
				printf("LINE\n");
			else 
				printf("NONE\n");
			continue;
		}
		x=(b1*c2-b2*c1)/temp;
		y=(a2*c1-a1*c2)/temp;

		printf("POINT %.2lf %.2lf\n",x,y);
		
	}
	printf("END OF OUTPUT\n");
	return (0);
}
#include <stdio.h>
#include <math.h>

int main()
{
	int totalhole,i,flag;
	double x1,y1,x2,y2,x,y,distance1,distance2;

	while (scanf("%d",&totalhole)!=EOF)
	{	
		flag=1;
		scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
		
		for (i=0;i<totalhole;++i)
		{
			scanf("%lf %lf",&x,&y);

			distance1=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
			distance2=sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2));

			if (distance2>=2*distance1 && flag)
			{
				printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",x,y);
				flag=0;
				
			}
		}
		if (flag)
			printf("The gopher cannot escape.\n");
	}
	return (0);
}
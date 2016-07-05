#include <stdio.h>

int main()
{
	float hour,minute,degree1,degree2,diff;

	while (1)
	{
		scanf("%f:%f",&hour,&minute);
		if (hour==0 && minute==0)
			break;
		degree1=hour*30+minute/60*30;
		degree2=minute*6;
		diff=degree1-degree2;
		if (diff<0)
			diff=-diff;
		if (diff>180)
			diff=360-diff;
		printf("%.3f\n",diff);
	}
	return (0);
}
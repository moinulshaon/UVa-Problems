#include <stdio.h>
#include <math.h>

int main()
{
	double s,degree,pi=acos(-1),result;
	char arr[5];

	while (scanf("%lf %lf %s",&s,&degree,arr)==3)
	{
		
		if (arr[0]=='m')
			degree/=60;

		if (degree>180)
			degree=360-degree;
		degree=degree*pi/180;


		

		result=degree*(6440+s);

		printf("%lf ",result);

		result=2*(s+6440)*sin(degree/2);

		printf("%lf\n",result);
		
	}
	return 0;


}
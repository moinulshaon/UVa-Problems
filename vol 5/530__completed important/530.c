#include <stdio.h>

int main()
{
	long double n,c,result,i;

	while (1)
	{
		result=1;
		scanf("%llf %llf",&n,&c);
		if (c>n/2)
			c=n-c;

		if (c==0 && n==0)
			break;
		if (c==0)
		{
			printf("1\n");
			continue;
		}
		for (i=1;i<=c;++i)
			result*=(n-c+i)/i;

		printf("%.0llf\n",result);

	}
	return (0);

}
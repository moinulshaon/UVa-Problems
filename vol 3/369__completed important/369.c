#include <stdio.h>

int main()
{
	long double n,c,result,i;
	int temp1,temp2;

	while (1)
	{
		result=1;
		scanf("%llf %llf",&n,&c);
		temp1=(int)n;
		temp2=(int)c;
		if (c>n/2)
			c=n-c;

		if (c==0 && n==0)
			break;
		if (c==0)
		{
			printf("%d things taken %d at a time is 1 exactly.\n",temp1,temp2);
			continue;
		}
		for (i=1;i<=c;++i)
			result*=(n-c+i)/i;

		printf("%d things taken %d at a time is %.0llf exactly.\n",temp1,temp2,result);

	}
	return (0);

}
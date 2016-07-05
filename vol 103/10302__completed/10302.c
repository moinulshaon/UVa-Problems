#include <stdio.h>

int main()
{
	unsigned  long long x,sum,i;

	while (scanf("%llu",&x)!=EOF)
	{
		sum=0;
		for (i=1;i<=x;++i)
			sum+=i*i*i;
		printf("%llu\n",sum);
	}
	return (0);
}
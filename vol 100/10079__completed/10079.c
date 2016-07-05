#include <stdio.h>
int main()
{
	long long int temp;
	unsigned long long int p;
	while (1)
	{
		scanf("%lli",&temp);
		if (temp<0)
			break;

		p=temp*(temp+1)/2;
		printf("%llu\n",p+1);
	}
	return 0;
}
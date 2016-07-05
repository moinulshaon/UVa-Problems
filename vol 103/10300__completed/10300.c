#include <stdio.h>

int main()
{
	unsigned long field,animal,ecology,sum;
	int test,farmerno;

	scanf("%d",&test);

	while (test--)
	{
		scanf("%d",&farmerno);
		sum=0;
		while (farmerno--)
		{
			scanf("%lu %lu %lu",&field,&animal,&ecology);

			sum+=field*ecology;
		}
		printf("%lu\n",sum);
	}
	return (0);
}
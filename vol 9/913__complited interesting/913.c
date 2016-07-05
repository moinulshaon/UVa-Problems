#include <stdio.h>

int main()
{
	unsigned   long long int number;
	unsigned int n;

	while (scanf("%lu",&n)!=EOF)
	{
		number=(n-1)*(n-1)/2+2*n-5;
		number+=2*number+6;
		printf("%llu\n",number);
	}
	return (0);
}
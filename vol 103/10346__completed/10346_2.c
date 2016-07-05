#include <stdio.h>

int main()
{
	long int n,k;

	while (scanf("%ld %ld",&n,&k)==2)
	{
		printf("%ld\n",n+(n-1)/(k-1));
	}
	return 0;
}
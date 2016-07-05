#include <stdio.h>

int primes[1000005];

int main()
{
	
	unsigned int i,n,j;

	for (i=2;i<1000005;++i)
		primes[i]=1;

	for (i=2;i<1000;++i)
		for (j=i*2;j<1000005;j+=i)
			primes[j]=0;

	while (1)
	{
		scanf("%u",&n);
		if (n==0)
			break;
		for (i=3;;++i)
		{
			if (primes[i] && primes[n-i])
			{
				printf("%u = %u + %u\n",n,i,n-i);
				break;
			}
		}
	}
	return (0);
}
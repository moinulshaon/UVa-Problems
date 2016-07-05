#include <stdio.h>

int main()
{
	unsigned number,i,j,count;
	int primes[32768];

	primes[0]=primes[1]=0;
	for (i=2;i<=32768;++i)
		primes[i]=1;
	for (i=2;i<=181;++i)
		for (j=2*i;j<=32768;j+=i)
			primes[j]=0;


	while (1)
	{
		count=0;
		scanf("%u",&number);
		if (number==0)
			break;
		for (i=2;i<=number/2;++i)
		{
			if (primes[i]+primes[number-i]==2)
				++count;
		}
		printf("%u\n",count);
		
	}
	return (0);
}
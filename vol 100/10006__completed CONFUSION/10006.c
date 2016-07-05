#include <stdio.h>

int main()
{
	/*unsigned int number;
	unsigned int i,j,flag;

	int primes[65001];
	primes[0]=primes[1]=0;
	for (i=2;i<=65000;++i)
		primes[i]=1;
	for (i=2;i<=254;++i)
		for (j=2*i;j<=65000;j+=i)
			primes[j]=0;

	for (number=2;number<=65000;++number)
	{

		
		if (number==0)
			break;
		if (primes[number])
		{
			printf("%ld is normal.\n",number);
			continue;
		}
		flag=0;
		for (i=2;i<number;++i)
		{
			if (in_mod_n(i,number)!=i)
			{
				flag=1;
				printf("%ld is normal.\n",number);
				break;
			}
		}
		if (!flag)
			printf("The number %u is a Carmichael number.\n",number);
		
	}
	return (0);*/

	unsigned number,i,flag;

	unsigned carmichaels[15]={561,1105,1729,2465,2821,6601,8911,10585,15841,29341,
					41041,46657,52633,62745,63973};

	while (1)
	{
		flag=0;
		scanf("%u",&number);
		if (!number)
			break;
		for (i=0;i<15;++i)
		{
			if (carmichaels[i]==number)
			{	
				flag=1;
				break;
			}
		}
		if (flag)
			printf("The number %u is a Carmichael number.\n",number);
		else
			printf("%u is normal.\n",number);
	}

	return (0);

}
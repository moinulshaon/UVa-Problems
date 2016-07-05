#include <stdio.h>
#include <math.h>
#define LONG long

char prime[1000001];
int i,j;

void div(LONG input)
{
	LONG temp=input,temp2=sqrt(input);
	for (i=2; input!=1  && i<=temp2;++i)
	{
		if (prime[i])
		{
			while (input%i==0)
			{
				input/=i;
				printf("    %4lld\n",i);
			}
		}
	}
	
	if (input!=1 )
		printf("    %lld\n",input);
}

int main()
{
	LONG  test;
	int k=0;

	for (i=2;i<1000001;++i)
		prime[i]=1;

	for (i=2;i<=1000;++i)
		if (prime[i])
			for (j=i*2;j<1000001;j+=i)
				prime[j]=0;
	
	while (1)
	{
		if (k)
			printf("\n");
		scanf("%lld",&test);
		div(test);
		//printf("Between %d and %d, %d has a maximum of %d divisors.\n",L,U,result,max);
		++k;
	}
	return 0;
}
#include <stdio.h>
#include <math.h>
#define LONG long long
char prime[10000001];
int i,j;

LONG largest(LONG input)
{
	LONG result=-1,count=0,temp=input,temp2=sqrt(input);
	for (i=2; input!=1  && i<=temp2;++i)
	{
		if (prime[i])
		{
			while (input%i==0)
			{
				input/=i;
				if (result!=i)
				{
					result=i;
					++count;
				}
			}
		}
	}
	
	if (input>temp2 && count)
		return input;
	else if (count<2)
		return -1;
	else
		return result;
}
int main()
{
	
	LONG input,result;

	for (i=0;i<10000001;++i)
		prime[i]=1;

	prime[0]=prime[1]=0;
	for (i=2;i<=3162;++i)
		if (prime[i])
			for (j=i*2;j<10000001;j+=i)
				prime[j]=0;

	while (1)
	{
		scanf("%lld",&input);
		if (!input)
			return 0;
		if (input<0)
			input=-input;

		result=largest(input);
		printf("%lld\n",result);
	}
}
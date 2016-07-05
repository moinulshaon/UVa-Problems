#include <stdio.h>
#include <math.h>

char prime[31623];
int i,j;

int div(int input)
{
	int result=1,count=0,temp=input,temp2=sqrt(input);
	for (i=2; input!=1  && i<=temp2;++i)
	{
		if (prime[i])
		{
			count=0;
			while (input%i==0)
			{
				input/=i;
				++count;
			}
			result*=(count+1);
		}
	}
	
	if (input>temp2)
		return result*2;
	else
		return result;
}

int main()
{
	int test,k;
	int L,U,result,max,temp;

	for (i=2;i<31623;++i)
		prime[i]=1;

	for (i=2;i<=177;++i)
		if (prime[i])
			for (j=i*2;j<31623;j+=i)
				prime[j]=0;
	scanf("%d",&test);
	while (test--)
	{
		scanf("%d %d",&L,&U);
		max=0;
		for (k=L;k<=U;++k)
		{
			temp=div(k);
			if (temp>max)
			{
				max=temp;
				result=k;
			}
		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n",L,U,result,max);
	}
	return 0;
}
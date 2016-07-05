#include <stdio.h>

char prime[1000001];
int result[1000001];

int main()
{
	int lower,higher,sum,i,j,dp=0,test,save=0;
	for (i=2;i<=1000000;++i)
		prime[i]=1;
	prime[0]=prime[1]=0;
	for (i=2;i<=1000;++i)
		if (prime[i])
			for (j=i*2;j<=1000000;j+=i)
				prime[j]=0;

	for (i=1;i<=1000000;++i)
	{
		result[i]=save;
		if (prime[i])
		{
			sum=0;
			j=i;
			while(j!=0)
			{
				sum+=j%10;
				j/=10;
			}
			if (prime[sum])
			{
				result[i]=save+=1;
			}
		}
	}
	
	scanf("%d",&test);
	while (test--)
	{
		scanf("%d %d",&lower,&higher);
		if (lower==higher)
		{
			if (result[lower]>result[lower-1])
				printf("1\n");
			else 
				printf("0\n");

		}
		else 
			printf("%d\n",result[higher]-result[lower-1]);

	}
	return 0;




}
#include <stdio.h>

char prime[1000001];
int result[1000001];


int final[115];
int main()
{
	register i,j;
	int prv=0,test,l,u,count,max=0,temp;
	for (i=2;i<1000001;++i)
		prime[i]=1;
	for (i=2;i<=1000;++i)
		if (prime[i])
			for (j=i*2;j<1000001;j+=i)
				prime[j]=0;

	for (i=2;i<1000001;++i)
	{
		if (prime[i])
		{
			result[i]=i-prv;
			prv=i;
		}
	}

	scanf("%d",&test);

	while (test--)
	{
		scanf("%d %d",&l,&u);
		count=max=0;
		for (i=0;i<115;++i)
			final[i]=0;
		for (i=l;i<=u;++i)
		{
			if (result[i] && count)
				++final[result[i]];
				
			if (result[i])
				count=1;
		}
		count=0;
		for (i=0;i<115;++i)
			if (final[i]>max)
			{
				max=final[i];
				temp=i;
			}
		for (i=0;i<115;++i)
		{
			if (final[i]==max)
				++count;
		}
		if (max==0 || count>1)
			printf("No jumping champion\n");
		else
			printf("The jumping champion is %d\n",temp);

	}
	
	return 0;

}
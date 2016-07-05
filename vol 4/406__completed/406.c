#include <stdio.h>

int main()
{
	int primes[1001],i,j,count,n,c,arr[1001],center;

	for (i=0;i<1001;++i)
		primes[i]=1;
	primes[0]=0;
	for (i=2;i<=31;++i)
		if (primes[i])
			for (j=i*2;j<1001;j+=i)
				primes[j]=0;

	for (j=0;scanf("%d %d",&n,&c)==2;++j)
	{
		printf("%d %d:",n,c);
		count=0;
		for (i=1;i<=n;++i)
			if (primes[i])
				arr[count++]=i;
		
		if (count%2)
		{
			center=count/2;
			

			if (center-c+1>=0)
			{
				for (i=center-c+1;i<=center+c-1;++i)
					printf(" %d",arr[i]);
			}
			else
			{
				for (i=0;i<count;++i)
					printf(" %d",arr[i]);
			}
		}
		else 
		{
			center =count/2;

			if (center-c>=0)
			{
				for (i=center-c;i<center+c;++i)
					printf(" %d",arr[i]);
			}
			else
			{
				for (i=0;i<count;++i)
					printf(" %d",arr[i]);
			}

		}
		printf("\n\n");
	}
	return (0);
		
}
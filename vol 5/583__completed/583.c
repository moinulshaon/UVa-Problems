#include <stdio.h>
#include <math.h>
#define size 46340

char prime[size];
int main()
{
	int i,j;
	int temp,number,k;

	temp=(int)sqrt(size);

	for (i=1;i<size;++i)
		prime[i]=1;

	for (i=2;i<=temp;++i)
		if (prime[i])
			for (j=i*2;j<size;j+=i)
				prime[j]=0;

	while (1)
	{
		scanf("%d",&number);
		if (number==0)
			return 0;
		if (number<0)
		{
			if (number!=-1)
				printf("%d = -1 x",number);
			else
			{
				printf("-1 = -1\n");
				continue;
			}
			number=-number;
		}
		else
			printf("%d =",number);

		j=i=2;
		k=1;
		while (number!=1)
		{
			temp=(int)sqrt(number);
			if (i>temp)
			{
				printf(" %d\n",number);
				break;
			}
			for (i=j;i<=temp;i+=k)
			{	
				if (prime[i] && number%i==0)
				{
					number/=i;
					if (number!=1)
						printf(" %d x",i);
					else
						printf(" %d\n",i);
					break;
				}
			}	
			if (i!=2)
				k=2;
			j=i;

		}
	}

}


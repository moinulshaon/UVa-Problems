#include <stdio.h>
#include <math.h>

char prime[1001];
int i,j;

int div(int input)
{
	int result=0,temp2=(int)sqrt(input);
	for (i=2; input!=1  && i<=temp2;++i)
	{
		if (prime[i] && input%i==0)
		{
			while (input%i==0)
			{
				input/=i;
			}
			++result;
		}
	}
	
	if (input>temp2)
		return result+1;
	else 
		return result; 
}

int main()
{
	int input;

	for (i=2;i<1001;++i)
		prime[i]=1;

	for (i=2;i<=31;++i)
		if (prime[i])
			for (j=i*2;j<1001;j+=i)
				prime[j]=0;
	
			
	while (1)
	{
		scanf("%d",&input);
		if (!input)
			return 0;
		printf("%d : %d\n",input,div(input));
	}
	return 0;
}
#include <stdio.h>
#include <math.h>

char prime[1000001];
int square[1000001];
long long result[1000001];



int main()
{
	
	int i,j,input;

    int temp;

	freopen("input.txt","r",stdin);
	for (i=2;i<1000001;++i)
		prime[i]=1;

	for (i=2;i<=1000;++i)
		if (prime[i])
			for (j=i*2;j<1000001;j+=i)
				prime[j]=0;

	for (i=2;i<1001;++i)
		if (prime[i])
			for (j=1;( temp=(int)pow(i,j) )<1000001;++j)
				square[temp]=i;


	result[1]=1;

	for (i=2;i<1000001;++i)
	{
		if (square[i])
			result[i]=result[i-1]*square[i];
		else if (prime[i])
			result[i]=result[i-1]*i;
        else
            result[i]=result[i-1];
		while (result[i]%10==0)
			result[i]/=10;
		result[i]%=10000000;

	}

	while (1)
	{
	    scanf("%d",&input);
	    if (!input)return 0;
        printf("%lld\n",result[input]%10);
	}

}

#include <stdio.h>
#define size 30000



int main()
{
	int i,j;
	int input;
	long long  dp[size+5]={1};
	int	coin[5]={1,5,10,25,50};



	for (i=0;i<5;++i)
		for (j=0;j<=size;++j)
			if (j-coin[i]>=0)
				dp[j]+=dp[j-coin[i]];

	while (scanf("%d",&input)==1)
	{
		if (dp[input]!=1)
            printf("There are %lld ways to produce %d cents change.\n",dp[input],input);
        else
            printf("There is only 1 way to produce %d cents change.\n",input);
	}
	return 0;
}

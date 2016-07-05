#include <stdio.h>
#define size 6000



int main()
{
	register i,j;
	int cent;
	double input;
	double dp[size+11]={1};
	int	coin[11]={1,2,4,10,20,40,100,200,400,1000,2000};


	
	for (i=0;i<11;++i)
		for (j=0;j<=size;++j)
			if (j-coin[i]>=0)
				dp[j]+=dp[j-coin[i]];

	while (1)
	{
		scanf("%lf",&input);
		if (input==0)
			return 0;
		cent=(int)(input*20);
		printf("%6.2lf%17.0lf\n",input,dp[cent]);
	}
}
#include <stdio.h>
#include <math.h>

int gcd(int m,int n)
{
	int temp;
	if (n>m)
		n^=m^=n^=m;
	while (n!=0)
	{
		temp=n;
		n=m%n;
		m=temp;
	}
	return (temp);
}

int main()
{
	int numbers[10000],i,j,count,pair,test;
	double result;


	while (scanf("%d",&test)==1)
	{
		if (test==0)
			return (0);
		count=pair=0;
		for (i=0;i<test;++i)
			scanf("%d",&numbers[i]);
		for (i=0;i<test;++i)
		{
			for (j=i+1;j<test;++j)
			{
				if (gcd(numbers[i],numbers[j])==1)
					++count;
				++pair;
			}
		}
		if (count)
		{
			result=sqrt(6*(double)pair/count);
			printf("%lf\n",result);
		}
		else 
			printf("No estimate for this data set.\n");
		
	}
	return (0);
}
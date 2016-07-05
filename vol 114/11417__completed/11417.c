#include <stdio.h>

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
	register i,j;
	int result,k;

	while (1)
	{
		scanf("%d",&k);
		if (!k)
			return 0;
		else
		{
			result=0;
			for (i=1;i<k;++i)
				for (j=i+1;j<=k;++j)
					result+=gcd(i,j);

			printf("%d\n",result);
		}
	}
	
}
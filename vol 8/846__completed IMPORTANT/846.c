#include <stdio.h>

int main()
{
	unsigned long int x,y,diff,sum;
	int n,i,m,j,step;

	scanf("%d",&n);

	for (i=0;i<n;++i)
	{
		sum=0;
		scanf("%lu %lu",&x,&y);
		diff=y-x;

		m=0;
		step=0;
		for (j=0;sum<diff;++j)
		{
			if (j%2==0)
				++m;
			sum+=m;
			++step;
		}
		printf("%d\n",step);
	}
	return (0);
}
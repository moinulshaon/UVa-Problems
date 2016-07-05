#include <stdio.h>

int main()
{
	long n,m,ns[1000000],i,count,j,temp;

	while (1)
	{
		scanf("%ld %ld",&n,&m);

		if (n==0 && m==0)
			break;
		for (i=0;i<n;++i)
			scanf("%ld",&ns[i]);

		count=j=0;

		for (i=0;i<m;++i)
		{
			scanf("%ld",&temp);
			for (;j<n;++j)
			{
				if (temp==ns[j])
				{
					++count;
					++j;
					break;
				}
				else if (ns[j]>temp)
					break;
			}
		}
		printf("%ld\n",count);

	}
	return (0);
}
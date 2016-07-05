#include <stdio.h>
#include <math.h>

int main()
{
	int n,arr[3001],diff[3001],sum,i,j,flag;

	while (scanf("%d",&n)!=EOF)
	{
		sum=0;
		flag=1;
		for (i=0;i<n;++i)
		{
			scanf("%d",&arr[i]);
		}
		for (i=0;i<n-1;++i)
		{
			diff[i]=abs(arr[i]-arr[i+1]);
			
			for (j=0;j<i;++j)
			{
				if (diff[i]==diff[j])
				{
					flag=0;
					break;
				}
			}
			if (!flag)
				break;

		}
		if (!flag)
		{
			printf("Not jolly\n");
			continue;
		}
		for (i=0;i<n-1;++i)
		{
			sum+=diff[i];
		}
		if (sum==n*(n-1)/2)
			printf("Jolly\n");
		else
			printf("Not jolly\n");

			
	}
	return (0);

}
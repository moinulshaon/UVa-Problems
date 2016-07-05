#include <stdio.h>

int arr[10001],sum[10001];
int main()
{
	register i;
	int j,marble,query,temp;

	for (j=1;;++j)
	{
		scanf("%d %d",&marble,&query);
		if (!marble && !query)
			return 0;
		for (i=0;i<=10000;++i)
			arr[i]=sum[i]=0;
		for (i=0;i<marble;++i)
		{
			scanf("%d",&temp);
			++arr[temp];
		}

		temp=1;
		for (i=0;i<=10000;++i)
		{
			if (arr[i])
			{
				sum[i]+=temp;
				temp+=arr[i];
			}
		}
		printf("CASE# %d:\n",j);
		for (i=0;i<query;++i)
		{
			scanf("%d",&temp);
			if (arr[temp])
				printf("%d found at %d\n",temp,sum[temp]);
			else
				printf("%d not found\n",temp);
		}
	}
}
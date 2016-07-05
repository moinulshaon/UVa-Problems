#include <stdio.h>

int main()
{
	int arr[50];
	int n,i,sum,k,flag;
	for (k=1;;++k)
	{
		sum=0;
		scanf("%d",&n);
		if (n==0)
			break;
		for (i=0;i<n;++i)
		{
			scanf("%d",&arr[i]);
			sum+=arr[i];
		}
		sum/=n;
		flag=0;

		for (i=0;i<n;++i)
		{
			if (arr[i]>sum)
				flag+=arr[i]-sum;
			else if (arr[i]<sum)
				flag+=sum-arr[i];
		}
		printf("Set #%d\n",k);
		printf("The minimum number of moves is %d.\n",flag/2);
		printf("\n");

	}
	return (0);
}
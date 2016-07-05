#include <stdio.h>

int main()
{
	int n1,n2,i,j,count;
	int arr[1001];
	float sum;

	scanf("%d",&n1);

	for (i=0;i<n1;++i)
	{
		sum=0;
		count=0;
		scanf("%d",&n2);
		for (j=0;j<n2;++j)
		{
			scanf("%d",&arr[j]);
			sum+=arr[j];
		}
		sum/=n2;
		for (j=0;j<n2;++j)
		{
			if (arr[j]>sum)
				++count;
		}
		printf("%.3f%%\n",(float)count*100/n2);
	}
	return (0);
	

}
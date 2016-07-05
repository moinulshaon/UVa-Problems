#include <stdio.h>


int main()
{
	int arr[52];
	int n,i,L,j,count,temp,x;
	scanf("%d",&n);
	for (i=0;i<n;++i)
	{
		count=0;
		scanf("%d",&L);
		for (j=0;j<L;++j)
			scanf("%d",&arr[j]);
		while (1)
		{	
			x=count;
			for(j=0;j<L-1;++j)
			{
				if (arr[j]>arr[j+1])
				{
					temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
					++count;
				}
			}
			if (x==count)
			{
				printf("Optimal train swapping takes %d swaps.\n",count);
				break;
			}

		}
	}
	return (0);
}
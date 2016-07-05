#include <stdio.h>

int main()
{
	int i,j,arr1[13],arr2[12];


	for (j=1;;++j)
	{
		scanf("%d",&arr1[0]);
		if (arr1[0]<0)
			return 0;
		for (i=1;i<13;++i)
			scanf("%d",&arr1[i]);
		for (i=0;i<12;++i)
			scanf("%d",&arr2[i]);
		printf("Case %d:\n",j);
		for (i=0;i<12;++i)
		{
			if (arr1[i]>=arr2[i])
			{
				printf("No problem! :D\n");
				arr1[i+1]+=arr1[i]-arr2[i];
			}
			else
			{
				printf("No problem. :(\n");
				arr1[i+1]+=arr1[i];
			}
		}

	}
}
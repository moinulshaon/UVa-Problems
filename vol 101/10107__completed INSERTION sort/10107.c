#include <stdio.h>

int main()
{
	register i,j;
	int arr[10001];

	scanf("%d",&arr[0]);
	printf("%d\n",arr[0]);

	for (i=1;scanf("%d",&arr[i])==1;++i)
	{
		for (j=i;j>0 && arr[j]<arr[j-1];--j)
			arr[j]^=arr[j-1]^=arr[j]^=arr[j-1];

		if (i & 1)
			printf("%d\n",(arr[i/2]+arr[i/2+1])/2);	
		else
			printf("%d\n",arr[i/2]);
	
	}
	return 0;
}
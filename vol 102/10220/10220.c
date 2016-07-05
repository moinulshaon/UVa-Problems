#include <stdio.h>


int result[1001];
int arr[10000001];
int main()
{
	int i,j,temp;
	arr[0]=1;
	for (i=1;i<10;++i)
	{
		for (j=100;j>=0;--j)
		{
			temp=0;
			arr[j]*=i;
			while (arr[j]>9)
			{
				arr[j+(++temp)]+=arr[j]/10;
				arr[j]%=10;
			}
		}
		for (j=0;j<101;++j)
			result[i]+=arr[j];
		for (j=0;j<101;++j)
		{
			printf("%d ",arr[j]);
		}
		printf("\n");
		getchar();
	}


	for (i=1;i<10;++i)
		printf("%d\n",result[i]);
	
}
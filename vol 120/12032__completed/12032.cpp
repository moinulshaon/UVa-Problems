#include <stdio.h>


int arr[100005];

int main()
{
	int max,test,k,i,j,stair,temp;
	char flag;

    arr[0]=0;
	scanf("%d",&test);

	for (k=1;k<=test;++k){
		scanf("%d",&stair);

		max=arr[0];


		for (i=1;i<=stair;++i)
		{
			scanf("%d",&arr[i]);

            temp=arr[i]-arr[i-1];


			if (temp>max)
				max=temp;
		}

		while(1)
		{
			temp=max;
			flag=1;
			for (j=1;j<=stair;++j)
			{
				if (arr[j]-arr[j-1]>temp)
				{
					flag=0;
				}
				else if (arr[j]-arr[j-1]==temp)
					--temp;
			}
			if (flag)
				break;
			++max;
		}

		printf("Case %d: %d\n",k,max);
	}
	return 0;

}

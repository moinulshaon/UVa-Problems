#include <stdio.h>

int main()
{
	int height[10001]={0};
	int i,L,M,R,flag=1;
	for (i=0;i<=10000;++i)
		height[i]=0;
    freopen("input.txt","r",stdin);
	while(scanf("%d %d %d",&L,&M,&R)==3)
	{
		for (i=L;i<R;++i)
			if (M>height[i])
				height[i]=M;
	}


	for (i=0;i<=10000;++i)
	{

		if (height[i]!=height[i-1])
		{
			if (flag && height[i])
			{
				printf("%d %d",i,height[i]);
				flag=0;
			}
			else if (!flag)
                printf(" %d %d",i,height[i]);

		}
	}
	printf("\n");
	return (0);
}

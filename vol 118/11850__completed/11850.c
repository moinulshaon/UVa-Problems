#include <stdio.h>

int main()
{
	int arr[1423],i,next,pos,test,j;

	while (1)
	{
		scanf("%d",&test);
		if (test==0)return 0;

		for (i=0;i<1423;++i)
			arr[i]=0;
		while (test--)
		{
			scanf("%d",&pos);
			arr[pos]=1;
		}
		next=200;
		for (i=1;i<=1422 && i<=next;++i)
		{
			if (arr[i])
			{
				next=i+200;
			}
		}
	
		next=2*1422-next;
		for (j=1422;j>=0 && j>=next;--j)
		{
			if (arr[j])
			{
				next=j-200;
			}
		}
		if (j==-1 && i==1423)
			printf("POSSIBLE\n");
		else 
			printf("IMPOSSIBLE\n");
	}
	
}
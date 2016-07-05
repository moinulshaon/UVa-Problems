#include <stdio.h>

int main()
{
	int n,days,politicsno,parameter[102],i,j,count,k;
	scanf("%d",&n);
	for (k=0;k<n;++k)
	{
		count=0;
		scanf("%d",&days);
		scanf("%d",&politicsno);
		for (i=1;i<=politicsno;++i)
			scanf("%d",&parameter[i]);
		for (i=1;i<=days;++i)
		{
			if (i%7==0 ||(i+1)%7==0)
				continue;
			for (j=1;j<=politicsno;++j)
			{
				if (i%parameter[j]==0)
				{
					++count;
					break;
				}
			}
		}
		printf("%d\n",count);
	}
	return (0);
}
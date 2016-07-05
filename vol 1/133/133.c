#include <stdio.h>

int main()
{
	int arr[20];
	int k,m,len,i,j,x,flag;

	while (1)
	{
		scanf("%d %d %d",&len,&k,&m);
		if (k==0 && m==0 && len==0)
			break;
		for (i=0;i<len;++i)
			arr[i]=i;
		i=x=j=0;
		while (1)
		{			
			flag=1;
			for (x=0;x<len;++x)
				if (arr[x]!=-1)
				{
					flag=0;
					break;
				}
			if (flag)
				break;
			
			while (i<k-1)
			{
				if (arr[i]==-1)
					continue;
				else
					++i;
				if (i==len)
					i=0;
			}
			
			while (j<m-1)
			{
				if (arr[len-j-1]==-1)
					continue;
				else
					++j;
			}
			if (arr[i]==arr[len-j-1])
			{
				printf("%3d\n",arr[i]);
				arr[i]=-1;
			}
			else
			{
				printf("%3d%3d\n",arr[i],arr[len-j-1]);
				arr[i]=arr[len-j-1]=-1;
			}
			getchar();
		}
	}
}
#include <stdio.h>


char arr[1000001];
int result[1000001];
int main()
{
	int i,m,temp,test,l,u;

	freopen ("input.txt","r",stdin);
	for(m=1;scanf("%s",arr)!=EOF;++m)
	{
		temp=0;
		for (i=0;arr[i]!='\0';++i)
		{
			if (arr[i]=='1')
				++temp;
			result[i+1]=temp;
		}

		printf("Case %d:\n",m);
		scanf("%d",&test);
		//getchar();
		while (test--)
		{
			scanf("%d %d",&l,&u);
			//getchar();
			if (l>u)
				l^=u^=l^=u;
			if (result[u]-result[l-1]==0 || result[u]-result[l-1]==u-l+1)
				printf("Yes\n");
			else
				printf("No\n");
		}

	}
	return 0;
}
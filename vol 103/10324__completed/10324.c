#include <stdio.h>
#include <string.h>


char arr[1000000];
int check(int i,int j)
{
	for (;i<=j;++i)
		if (arr[i]!=arr[j])
			return (0);
	return (1);
}

int main()
{
	
	int n,i,j,m,temp;

	freopen ("input.txt","r",stdin);
	for(m=1;scanf("%s",arr)!=EOF;++m)
	{
		if (strlen(arr)==0)
			break;
		scanf("%d",&n);
		printf("Case %d:\n",m);
		while(n--)
		{
			scanf("%d %d",&i,&j);
			if(i>j)
				i^=j^=i^=j;

			if(check(i,j))
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return (0);
}
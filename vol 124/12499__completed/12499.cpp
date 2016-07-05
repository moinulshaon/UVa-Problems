#include <cstdio>


using namespace std;

int aray[55];


int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("file.txt","w",stdout);
	int t;
	int n,l;
	scanf("%d",&t);
	for(int cas=0;cas<t;cas++)
	{
		scanf("%d %d",&n,&l);
		for(int i=0;i<n;i++)
			scanf("%d",&aray[i]);
		for(int i=0;i<n-1;i++)
			aray[i]=aray[i+1]-aray[i];
		aray[n-1]=l-aray[n-1];
		unsigned res=0;
		for(int i=0;i<n;i++)
		{
			if(i%2==0)
				res^=(unsigned)aray[i];
		}
		if(res)
			printf("Case %d: First Player\n",cas+1);
		else
			printf("Case %d: Second Player\n",cas+1);

	}
    return 0;
}

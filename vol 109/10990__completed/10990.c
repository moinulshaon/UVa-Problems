#include <stdio.h>



int phi[2000001];
char prime[2000001];

int depth[2000001];


int main()
{

	int i,j,test,a,b;

	//freopen("input.txt","r",stdin);

	for (i=1;i<2000001;++i)
		phi[i]=i;

	for (i=2;i<=2000000;++i)
		if (prime[i]==0)
		{
			phi[i]=phi[i]/i*(i-1);
			for (j=i*2;j<2000001;j+=i)
			{
				prime[j]=1;
				phi[j]=phi[j]/i*(i-1);
			}

		}

	for (i=2;i<2000001;++i)
		depth[i]=1+depth[phi[i]];



	for (i=1;i<2000001;++i)
		depth[i]+=depth[i-1];

	scanf("%d",&test);

	while (test--)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",depth[b]-depth[a-1]);
	}
	return 0;


}

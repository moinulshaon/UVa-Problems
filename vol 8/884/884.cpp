#include <cstdio>
#include <cmath>
#define N 1000001

using namespace std;

int factors[N];
int main()
{
	register int i,j,k;
	int  n;
	for(i=0;i<N;i++)
		factors[i] = 0;
	for(i=2;i<N/2;i++)
	{
		if(!factors[i])
			factors[i] = 1;
		for(j=2;j<=i&&(k = j*i)<N;j++)
			if(!factors[k]&&factors[j]==1)
					factors[k] = factors[i]+1;
	}
	for(i=N/2;i<N;i++)
		if(!factors[i])
			factors[i]=1;
	for(i=2;i<N;i++)
		factors[i] += factors[i-1];
	while(scanf("%d",&n)==1)
		printf("%d\n",factors[n]);
	return 0;
}

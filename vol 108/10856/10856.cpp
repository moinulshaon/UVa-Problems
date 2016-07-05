#include <cstdio>
#include <cmath>
#define N 2703666

using namespace std;

int factors[N];
int main()
{

    freopen("in.txt","r",stdin);

	register int i,j,k;
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
    int  n;
	for(k=1;;++k)
	{
	    scanf("%d",&n);
	    if (n<0)return 0;
        for (i=0;factors[i]<n;++i)
        ;
        if (factors[i]==n)
            printf("Case %d: %d!\n",k,i);
        else
            printf("Case %d: Not possible.\n",k);
	}
	return 0;
}

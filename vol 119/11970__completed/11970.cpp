#include <cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int T;
    cin>>T;
    long long N,x,s;
    for(int j=1;j<=T;j++)
    {
        scanf("%lld",&N);
        long rt=sqrt(N-1);

        printf("Case %d:",j);
        for(long i=rt;i>=1;i--)
        {
            s=i*i;
            x=N-s;
            if(x%i==0)
                printf(" %lld",x);

        }
        printf("\n");
    }
    return 0;
}

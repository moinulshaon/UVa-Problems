#include <cstdio>
#include <cmath>
#include <algorithm>
#define sz 10001
#define INF 10000000

using namespace std;
int dp[sz];

int main()
{
    for (int i=0;i<sz;++i)
        dp[i]= INF;
    dp[0]=0;
    for (int j=1;j<=100;++j)
        for (int i=0;i<sz;++i)
            if (i-j*j >=0)
                dp[i]=min(dp[i],dp[ i- j*j ]+1 );
    int kase,in;
    scanf("%d",&kase);
    while (kase--)
    {
        scanf("%d",&in);
        printf("%d\n",dp[in]);
    }
    return 0;

}

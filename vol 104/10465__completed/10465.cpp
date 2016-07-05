#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[10100];
int m,n;

int main()
{
    int t;
    while (scanf("%d %d %d",&n,&m,&t)==3)
    {
        memset(dp,0,sizeof(dp));

        dp[0]=1;
        for (int i=0;i<=t;++i)
        {
            if (i-n>=0  && dp[i-n])
                dp[i]=max(dp[i],1+dp[i-n]);
            if (i-m>=0 && dp[i-m])
                dp[i]=max(dp[i],1+dp[i-m]);
        }
        int tt;
        for (tt=t;tt>=0;--tt)
            if (dp[tt])
                break;
        if (t-tt)
            printf("%d %d\n",dp[tt]-1,t-tt);
        else
            printf("%d\n",dp[tt]-1);
    }
    return 0;
}

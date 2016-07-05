#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int price[1010],weight[1010];
int dp[1010][110];
int cap;
int object;

int main()
{
    freopen("in.txt","r",stdin);

    int kase;
    scanf("%d",&kase);
    while (kase--)
    {
        scanf("%d",&object);

        for (int i=0;i<object;++i)
            scanf("%d %d",&price[i],&weight[i]);

        memset(dp,0,sizeof(dp));

        dp[0][0]=1;
        for (int j=0;j<object;++j)
        for (int i=1010;i>=0;--i)
        dp[i][j]+=

        int person;
        scanf("%d",&person);

        int ans=0;
        while (person--)
        {
            memset(dp,-1,sizeof(dp));
            scanf("%d",&cap);
            ans+=func(0,0);
        }
        printf("%d\n",ans);

    }
    return 0;
}

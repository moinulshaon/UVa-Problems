#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int price[1010],weight[1010];
int dp[1010][110];
int cap;
int object;

int func(int taken,int w)
{
    if (taken==object)return 0;
    else if (dp[taken][w]!=-1)return dp[taken][w];
    else
    {
        int p1;
        if (w+weight[taken]<=cap)
            p1=price[taken]+func(taken+1,w+weight[taken]);
        else
            p1=0;
        int p2=func(taken+1,w);
        return dp[taken][w]=max(p1,p2);
    }
}

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

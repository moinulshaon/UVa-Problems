#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define INF 1000000000

using namespace std;

int dp[90100];
int coin[50][2];
bool vis[90100];
int totalcoin;

int func(int n){

    if (!vis[n]){
        for (int i=0;i<totalcoin;++i)
            if ( n-coin[i][0]- coin[i][1] >=0 ){
                double tmp=n/sqrt(coin[i][0]+coin[i][1]);
                if ( tmp-floor(tmp)<1e-6 ){
                    dp[n]=min( dp[n] , 1+func( n-coin[i][0]-coin[i][1] ) );
                }
            }
    }
    vis[n]=true;
    return dp[n];
}

int main()
{
    freopen("in.txt","r",stdin);

    int kase,destination;
    scanf("%d",&kase);

    while (kase--)
    {
        scanf("%d %d",&totalcoin,&destination);

        destination*=destination;
        for (int i=1;i<=destination;++i)
            dp[i]=INF;
        dp[0]=0;
        memset(vis,false,sizeof(vis));
        vis[0]=true;
        for (int i=0;i<totalcoin;++i){
            scanf("%d %d",&coin[i][0],&coin[i][1]);
            coin[i][0]*=coin[i][0];
            coin[i][1]*=coin[i][1];
        }


        if (func(destination)==INF)
            printf("not possible\n");
        else
            printf("%d\n",func(destination));
    }
    return 0;
}

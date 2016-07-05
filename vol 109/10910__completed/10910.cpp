#include <cstdio>
#include <algorithm>

#define sz 72

using namespace std;

int dp[sz][sz][sz];

int p;

int DFS( int n,int t ){
    //printf("%d %d\n",n,t);
    if (t<0)return 0;
    if (n==1 && t>=p )return dp[n][t][p]=1;

    if (dp[n][t][p]!=-1)return dp[n][t][p];

    if (n*p>t)return dp[n][t][p]=0;
    int sum=0,tmp;
    for (int i=p ; tmp=DFS( n-1, t-i );++i)
        sum+=tmp;
    return dp[n][t][p]=sum;
}

int main(){
    freopen("in.txt","r",stdin);

    for (int i=0;i<sz;++i)
        for (int j=0;j<sz;++j)
            for (int k=0;k<sz;++k)
                dp[i][j][k]=-1;

    int kase,n,t;
    scanf("%d",&kase);

    while (kase--){
        scanf("%d %d %d",&n,&t,&p);

        printf("%d\n",DFS( n,t ));

    }
    return 0;


}

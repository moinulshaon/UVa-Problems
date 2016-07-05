#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define sz 1100

using namespace std;

vector<int> outarrow[sz];
bool vis[sz][2];

int dp[sz][2];

int DFS(int n,int on,int prvnode){


    if (vis[n][on]){
        return dp[n][on];
    }

    int mn;
    if (on){
        mn=0;
        int tt=0,tt2=0;
        for (int i=0;i<outarrow[n].size();++i){

            if (outarrow[n][i] !=prvnode){
                tt+= DFS( outarrow[n][i] ,1,n );
                tt2+= DFS( outarrow[n][i] ,0  ,n) ;
            }
        }
        if (tt<tt2)
            mn+= 1+tt;
        else
            mn+=tt2;

    }
    else{
        mn=1;
        for (int i=0;i<outarrow[n].size();++i){
            if (outarrow[n][i] !=prvnode)
                mn+= DFS( outarrow[n][i] ,1 ,n)  ;
        }
    }
    vis[n][on]=true;
    return dp[n][on]=mn;

}






int main()
{
    int m,n,tx,ty,a,b,ans,total;

    freopen("in.txt","r",stdin);

    while (scanf("%d",&total)==1 && total){

        memset(dp,false,sizeof(dp));
        memset(vis,false,sizeof(vis));

        for (int i=0;i<=total;++i){
            outarrow[i].clear();
        }

        for (int i=1;i<=total;++i){
            scanf("%d",&m);

            while (m--)
            {
                scanf("%d",&a);
                outarrow[i].push_back(a);
            }
        }

        int tmp=DFS( 1 ,1 ,-1);
        ans=(tmp==0)?1:tmp;

        printf("%d\n",ans);
    }
    return 0;

}

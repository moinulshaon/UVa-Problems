#include <cstdio>
#include <cstring>
#include <algorithm>

#define sz 10010

int dp[30][sz][30];

using namespace std;


int DFS( int l,int s,int prv){

    if (s<0)return 0;
    if (dp[l][s][prv]!= -1)return dp[l][s][prv];
    if (l==1 ){
        //printf("%d %d %d\n",l,s,prv);
        if ( s>prv && s>0 && s<27)
            return dp[l][s][prv]=1;
        else
            return dp[l][s][prv]=0;
    }

    int sum=0;
    for (int i= min(s,26 )-1 ; i>0  ; --i){
        if (i>prv)
            sum+=DFS( l-1,s-i ,i);
    }
    //printf("%d %d %d %d\n",l,s,prv,sum);
    return dp[l][s][prv]=sum;

}

int main()
{
    //freopen("in.txt","r",stdin);
    int l,s;

    memset(dp,-1,sizeof(dp));

    for (int kase=1;true;++kase)
    {
        scanf("%d %d",&l,&s);
        if (!l && !s)return 0;


        printf("Case %d: ",kase);
        if (l>26)
            printf("0\n");
        else
            printf("%d\n",DFS(l,s,0));


    }
}

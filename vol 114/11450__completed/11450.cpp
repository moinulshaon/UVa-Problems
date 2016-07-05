#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

vector<int> item[21];
int n,money;

int dp[21][210];
const int INF=(1<<29);

int func( int totake,int taka ){

    if ( taka>money ){
        return -INF;
    }
    if ( totake==n ){
        return taka;
    }

    if ( dp[totake][taka]!=-1 )return dp[totake][taka];

    int x= -INF;
    for (int i=0;i<item[totake].size();++i){
        x=max( x,func( totake+1,taka+item[totake][i] ) );
    }
    return dp[totake][taka]=x;
}

int main(){
    FRO
    int kase,a,b;
    scanf("%d",&kase);
    while( kase--){
        scanf("%d %d",&money,&n);

        for (int i=0;i<n;++i){
            item[i].clear();
        }
        for (int i=0;i<n;++i){
            scanf("%d",&a);
            while( a-- ){
                scanf("%d",&b);
                item[i].PB(b);
            }
        }

        memset( dp,-1,sizeof(dp) );
        int ans=func(0,0);
        if ( ans<0 ){
            printf("no solution\n");
        }else{
            printf("%d\n",ans);
        }

    }


    return 0;
}

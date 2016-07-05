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
#define MAKE(x,s) memset(x,s,sizeof(x))

int n;
int w[110],egg[110];
int dp[110][11000];

int func( int totake,int have ){

    if ( totake==n )return 0;

    if ( dp[totake][have]!=-1 )return dp[totake][have];

    int x=w[totake]+func( totake+1,have+egg[totake] );
    if ( have ){
        x=min( x, w[totake]/2 +func( totake+1,have+egg[totake]-1 ) );
    }
    return dp[totake][have]=x;
}

int main(){

    while( scanf("%d",&n)==1 && n ){

        int sum=0;

        for (int i=0;i<n;++i){
            scanf("%d %d",&w[i],&egg[i]);
            sum+=egg[i];
        }

        for (int i=0;i<=n;++i){
            for (int j=0;j<=sum;++j){
                dp[i][j]= -1;
            }
        }

        printf("%d\n",func(0,0));
    }

    return 0;
}

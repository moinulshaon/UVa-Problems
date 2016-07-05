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

int dp[1010][6010];
int w[1010];
int cap[1010];
int n;


int func( int totake,int rem){

    if ( totake==n )return 0;

    if ( dp[totake][rem] != -1 )return dp[totake][rem];

    int x=0,y=0;
    x=func( totake+1,rem );
    if ( rem-w[totake]>=0 ){
        y=1+func( totake+1,min( rem-w[totake],cap[totake]  ) );
    }
    return dp[totake][rem]=max( x,y );
}

int main(){


    while( scanf("%d",&n)==1 && n ){

        for (int i=0;i<n;++i){
            scanf("%d %d",&w[i],&cap[i]);
        }
        memset(dp,-1,sizeof(dp));

        printf("%d\n",func(0,6009));
    }

    return 0;
}

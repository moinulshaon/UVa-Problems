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
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

int dp[1001][1001][11];
int mod = 1000000000+7;
int n;

int func( int totake,int left,int dif ){

    if ( left ==0 )return 1;
    if ( totake <= 0 ){
        return 0;
    }
    if ( dp[  totake][ left][ dif ] != -1 )return dp[  totake][ left][ dif ];

    return dp[  totake][ left][ dif ] =
            ( func( totake-1,left,dif ) + func( totake - dif ,left-1,dif) )%mod;

}

int main(){

    //FRO

    NEG(dp);

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int k,d;
        scanf("%d %d %d",&n,&k,&d);

        if ( k == 1 ){
            printf("Case %d: %d\n",kk,n);
            continue;
        }

        int ans = func( n-d-1,k,d );
        //cout<<ans<<endl;
        int cnt = 1;
        for (int i=n;i>=n-d;--i){
            if( d+1 <= n )
                ans = ( ans + func( i-d-(d-cnt),k-1,d ) )%mod;
            //cout<<ans<<endl;
            if ( cnt<d )
                cnt++;
        }

        printf("Case %d: %d\n",kk,ans);
    }


    return 0;
}

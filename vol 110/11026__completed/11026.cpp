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

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 1005

int n;
LL m;
LL dp[SIZE][SIZE];

LL arr[SIZE];
LL sum[SIZE];

int main(){



    while ( scanf("%d %lld",&n,&m)==2 ){
        if ( n==0 && m==0 )break;

        for (int i=1;i<=n;++i){
            scanf("%lld",&arr[i]);
        }

        for (int i=1;i<=n;++i){
            dp[0][i] = arr[i];
        }
        dp[0][0] = 0;
        sum[0] = 0;

        for (int i=1;i<=n;++i){
            sum[i] = ( sum[i-1]+dp[0][i] )%m;
        }

        LL ans = 0;
        for (int k=1;k<=n;++k){
            for (int i=k+1;i<=n;++i){
                dp[k][i] = ( arr[i] * sum[i-1] )%m;
            }
            for (int i=1;i<=n;++i){
                sum[i] = (sum[i-1]+dp[k][i])%m;
            }
            ans = max( ans , sum[n] );
        }
/*
        for (int k=1;k<=n;++k){
            for (int i=1;i<=n;++i){
                cout<<dp[k][i]<<" ";
            }cout<<endl;
        }
*/
        printf("%lld\n",ans);
    }


    return 0;
}

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

#define SIZE 1010

LL mod = 1000000007;
LL fact[SIZE];

LL dp[SIZE][SIZE];

LL func( int n,int r ){
    if ( r==0 || r== n )return 1;
    if ( dp[n][r] != -1 )return dp[n][r];
    else return dp[n][r] = dp[n][n-r] = ( func( n-1,r )+func( n-1,r-1 ) )%mod;
}

int main(){

    NEG(dp);

    fact[0]=1;
    for (int i=1;i<SIZE;++i){
        fact[i] = ( fact[i-1]* i )%mod;
    }

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);

        printf("Case %d: ",kk);
        if ( k>m || k>n || m>n ){
            printf("0\n");
            continue;
        }
        LL ans = func( m,k );
        LL sum = 0;
        for (int i=0; i<= m-k ;++i){
            if ( i&1 ){
                sum = ( sum- func( m-k,i ) * fact[ n- k -i]   )%mod;
            }else{
                sum = ( sum+ func( m-k,i ) * fact[ n- k -i]   )%mod;
            }
            //cout<<sum<<endl;
        }
        ans=( ans*sum )%mod;
        if ( ans<0 )ans+=mod;
        printf("%lld\n",ans);
    }

    return 0;
}

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

long long BigMod ( long long a, long long p, long long m ){
    long long res = 1;
    long long x = a;

    while ( p ){
        if ( p & 1 ){
            res = ( res * x ) % m;
        }
        x = ( x * x ) % m;
        p = p >> 1;
    }

    return res % m;
}

#define SIZE 1005

int n;
LL m;
LL dp[SIZE][SIZE];

LL arr[SIZE];

LL func( int totake,int have ){

    if ( have==0 )return arr[totake];


    LL &ret = dp[totake][have];
    if ( ret != -1 )return ret;

    ret = 0;
    for (int i=have;i<totake;++i){
        ret += arr[totake] * func(i,have-1) ;
        ret %= m;
    }
    return ret;
}

int main(){

    FRO

    while ( scanf("%d %lld",&n,&m)==2 ){
        if ( n==0 && m==0 )break;

        for (int i=1;i<=n;++i){
            scanf("%lld",&arr[i]);
        }

        NEG(dp);

        LL ans = 0;
        for (int k=1;k<=n;++k){
            LL sum = 0;
            for (int i=1;i<=n;++i){
                sum += func( i,k );
                sum%=m;
                cout<<func(i,k)<<" ";
            }cout<<endl;
            ans = max( ans , sum );
        }

        printf("%lld\n",ans);
    }


    return 0;
}

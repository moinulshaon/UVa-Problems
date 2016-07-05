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

#define SIZE 100010

LL dp[SIZE][6];
LL way[SIZE][6];
LL cum[SIZE][6];

LL mod = 7477777;

LL shaon( int n,int k ){
    if ( n<k )return 0;
    if ( k==1 )return 1;

    if ( way[n][k] != -1 )return way[n][k];

    return way[n][k] = ( shaon( n-1,k-1 )+ shaon( n-1,k ) )%mod;
}

LL save[SIZE][6];
LL another( int n,int k ){
    if ( k>n )return 0;
    if ( save[n][k] != -1 )return save[n][k];
    return save[n][k] = ( another( n-1,k ) + (n-1)*shaon( n-1,k-1 ) )%mod;
}

LL func( int n,int k ){
    if ( n<k )return 0;
    if ( k==1 )return (LL(n)*n)%mod;

    if ( dp[n][k] != -1 )return dp[n][k];

    LL sum=( (2*n-1)*cum[ n-1 ][ k-1 ] )%mod;
    /*
    for (int i=k-1;i<n;++i){
        sum+= (2*n-1-2*i)*shaon( i,k-1 );
    }
    */
    sum= ( sum-2*another( n,k ) )%mod;

    //printf("%d %d %d %d\n",n,k,dp[n][k],sum);
    return dp[n][k]= ( func( n-1,k-1 ) + func( n-1,k ) + sum )%mod;
}

int main(){

    NEG(dp);
    NEG(way);
    NEG(save);


    for (int i=1;i<SIZE;++i){
        for (int j=1;j<6;++j){
            cum[i][j] = ( cum[i-1][j]+shaon( i,j ) )%mod;
        }
    }

    for (int i=0;i<SIZE;++i){
        func( i,5 );
    }


    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n;
        scanf("%d",&n);
        LL ans = func( n,5 );
        if ( ans<0  )ans+=mod;
        printf("Case %d: %lld\n",kk,ans);
    }


    return 0;
}

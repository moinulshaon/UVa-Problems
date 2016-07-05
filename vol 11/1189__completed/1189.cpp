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

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

char str[210];
int ans;

char dp[110][210];
int save[110];
int mod;

char func( int totake ,int m){
    if ( m==0 )return 1;
    if ( totake==100 )return 0;

    if ( dp[totake][m] != -1 )return dp[totake][m];

    if ( func( totake+1, (m+save[totake])%mod ) >0  ){
        str[ans++]='1';
        return dp[totake][m]=1;
    }else if ( func( totake+1, m ) >0  ){
        str[ans++]='0';
        return dp[totake][m]=1;
    }else{
        return dp[totake][m]=0;
    }

}

int BigMod ( int a, int p, int m ){
    int res = 1;
    int x = a;

    while ( p ){
        if ( p & 1 ){
            res = ( res * x ) % m;
        }
        x = ( x * x ) % m;
        p = p >> 1;
    }

    return res % m;
}


int main(){

    int n;
    while ( scanf("%d",&n)==1 && n ){
        NEG(dp);
        ans=0;
        mod=n;

        for (int i=0;i<110;++i){
            save[i]= BigMod( 10,i,n );
        }

        func(0,n);

        for (int i=0;i<ans;++i){
            printf("%c",str[i]);
        }printf("\n");
    }


    return 0;
}

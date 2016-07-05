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

#define INF (1<<20)

int dp[105][255];
int n;
int arr[105];
int w;

int func( int totake ,int now ){

    if ( now>=w )return now-w;

    if ( totake == n )return INF;

    if ( dp[totake][now] != -1 )return dp[totake][now];
    return dp[totake][now] = min( func(totake+1,now) , func( totake+1,now+arr[totake] ) );
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    while (  kase-- ){

        NEG(dp);
        scanf("%d",&w);
        w/=10;

        scanf("%d",&n);

        for (int i=0;i<n;++i){
            scanf("%d",&arr[i]);
            arr[i]/=10;
        }

        int ans = func( 0 , 0 );

        if ( ans >=INF )printf("NO SOLUTION\n");
        else printf("%d\n",w*10+ans*10);

    }


    return 0;
}

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


int arr[105];

int dp[105][105];

int func( int le,int ri ){

    if ( le > ri )return 0;

    if ( dp[le][ri] != -1 )return dp[le][ri];

    int ans = 1+func(le+1,ri);
    for (int i=le+1;i<=ri ;++i){
        if ( arr[le] == arr[i] ){
            ans=min( ans, func( le+1,i ) + func( i+1,ri ) );
        }
    }
    return dp[le][ri] = ans ;
}

int n,m;
int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for(int kk=1;kase--;++kk){
        scanf("%d %d",&n,&m);

        for (int i=0;i<n;++i){
            scanf("%d",&arr[i]);
        }

        NEG(dp);
        printf("Case %d: %d\n",kk,func(0,n-1));
    }


    return 0;
}

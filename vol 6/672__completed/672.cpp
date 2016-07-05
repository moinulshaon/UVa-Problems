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

#define SIZE 105

struct tt{
    int t,p,o;
}arr[SIZE];

bool cmp( const tt&a,const tt&b ){
    return a.t<b.t;
}

int n;
int dp[SIZE];

int func( int totake ){

    if ( totake >=n )return 0;

    int &ret = dp[totake];

    if (ret != -1 )return ret;
    ret = 0;
    for (int i=totake+1;i<n;++i){
        if ( abs( arr[totake].o - arr[i].o )<= arr[i].t - arr [totake].t ){
            ret = max(  ret, arr[i].p+ func( i ) );
        }
    }
    return ret;
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){
        scanf("%d %*d %*d",&n);
        //cout<<n<<endl;
        for (int i=0;i<n;++i){
            scanf("%d",&arr[i].t);
        }
        for (int i=0;i<n;++i){
            scanf("%d",&arr[i].p);
        }

        for (int i=0;i<n;++i){
            scanf("%d",&arr[i].o);
        }

        sort( arr,arr+n,cmp );

        int ans = 0;
        NEG(dp);

        for (int i=0;i<n;++i){
            if ( arr[i].o <= arr[i].t  )
                ans = max( ans , arr[i].p + func (i) );
        }

        printf("%d\n",ans);
        if ( kase )printf("\n");
    }

    return 0;
}

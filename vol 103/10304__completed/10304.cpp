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

#define SIZE 255

int dp[SIZE][SIZE];
int v[SIZE];
int sum[SIZE];
int arr[SIZE];

int result(  int x,int y ){
    if ( x>y )return 0;
    return sum[y]-sum[x-1];
}

int func( int l,int r ){

    if ( l>r )return 0;

    int &ret = dp[l][r];
    if ( ret != -1 )return ret;


    ret = (1<<29);
    for (int i=l;i<=r;++i){
        ret = min( ret ,func( l,i-1 ) + func( i+1,r ) + result( l,r ) - arr[i]   );
    }
    return ret;
}

int main(){

    int n;
    while  ( scanf("%d",&n) == 1 && n ){

        sum[0]=0;
        for (int i=1;i<=n;++i){
            scanf("%d",&arr[i]);
            sum[i]= sum[i-1]+arr[i];
            //cout<<sum[i]<<endl;
        }

        NEG(dp);
        printf("%d\n",func( 1,n ));
    }


    return 0;
}


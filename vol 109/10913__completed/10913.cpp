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

int dp[77][77][3][7];

int n;
int arr[77][77];

int func ( int r,int c,int dir,int left ){

    //cout<<r<<' '<<c<<' '<<dir<<' '<<left<<endl;

    if ( arr[r][c] < 0 ){
        left--;
    }

    if ( left<0 ){
        return -(1<<28);
    }


    if ( r == n-1 && c== n-1 ){
        return arr[r][c];
    }

    if ( dp[r][c][dir][left] != -1 )return dp[r][c][dir][left];


    int ans = -(1<<28);
    if ( r+1<n ){
        ans = max(  ans,arr[r][c] + func( r+1,c,2,left ) );
    }
    if ( c+1<n && dir != 0 ){
        ans = max(  ans,arr[r][c] + func( r,c+1,1,left ) );
    }
    if ( c-1>=0 && dir != 1 ){
        ans = max(  ans,arr[r][c] + func( r,c-1,0,left ) );
    }
    return dp[r][c][dir][left] = ans ;
}

int main(){

    FRO

    int k;
    int kase= 1;
    while ( scanf("%d %d",&n,&k) == 2 && ( n+k ) ){

        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                scanf("%d",&arr[i][j]);
            }
        }

        NEG(dp);

        int ans = func( 0,0,2,k );

        printf("Case %d: ",kase++);
        if ( ans< -(1<<27) ){
            printf("impossible\n");
        }else{
            printf("%d\n",ans);
        }

    }


    return 0;
}

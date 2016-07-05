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

int n;

int arr[20];

char dp[1<<17][102];
int sum[1<<17];

int Set(int N,int pos){
    return N=N | (1<<pos);
}
int Reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool Check(int N,int pos){
    return (bool)(N & (1<<pos));
}


char func( int state,int x ){

    char &ret = dp[state][x];
    if ( ret != -1 ){
        return ret;
    }
    if ( __builtin_popcount(state) == 1 ){
        return ret = 1;
    }

    ret = 0;

    int y= sum[state]/x;
    for (int nxt=state&(state-1);nxt>0;nxt = state&(nxt-1) ){
        if ( sum[nxt]%x == 0 && func( nxt,min(x,sum[nxt]/x) ) && func( state-nxt,min( x,sum[ state-nxt ]/x ) ) ){
            return ret = 1;
        }
        if ( sum[nxt]%y == 0 && func( nxt,min(y,sum[nxt]/y) ) && func( state-nxt,min( y,sum[ state-nxt ]/y ) ) ){
            return ret = 1;
        }
    }
    return ret;
}

int main(){

    FRO

    int kk=1;
    while ( scanf("%d",&n) == 1 && n ){

        int x,y;
        scanf("%d %d",&x,&y);

        for (int i=0;i<n;++i){
            scanf("%d",&arr[i]);
        }

        for (int i=0;i<(1<<n);++i){
            sum[i] = 0;
            for (int j=0;j<n;++j){
                if ( Check( i,j ) == 1 ){
                    sum[i] += arr[j];
                }
            }
        }

        printf("Case %d: ",kk++);
        NEG(dp);
        if (  sum[ (1<<n)-1 ] == x*y && func( (1<<n)-1,min(x,y) ) == 1 ){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }


    return 0;
}

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

LL dp[15][310][3][3];

LL func( int frame ,int sum,int now,int nxt){

    if ( sum<0 )return 0;
    if ( frame>11 ){
        return sum==0;
    }

    LL &ret = dp[frame][sum][now][nxt];
    if ( ret != -1 )return ret;
    ret = 0;

    if ( frame<=10 ){
        for (int i=0;i<10;++i){
            for (int j=0;j<=10;++j){
                if ( i+j<10 )
                    ret+= func( frame+1,sum-(i+j)-i*now-j*nxt,0,0 );
                else if ( i+j == 10 ){
                    ret+= func( frame+1,sum-(i+j)-i*now-j*nxt,1,0 );
                }
            }
        }
        ret+= func( frame+1,sum-10-10*(now), nxt+1,1 );
    }else{
        //cout<<now<<" "<<nxt<<endl;
        if ( now>0 ){

            for (int i=0;i<=10;++i){
                if ( nxt == 0 )
                    ret+= func( frame+1,sum-i*(now),nxt,0 );
                else{
                    for (int j=0;j<=10;++j){
                        if ( i==10 ){
                            ret+= func( frame+1,sum-10*(now)-j*(nxt),0,0 );
                        }else if (i+j<=10){
                            ret+= func( frame+1,sum-i*(now)-j*(nxt),0,0 );
                        }
                    }
                }
            }
        }else{
            ret+= ( sum==0 );
        }
    }
    return ret;
}

int main(){

    //FRO

    NEG(dp);

    int n;
    while ( scanf("%d",&n)==1 && n!= -1 ){
        printf("%lld\n",func( 1,n,0,0 ));
    }

    return 0;
}

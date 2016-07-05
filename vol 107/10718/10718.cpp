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

LL Set(LL N,int pos){
    return N=N | (1LL<<pos);
}
LL Reset(LL N,int pos){
    return N= N & ~(1LL<<pos);
}
bool Check(int N,int pos){
    return (bool)(N & (1LL<<pos));
}


int main(){

    LL n,l,r;

    while ( scanf("%lld %lld %lld",&n,&l,&r) == 3 ){

        LL ans = 0;
        LL mx = 0;
        for (int i=33;i>=0;--i){
            LL tmp = Set( ans,i );
            if ( tmp>=l && tmp<=r && ( tmp|n )>=mx ){
                mx= ( tmp|n );
                ans = tmp;
            }

            tmp = Set( 0,i );
            if ( tmp>=l && tmp<=r && ( tmp|n )>=mx ){
                mx= ( tmp|n );
                ans = tmp;
            }
        }
        printf("%lld\n",ans);
    }


    return 0;
}

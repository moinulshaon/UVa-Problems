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

int ff(LL x){

    int i;
    for (i=0; x>0;++i ){
        x>>=1;
    }
    return i-1;
}

map<LL,LL> mp;

LL func( LL x ){

    //printf("%lld\n",x);

    if ( x==0 )return 0;

    if ( mp.find( x )!= mp.end() )return mp[x];

    LL tmp= 1LL<<ff(x);

    return mp[x] = x-tmp+1+func( x-tmp )+func( tmp-1 );
}

int main(){

    //FRO

    LL a,b;
    int kk=1;
    while ( scanf("%lld %lld",&a,&b) == 2 ){

        if ( !a && !b )break;

        LL ans= func( b )-func( a-1 );

        printf("Case %d: %lld\n",kk++,ans);
    }


    return 0;
}

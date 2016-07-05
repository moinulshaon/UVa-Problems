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


typedef pair<LL,LL> pint;
typedef map<int,int> mint;

pint extendedgcd(LL a,LL b){
    LL div,temp,x0=1,x1=0,y0=0,y1=1;

    while (b!=0){

        div=a/b;
        temp=a;
        a=b;
        b=temp%b;

        temp=x1;
        x1=x0-div*x1;
        x0=temp;

        temp=y1;
        y1=y0-div*y1;
        y0=temp;
    }
    return MP(x0,y0);
}

LL func( LL a,LL b,LL x ){

    LL d= __gcd( a,b );

    if ( x%d != 0 )return 0;

    x/= d;
    a/= d;
    b/= d;

    pint sol = extendedgcd( a,b );

    sol.X *= x;
    sol.Y *= x;

    //cout<<"in "<<sol.X<<" "<<sol.Y<<" "<<x<<endl;
    //cout<<sol.Y/a+sol.X/b<<endl;
    return max( 1e-6,LL(sol.Y/a)-ceil(-double(sol.X)/b)+1+1e-6 ) ;
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        LL a,b,c,p;
        scanf("%lld %lld %lld %lld",&a,&b,&c,&p);

        LL ans = 0;
        while ( p>=0 ){
            ans += func( a,b,p );
            //cout<<a<<" "<<b<<" "<<p<<" "<<endl;
            //cout<<func(a,b,p)<<endl;
            p-= c;
            //break;
        }

        printf("Case %d: %lld\n",kk,ans);
    }


    return 0;
}

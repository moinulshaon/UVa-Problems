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

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

bool vis[510];
double ee[510];


bool vis22[510];
double suff[510];
double pp;

double func( int x ){

    if ( x==0 )return 0;
    if ( vis22[x] )return suff[x];

    vis22[x]=true;
    return suff[x]= pp*( 1+ func(x-1) ) ;

}

double exe( int x ){

    if ( x==0 )return 0;
    if ( vis[x] )return ee[x];

    vis[x]=true;
    return ee[x]= (1.0-pp)*exe( x-1 ) + pp*( max( 1.0/(x-1)*exe(x-1) -  , 1+func( x-1 ) ) );

}



int main(){

    int n;
    while ( scanf("%d %lf",&n,&pp)==2 && n ){
        CLR(vis);
        CLR(vis22);

        printf("%lf\n",exe(n));
    }


    return 0;
}

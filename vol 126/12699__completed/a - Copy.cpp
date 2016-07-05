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




int a,d,s;

#define SIZE 1000100

double add[SIZE],dd[SIZE],sub[SIZE];

double dp[SIZE][31];
bool vis[SIZE][31];

double funcs( int x ,int le ){

    if ( x== 0 || le == 0 )return 0;

    if ( vis[x][le] )return dp[x][le];

    vis[x][le]=true;

    if ( x%2 == 0 ){
        return dp[x][le]=funcs( x/2,le );
    }else{
        return dp[x][le]=.5*( 1+ funcs( x-1,le-1 ) )+.5*( funcs( x+1,le-1 ) );
    }
}



double funcd( int x ,int le ){
    if ( x == 0 || le == 0 )return 0;

    if ( vis[x][le] )return dp[x][le];

    vis[x][le]=true;

    if ( x%2 == 0 ){
        return dp[x][le]=1+funcd( x/2,le );
    }else{
        return dp[x][le]= .5*funcd( x-1,le-1 )+.5*funcd( x+1,le-1 ) ;
    }
}

int main(){


    for (int i=1;i<SIZE;++i){
        sub[i]=funcs( i , 30 );
    }


    for (int i=1;i<SIZE;++i){
        add[i]=sub[i];
    }

    CLR(vis);

    for (int i=1;i<SIZE;++i){
        dd[i]=funcd( i , 30 );
    }


    FRO
    //freopen("out.txt","w",stdout);

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){
        int n;
        scanf("%d %d %d %d",&n,&d,&s,&a);

        //printf("%lf %lf %lf\n",add[n],sub[n],dd[n]);

        printf("%.3lf\n",add[n]*a+sub[n]*s+dd[n]*d );
    }



    return 0;
}

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

#define SIZE 34

LL dp[SIZE][SIZE][SIZE][SIZE][SIZE];

LL func( int d1,int d2,int g1,int g2,int g ){

    //cout<<d1<<" "<<d2<<" "<<g1<<" "<<g2<<endl;

    //getchar();
    if ( d2==0  ){
        if ( d1==0 )return 1;
        else return 0;
    }

    LL &ret = dp[d1][d2][g1][g2][g];

    if ( ret != -1 )return ret;

    ret = 0;
    if ( g1==0 && d1 > 0 && g2==0 && d2>0 ){
        return ret=0;
    }
    bool on=true;
    if ( g1==0 && d1>0 ){
        on=false;
        ret += func( d1-1,d2,g,g2-1,g );
    }
    if ( g2==0 && d2>0 ){
        on=false;
        ret += func( d1,d2-1,g1-1,g,g );
    }

    if ( on ){

        if ( d1>0 )
            ret += func( d1-1,d2,g,g2-1,g ) ;

        //if ( d1+d2==6 )cout<<"done";

        if (d2>0)
            ret+=func( d1,d2-1,g1-1,g,g );
    }
    return ret;
}

int main(){

    NEG(dp);

    int d,g,kk=1;
    while ( scanf("%d %d",&d,&g)==2 ){
        if ( d== -1 && g== -1 )break;
        printf("Case %d: ",kk++);

        if ( g==0 || d==0 )printf("0\n");
        else printf("%lld\n",2*func( d-1,d,g,g-1,g ));
    }


    return 0;
}

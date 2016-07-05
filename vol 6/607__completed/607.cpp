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

typedef pair<int,int> pint;

int topic;
int w[1010];
int perlec,cc;

pint dp[1010][510];
bool vis[1010][510];

const int INF=(1<<29);

int calc( int tt ){
    if ( tt==0 )return 0;
    else if ( tt<=10 )return -cc;
    else return ( tt-10)*(tt-10);
}

pint func(int totake,int left){

    if ( totake==topic )return make_pair( 0,calc(left) );

    if ( vis[totake][left] )return dp[totake][left];

    pint x=make_pair(INF,0),y;

    if ( left!=perlec ){
        y=func( totake,perlec );
        y.first++;
        y.second+=calc( left );

        if ( y.first<x.first ){
            x=y;
        }else if ( y.first==x.first ){
            x.second= min( x.second, y.second);
        }
    }

    if ( left >=w[totake] ){

        y=func( totake+1,left-w[totake] );

        if ( y.first<x.first ){
            x=y;
        }else if ( y.first==x.first ){
            x.second= min( x.second, y.second);
        }
    }
    vis[totake][left]=true;
    return dp[totake][left]=x;
}

int main(){
    FRO

    for(int kk=1; scanf("%d",&topic)==1 && topic ;++kk){
        if ( kk!=1 )printf("\n");

        scanf("%d %d",&perlec,&cc);

        for (int i=0;i<topic;++i){
            scanf("%d",&w[i]);
        }

        memset(vis,false,sizeof(vis));
        pint ans=func( 0,perlec );

        printf("Case %d:\n",kk);
        printf("Minimum number of lectures: %d\n",ans.first+1);
        printf("Total dissatisfaction index: %d\n",ans.second);
    }


    return 0;
}

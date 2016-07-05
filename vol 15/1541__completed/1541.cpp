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

int bb,tt;

int board[51];
bool lose[51];
char tmp[51];

bool vis[51][2][41];

double dp[51][2][41];

double func( int now,int prv,int move ){

    if ( move>tt )return 0;
    if ( now>bb )return 1;

    if ( vis[ now ][prv][move] )return dp[ now ][prv][move];

    vis[ now ][prv][move]=true;

    if ( prv==1 ){
        if ( lose[now] ){
            return dp[ now ][prv][move]=func( now,!prv,move+1 );
        }else{
            return dp[ now ][prv][move]=func( now+board[now],!prv,move );
        }
    }else{
        return dp[ now ][prv][move]=.5*func( now+1,!prv,move+1 )+.5*func( now+2,!prv,move+1 );
    }
}

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){
        scanf("%d %d",&bb,&tt);
        CLR(lose);
        for (int i=1;i<=bb;++i){
            scanf("%s",tmp);
            if ( tmp[0] =='L' ){
                lose[i]=true;
            }else{
                sscanf(tmp,"%d",&board[i]);
            }
        }

        CLR(vis);

        double ans= .5*func( 1,1,1 )+.5*func( 2,1 ,1 );

        if ( fabs(ans-.5)<1e-7 )printf("Push. 0.5000\n");
        else if ( ans>.5) printf("Bet for. %.4lf\n",ans);
        else printf("Bet against. %.4lf\n",ans);

    }


    return 0;
}

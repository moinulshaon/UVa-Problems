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
#define INF 100000000

double ini[60][60];
int node,edge;
map<int,int> mp;

double profit[20];
int city;

int SET(int N,int pos){
    return N=N | (1<<pos);
}
int reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool check(int N,int pos){
    return (bool)(N & (1<<pos));
}

bool vis[1<<15][15];
double dp[1<<15][15];

double func( int state,int now ){

    if ( state== (1<<city)-1 )return profit[now]-ini[ mp[now] ][0];

    if ( vis[state][now] )return dp[state][now];

    double mx= profit[now]-ini[ mp[now] ][0] ;

    for (int i=0;i<city;++i){
        if ( check( state,i ) == 0  ){
            mx=max( mx,profit[now]-ini[ mp[now] ][ mp[i] ]+func( SET(state,i) ,i ) );
        }
    }
    vis[state][now]=true;
    return dp[state][now]=mx;
}

int main(){
    FRO
    int u,v,kase;
    double cc;
    scanf("%d",&kase);

    while(kase--){
        scanf("%d %d",&node,&edge);


        for (int i=0;i<=node;++i){
            for (int j=0;j<=node;++j){
                if ( i!=j )
                    ini[i][j]=INF;
                else
                   ini[i][j]=0;
            }
        }

        while(edge--){
            scanf("%d %d %lf",&u,&v,&cc);
            ini[u][v]=ini[v][u]=min(cc,ini[v][u]);
        }
        for (int k = 0; k <=node ; k++ ) {
            for (int i = 0; i <=node; i++ ) {
                for (int j = 0; j <=node; j++ )
                    ini[i] [j] = min (ini [i] [j], ini [i] [k]+ ini [k] [j]); //shortest
            }
        }
        mp.clear();
        int cd;
        scanf("%d",&cd);

        for (int i=0;i<cd;++i){
            profit[i]=0;
        }

        city=0;
        map<int,int> anmp;
        for (int i=0;i<cd;++i){
            scanf("%d %lf",&u,&cc);

            if ( anmp.find(u)==anmp.end() ){
                mp[city]=u;
                anmp[u]=city;
                city++;
            }
            profit[ anmp[u] ]+=cc;
        }

        double ans=0;
        memset(vis,false,sizeof(vis));
        for (int i=0;i<city;++i){
            ans=max( ans, -ini[ 0 ][  mp[i] ]  + func( SET(0,i) ,i ) );
        }

        if ( ans<1e-6 ){
            printf("Don't leave the house\n");
        }else{
            printf("Daniel can save $%.2lf\n",ans);
        }
    }


    return 0;
}

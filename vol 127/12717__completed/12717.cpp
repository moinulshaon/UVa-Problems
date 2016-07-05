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

#define SIZE 2505

vector<int> out[SIZE];
int cost[SIZE][SIZE];

vector<int> w;

vector<pint> qq;

int cnt;
void bfs( int s ){

    bool vis[SIZE]={false};

    queue<int> q;

    q.push( s );
    vis[ s ]=true;

    while ( !q.empty() ){
        int x=q.front();q.pop();


        for (int i=0;i<out[x].size();++i){
            if ( !vis[ out[x][i] ] ){
                vis[ out[x][i] ] = true;
                q.push( out[x][i] );
                cost[ x ][ out[x][i] ] = cost[ out[x][i] ][ x ] = w[cnt++];
            }
        }
    }
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        printf("Case %d:\n",kk);

        int n,m,ss;
        scanf("%d %d %d",&n,&m,&ss);

        for (int i=0;i<=n;++i){
            out[i].clear();
        }
        w.clear();
        qq.clear();

        int u,v,tmp;
        for (int i=0;i<m;++i){
            scanf("%d %d %d",&u,&v,&tmp);
            out[u].PB( v );
            out[v].PB( u );

            qq.PB( make_pair( u,v ) );

            cost[ u ][ v ] =cost[ v ][ u ] = 0;

            w.PB( tmp );
        }

        sort( w.begin(),w.end() );


        cnt = 0;
        bfs(ss);

        for (int i=0;i<m;++i){

            printf("%d %d ",qq[i].first,qq[i].second);

            if ( cost[ qq[i].first ][ qq[i].second ] == 0 ){
                printf("%d\n",w[cnt++]);
            }else{
                printf("%d\n", cost[ qq[i].first ][ qq[i].second ]);
            }

        }

    }


    return 0;
}

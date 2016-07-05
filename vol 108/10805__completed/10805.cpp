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

#define SIZE 700

vector<int> out[SIZE];
int dist[SIZE][SIZE];

void bfs( int x ){


    queue<int> q;

    q.push( x );
    dist[x][x]= 0;

    int y ;
    while ( !q.empty() ){
        int tmp= q.front();q.pop();

        for (int i=0;i<out[tmp].size();++i){
            y= out[tmp][i];
            if ( dist[x][ y ] > dist[x][tmp] + 1 ){
                dist[x][ y ] = dist[x][tmp] + 1;
                q.push( y );
            }
        }
    }

}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for(int kk=1;kase--;++kk){
        int n,e;
        scanf("%d %d",&n,&e);

        for (int i=0;i<SIZE;++i){
            out[i].clear();
        }

        int save = n;

        int u,v;
        while ( e-- ){
            scanf("%d %d",&u,&v);

            out[u].PB( n );
            out[n].PB( u );

            out[v].PB( n );
            out[n].PB( v );

            n++;
        }

        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                dist[i][j] =(1<<29);
            }
        }
        for (int i=0;i<n;++i){
            bfs( i );
        }
        /*
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                printf("%3d",dist[i][j]);
            }printf("\n");
        }
        */

        int ans = (1<<29);
        for (int i=0;i<n;++i){
            int first=0,second=0;
            for (int j=0;j<save;++j){
                if ( dist[i][j]>first ){
                    second =first;
                    first = dist[i][j];
                }else if ( dist[i][j]>second ){
                    second = dist[i][j];
                }
            }
            ans= min( ans , first+second );
        }

        printf("Case #%d:\n%d\n\n",kk,ans/2);
    }


    return 0;
}

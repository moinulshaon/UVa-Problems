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

#define SIZE 505

int adj[SIZE][SIZE];

vector<int> out[SIZE],rev[SIZE];

int n;
int s,f;

int dist[SIZE];

struct node
{
    int val,city;
    bool operator < (const node & p)const{return val>p.val;}
}tt,xx;


void dijkstra(){

    memset( dist,62,sizeof(dist) );

    priority_queue< node > q;

    tt.city= s;
    tt.val = 0;

    q.push( tt );

    int v;
    while ( !q.empty() ){

        xx = q.top();q.pop();

        if ( dist[ xx.city ] < xx.val )continue;

        dist[ xx.city ] = xx.val;

        for (int i=0;i<out[ xx.city ].size();++i){
            v= out[ xx.city ][i];

            if ( dist[ v ] > xx.val+ adj[ xx.city ][ v ] ){
                tt.city= v ;
                tt.val=xx.val+ adj[ xx.city ][ v ];
                q.push( tt );
            }
        }
    }
}


int dd2(){


    priority_queue< node > q;

    bool vis[SIZE]={false};

    tt.city= s;
    tt.val = 0;

    q.push( tt );

    int v;
    while ( !q.empty() ){

        xx = q.top();q.pop();

        if ( xx.city == f )return xx.val;

        if ( vis[ xx.city ] )continue;
        vis[ xx.city ]=true;

        for (int i=0;i<out[ xx.city ].size();++i){
            v= out[ xx.city ][i];

            if ( adj[ xx.city ][ v ] != 0 && !vis[ v ] ){
                tt.city= v ;
                tt.val=xx.val+ adj[ xx.city ][ v ];
                q.push( tt );
            }
        }
    }
    return -1;
}



void shaon( int x ){

    if ( x== s )return ;

    for (int i=0;i<rev[x].size();++i){
        int y = rev[x][i];
        if ( dist[ y ]+adj[ y ][ x ] == dist[ x ]
            && adj[ y ][ x ] != 0   ){
                adj[ y ][ x ] = 0;
                shaon( y );
            }
    }

}

int main(){

    FRO

    int ee;
    while ( scanf("%d %d",&n,&ee) == 2 && ( n+ee ) ){


        CLR(adj);

        for (int i=0;i<n;++i){
            out[i].clear();
            rev[i].clear();
        }


        scanf("%d %d",&s,&f);

        int u,v,w;
        while ( ee-- ){
            scanf("%d %d %d",&u,&v,&w);

            out[u].PB( v );
            adj[u][v] = w;
            rev[ v ].PB( u );
        }

        dijkstra();
        /*
        for (int i=0;i<n;++i){
            printf("%d ",dist[i]);
        }printf("\n");
        */
        shaon( f );


        printf("%d\n",dd2());

    }



    return 0;
}

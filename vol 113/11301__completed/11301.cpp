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

// the maximum number of vertices + 1
#define SIZE 10015

// adjacency matrix (fill this up)
map<int,int> cap[SIZE];

// cost per unit of flow matrix (fill this up)
map<int,int> cost[SIZE];

// flow network and adjacency list
map<int,int> fnet[SIZE];
vector<int> out[SIZE];

// Dijkstra's successor and depth
int par[SIZE], d[SIZE];        // par[source] = source;

// Labelling function
int pi[SIZE];


const int INF= (INT_MAX/2);

// Dijkstra's using non-negative edge weights (cost + potential)
#define Pot(u,v) (d[u] + pi[u] - pi[v])
bool dijkstra( int n, int s, int t ){
    for( int i = 0; i < n; i++ ){
        d[i] = INF, par[i] = -1;
    }
    d[s] = 0;
    par[s] = -n - 1;

    while( 1 )
    {
        // find u with smallest d[u]
        int u = -1, bestD = INF;
        for( int i = 0; i < n; i++ ) if( par[i] < 0 && d[i] < bestD )
            bestD = d[u = i];
        if( bestD == INF ) break;

        // relax edge (u,i) or (i,u) for all i;
        par[u] = -par[u] - 1;
        for( int i = 0; i < out[u].size(); i++ )
        {
            // try undoing edge v->u
            int v = out[u][i];
            if( par[v] >= 0 ) continue;
            if( fnet[v][u] && d[v] > Pot(u,v) - cost[v][u] )
                d[v] = Pot( u, v ) - cost[v][u], par[v] = -u-1;

            // try edge u->v
            if( fnet[u][v] < cap[u][v] && d[v] > Pot(u,v) + cost[u][v] )
                d[v] = Pot(u,v) + cost[u][v], par[v] = -u - 1;
        }
    }

    for( int i = 0; i < n; i++ ) if( pi[i] < INF ) pi[i] += d[i];

    return par[t] >= 0;
}
#undef Pot

int mincost( int n, int s, int t, int &fcost )
{
    /*
    //clear the vector
    for (int i=0;i<n;++i){
        out[i].clear();
    }

    // build the adjacency list
    for( int i = 0; i < n; i++ )
        for( int j = 0; j < n; j++ )
            if( cap[i][j] || cap[j][i] ) out[i].PB(j);


    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            fnet[i][j]=0;
        }
    }
    */
    memset(pi,0,sizeof(pi));
    int flow = fcost = 0;
    //cout<<"shaon1\n";
    // repeatedly, find a cheapest path from s to t
    while( dijkstra( n, s, t )   )
    {
        // get the bottleneck capacity
        int bot = INT_MAX;
        for( int v = t, u = par[v]; v != s; u = par[v = u] )
            bot =min(bot, fnet[v][u] ? fnet[v][u] : ( cap[u][v] - fnet[u][v] ) );

        // update the flow network
        for( int v = t, u = par[v]; v != s ; u = par[v = u] ){
            if( fnet[v][u] ) { fnet[v][u] -= bot; fcost -= bot * cost[v][u]; }
            else { fnet[u][v] += bot; fcost += bot * cost[u][v]; }
            //printf("%d\n",fcost);
        }

        //cout<<"shaon\n";
        flow += bot;
    }
    return flow;
}

char arr[6][1005];

int dr[]={-1,+1,+0,+0};
int dc[]={+0,+0,+1,-1};

#define MUL(x) (2*(x))

int main(){

    freopen("out.txt","r",stdin);
    int row=5,col;

    while ( scanf("%d",&col)==1 && col ) {
        gets(arr[0]);
        int vertex=2*row*col;

        for (int i=0;i<vertex+3;++i){
            out[i].clear();
            cap[i].clear();
            cost[i].clear();
            fnet[i].clear();
        }
        //cout<<"start\n";

        // fill up cap with existing capacities.
        // if the edge u->v has capacity 6, set cap[u][v] = 6.
        // for each cap[u][v] > 0, set cost[u][v] to  the
        // cost per unit of flow along the edge i->v
        /*for (int i=0; i<edge; i++) {
            scanf("%d %d %d %d",&a,&b,&cp,&c);
            cost[a][b] = c;  cost[b][a] = c;
            cap[a][b] = cp;  cap[b][a] = cp;
        }*/

        for (int i=0;i<row;++i){
            gets(arr[i]);
        }

        int r,c;
        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                for (int k=0;k<4;++k){
                    r=i+dr[k];
                    c=j+dc[k];

                    if ( c>=0 && c<col && r>=0 && r<row && arr[r][c]!='@' ){
                        cost[ MUL(i*col+j)+1 ][ MUL(r*col+c) ]=arr[r][c]-'0';
                        cap[ MUL(i*col+j)+1 ][ MUL(r*col+c) ]=1;

                        out[ MUL(i*col+j)+1 ].PB( MUL(r*col+c) );
                        out[ MUL(r*col+c) ].PB(  MUL(i*col+j)+1);
                    }
                }
            }
        }

        int source=vertex,sink=vertex+1;
        for (int i=0;i<row;++i){
            if ( arr[i][0]=='@' ){
                cost[ source ][ MUL(i*col+0) ]=0;
                cap[ source ][ MUL(i*col+0) ]=1;

                out[ source ].PB( MUL(i*col+0) );
                out[ MUL(i*col+0) ].PB(  source );

            }
        }


        for (int i=0;i<row;++i){
            cost[ MUL(i*col+col-1)+1 ][ sink ]=0;
            cap[ MUL(i*col+col-1)+1 ][ sink ]=1;

            out[ sink ].PB( MUL(i*col+col-1)+1 );
            out[ MUL(i*col+col-1)+1 ].PB(  sink );

        }

        for (int i=0;i<vertex;i+=2){
            cost[i][i+1]=0;
            cap[i][i+1]=1;

            out[ i ].PB( i+1 );
            out[ i+1 ].PB(  i );

        }

        int fcost;
        int flow = mincost( vertex+2, source, sink, fcost  );

        printf("%d\n",fcost);
    }
    return 0;
}

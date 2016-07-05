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
#define SIZE 105

// adjacency matrix (fill this up)
LL cap[SIZE][SIZE];

// cost per unit of flow matrix (fill this up)
LL cost[SIZE][SIZE];

// flow network and adjacency list
LL fnet[SIZE][SIZE];
vector<LL> out[SIZE];

// Dijkstra's successor and depth
LL par[SIZE], d[SIZE];        // par[source] = source;

// Labelling function
LL pi[SIZE];


const LL INF= (INT_MAX/2);

// Dijkstra's using non-negative edge weights (cost + potential)
#define Pot(u,v) (d[u] + pi[u] - pi[v])
bool dijkstra( LL n, LL s, LL t ){
    for( int i = 0; i < n; i++ ){
        d[i] = INF, par[i] = -1;
    }
    d[s] = 0;
    par[s] = -n - 1;

    while( 1 )
    {
        // find u with smallest d[u]
        LL u = -1, bestD = INF;
        for( int i = 0; i < n; i++ ) if( par[i] < 0 && d[i] < bestD )
            bestD = d[u = i];
        if( bestD == INF ) break;

        // relax edge (u,i) or (i,u) for all i;
        par[u] = -par[u] - 1;
        for( int i = 0; i < out[u].size(); i++ )
        {
            // try undoing edge v->u
            LL v = out[u][i];
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

LL mincost( LL n, LL s, LL t, LL &fcost ,LL lim,LL mul)
{
    //clear the vector
    for (int i=0;i<n;++i){
        out[i].clear();
    }

    // build the adjacency list
    for( int i = 0; i < n; i++ )
        for( int j = 0; j < n; j++ )
            if( cap[i][j] || cap[j][i] ){
                cap[i][j]*=mul;
                out[i].PB(j);
            }


    memset(fnet,0,sizeof(fnet));
    memset(pi,0,sizeof(pi));
    LL flow = fcost = 0;

    // repeatedly, find a cheapest path from s to t
    while( dijkstra( n, s, t ) && lim>0  )
    {
        // get the bottleneck capacity
        LL bot = INT_MAX;
        for( int v = t, u = par[v]; v != s; u = par[v = u] )
            bot =min(bot, fnet[v][u] ? fnet[v][u] : ( cap[u][v] - fnet[u][v] ) );

        // update the flow network
        for( int v = t, u = par[v]; v != s ; u = par[v = u] )
            if( fnet[v][u] ) { fnet[v][u] -= bot; fcost -= min(lim,bot) * cost[v][u]; }
            else { fnet[u][v] += bot; fcost += min(lim,bot) * cost[u][v]; }

        lim-=bot;
        flow += bot;
    }
    return flow;
}


int main(){
    FRO

    LL vertex,edge,kase;

    while ( scanf("%lld %lld",&vertex,&edge)==2  ) {

        memset( cap, 0, sizeof( cap ) );

        LL  a, b, c,cp,lim;


        // fill up cap with existing capacities.
        // if the edge u->v has capacity 6, set cap[u][v] = 6.
        // for each cap[u][v] > 0, set cost[u][v] to  the
        // cost per unit of flow along the edge i->v
        for (int i=0; i<edge; i++) {
            scanf("%lld %lld %lld",&a,&b,&cp);
            cost[a][b] = cp;  cost[b][a] = cp;
            cap[a][b] = 1;  cap[b][a] = 1;
        }

        LL fcost;
        LL mul;
        scanf("%lld %lld",&lim,&mul);

        LL flow = mincost( vertex+1, 1, vertex, fcost,lim, mul );

        if ( flow>=lim ){
            printf("%lld\n",fcost);
        }else{
            printf("Impossible.\n");
        }

    }
    return 0;
}

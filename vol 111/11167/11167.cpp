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

#define SIZE 1500

vector<int> out[SIZE];
int cap[SIZE][SIZE];

int q[SIZE],prev[SIZE];


bool bfs( int s,int t  ){
    // find an augmenting path
    memset( prev, -1, sizeof( prev ) );
    int qf = 0, qb = 0;
    prev[q[qb++] = s] = -2;
    while( qb > qf && prev[t] == -1 )
        for( int u = q[qf++], i = 0, v; i < out[u].size(); i++ )
            if( prev[v = out[u][i]] == -1 && cap[u][v] )
                prev[q[qb++] = v] = u;

    // see if we're done
    return  prev[t] != -1;
}

int dinic( int n, int s, int t ){
    int flow = 0;
    while( bfs( s,t ) ){

        // try finding more paths
        for( int z = 0; z < n; z++ ) {
            if( cap[z][t] && prev[z] != -1 ){
                int bot = cap[z][t];
                for( int v = z, u = prev[v]; u >= 0; v = u, u = prev[v] )
                    bot = (bot>cap[u][v])?cap[u][v]:bot;
                if( !bot ) continue;

                cap[z][t] -= bot;
                cap[t][z] += bot;


                for( int v = z, u = prev[v]; u >= 0; v = u, u = prev[v] ){
                    cap[u][v] -= bot;
                    cap[v][u] += bot;

                }
                flow += bot;
            }
        }
    }
    return flow;
}



int main(){

    int source=0,sink;

    while( scanf("%d %d",&left,&ff)==2 && left ){

        for (int i=0;i<left;++i){

        }

    }

    return 0;
}

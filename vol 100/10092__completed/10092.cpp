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
    FRO
    int source=0,left,right,sink;

    while( scanf("%d %d",&left,&right)==2 && (left+right) ){

        sink=left+right+1;

        for (int i=0;i<=sink+1;++i){
            out[i].clear();
        }

        for (int i=0;i<=sink+1;++i){
            for (int j=0;j<=sink+1;++j){
                cap[i][j]=0;
            }
        }

        int tmp,v,w,sum=0;
        for (int i=1;i<=left;++i){
            scanf("%d",&w);
            //printf("%d\n",w);
            sum+=w;
            cap[source][i]=/*cap[i][source]=*/w;

            out[source].PB(i);
            out[i].PB(source);
        }
        for (int i=1;i<=right;++i){
            scanf("%d",&tmp);
            while( tmp-- ){
                scanf("%d",&v);
                /*cap[left+i][v]=*/cap[v][left+i]=1;
                out[left+i].PB(v);
                out[v].PB(left+i);
            }
            cap[left+i][sink]=/*cap[sink][left+i]=*/1;
            out[left+i].PB(sink);
            out[sink].PB(left+i);
        }


        if ( dinic(sink+1,source,sink) >= sum ){
            printf("1\n");

            for (int i=1;i<=left;++i){
                bool on=false;
                for (int j=0;j<out[i].size();++j){

                    if ( cap[ i ][ out[i][j] ]==0 ){
                        if ( on )printf(" %d",out[i][j]-left);
                        else{
                            printf("%d",out[i][j]-left);
                            on=true;
                        }
                    }
                }
                printf("\n");
            }

        }else{
            printf("0\n");
        }

    }

    return 0;
}

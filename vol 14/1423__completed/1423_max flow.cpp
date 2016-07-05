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

#define SIZE 50

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

char line[1000];

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){
        int dim;
        scanf("%d %s",&dim,line);

        int cnt=0;
        int source=0,sink=dim+1;
        NEG(cap);
        for (int i=1;i<=dim;++i){
            char save=line[cnt];
            for (int j=i;j<=dim;++j){

                if ( line[cnt]  == '-' ){
                    cap[ i-1 ][ j ] = -10;
                }else if ( line[cnt] == '+' ){
                    cap[ i-1 ][ j ] = 1;
                }else{
                    cap[i-1][j] = 0;
                }

            }

            if ( save  == '-' ){
                cap[ i ][ sink ] = -10;
            }else if ( save == '+' ){
                cap[ i ][ sink ] = 1;
            }else{
                cap[ i ][sink] = 0;
            }

            cnt++;
        }

        for (int i=source;i<=sink+1;++i){
            out[i].clear();
        }

        for (int i=source;i<=sink;++i){
            for (int j=source;j<=sink;++j){
                if ( cap[i][j] == -1 ){
                    cap[i][j]=0;
                }else {
                    cap[i][j]+= 20;
                    out[i].PB(j);
                    out[j].PB(i);
                }
                printf("%3d",cap[i][j]);
            }printf("\n");
        }

        cout<<dinic(sink+1,source,sink)<<endl;;

        for (int i=1;i<=dim;++i){
            if ( i!= 1 )printf(" ");
            //printf("%d",cap[source][i]-cap[source][i-1]-20);
            printf("%d",cap[i][sink]-cap[i-1][sink]-10);
        }
        printf("\n\n");

    }


    return 0;
}

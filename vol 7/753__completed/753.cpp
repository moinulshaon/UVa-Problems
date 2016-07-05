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

#define SIZE 410

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

    while( bfs( s,t )  ){

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

    //ios::sync_with_stdio(false);

    int kase;
    cin>>kase;

    while ( kase-- ){

        for (int i=0;i<SIZE;++i){
            out[i].clear();
        }

        CLR(cap);
        int source=0,sink=1;

        int node=2;
        map<string,int> mp;

        int already;
        cin>>already;

        string tmp;
        while ( already-- ){
            cin>>tmp;
            if ( mp.find(tmp)==mp.end() ){
                mp[ tmp ]=node++;
            }
            if ( cap[ mp[ tmp ] ][sink] == 0 ){
                int save=mp[ tmp ];
                cap[ save ][sink]++;
                out[ save ].PB( sink );
                out[ sink ].PB( save );
            }else{
                cap[ mp[ tmp ] ][sink]++;
            }

        }

        int need;
        cin>>need;
        for (int i=0;i< need;++i ){
            cin>>tmp;
            cin>>tmp;

            if ( mp.find(tmp)==mp.end() ){
                mp[ tmp ]=node++;
            }

            if ( cap[source][ mp[ tmp ] ] == 0 ){
                int save=mp[ tmp ];
                cap[source][ save ]++;
                out[ save ].PB( source );
                out[ source ].PB( save );
            }else{
                cap[ source ][ mp[ tmp ] ]++;
            }

        }
        int convertor;
        cin>>convertor;

        string tt;
        while( convertor-- ){
            cin>>tmp>>tt;
            if ( mp.find(tmp)==mp.end() ){
                mp[ tmp ]=node++;
            }
            if ( mp.find(tt)==mp.end() ){
                mp[ tt ]=node++;
            }
            //printf("%d %d\n",mp[tmp],mp[tt]);
            cap[ mp[tmp] ][ mp[tt] ]= (1<<20);
            out[ mp[tmp] ].PB( mp[tt] );
            out[ mp[tt] ].PB( mp[tmp] );

        }



        cout<<need-dinic(node+1,source,sink)<<endl;
        if ( kase )cout<<'\n';

    }


    return 0;
}

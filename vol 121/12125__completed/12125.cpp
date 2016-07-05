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

#define SIZE 205

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

pair<double,double> point[110];
int save[SIZE][SIZE];

#define IN(x) ( 2*(x) )
#define OUT(x) ( 2*(x)+1 )

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n;
        double dd;
        scanf("%d %lf",&n,&dd);

        CLR(cap);

        int source=0,sink=OUT(n)+1;
        for (int i=0;i<=sink;++i){
            out[i].clear();
        }

        int a,b,ans=0;
        for (int i=1;i<=n;++i){
            scanf("%lf %lf %d %d",&point[i].first,&point[i].second,&a,&b);
            cap[ source ][ IN(i) ]= a;
            ans+=a;
            out[source].PB( IN(i) );
            out[IN(i)].PB( source );

            cap[ IN(i) ][OUT(i)]= b;
            out[ IN(i) ].PB( OUT(i) );
            out[ OUT(i) ].PB( IN(i) );
        }

        for (int i=1;i<=n;++i){
            for (int j=i+1;j<=n;++j){
                if ( sqrt( pow(point[i].first-point[j].first,2)
                          + pow(point[i].second-point[j].second,2) )<dd+1e-6 ){
                    cap[ OUT(i) ][ IN(j) ]=10000;

                    cap[ OUT(j) ][ IN(i) ]=10000;

                    out[ OUT(i) ].PB( IN(j) );
                    out[ IN(j) ].PB( OUT(i) );

                    out[ OUT(j) ].PB( IN(i) );
                    out[ IN(i) ].PB( OUT(j) );
                    //cout<<"ok "<<i<<' '<<j<<endl;
                }
            }
        }

        //printf("Case %d:",kk);
        bool ok=false;
        for (int i=1;i<=n;++i){

            memcpy( save,cap,sizeof(save) );

            cap[ IN(i) ][ sink ] = 10000;

            out[ IN(i) ].PB( sink );
            out[ sink ].PB( IN(i) );

            //cout<<dinic( sink+1,source,sink )<<' '<<ans<<endl;
            if ( dinic( sink+1,source,sink )>=ans ){
                if ( ok )printf(" ");
                printf("%d",i-1);
                ok=true;
            }

            memcpy( cap,save,sizeof(save) );
        }
        if ( !ok )printf("-1");

        printf("\n");

    }

    return 0;
}

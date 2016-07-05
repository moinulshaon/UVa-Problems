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

#define SIZE 410

#define in(p) ( 2*(p) )
#define ex(p) ( 2*(p)+1 )

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

    for (int i=0;i<n;++i){
        out[i].clear();
    }

    for (int i=0;i<n;++i){
        for (int j=i;j<n;++j){
            if ( cap[i][j] >0 || cap[j][i]>0 ){
                out[i].PB( j );
                out[j].PB( i );
            }
        }
    }

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

int dis,nn;
int pos[SIZE];
bool big[SIZE];

int calc( int x,int y ){
    return abs( pos[x]-pos[y] );
}

void build( int s,int f,int lim ){

    for (int i=0;i<=f;++i){
        for (int j=0;j<=f;++j){
            cap[i][j]=0;
        }
    }

    for (int i=0;i<=f;++i){
        cap[ in(i) ][ ex(i) ]=1+( big[i] ?10000:0 );

    }

    for (int i=0;i<=f;++i){
        for (int j=i+1;j<=f;++j){
            if ( calc(i,j)<=lim ){
                cap[ ex(i) ][ in(j) ]= 10000 ;

            }
        }
    }

}

int main(){

    //FRO
    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&nn,&dis);
        char tmp[10],tt;
        CLR(big);
        for (int i=1;i<=nn;++i){
            scanf("%s",tmp);
            sscanf(tmp,"%c%*c%d",&tt,&pos[i]);
            if ( tt=='B' ){
                big[i]=true;
            }else{
                big[i]=false;
            }
        }

        int source=0,sink=nn+1;
        big[source]=true;
        big[sink]=true;

        pos[source]=0;
        pos[sink]=dis;

        int ans= -1,low=0,high=(1<<30);

        while( low<=high ){
            int mid=(low+high)/2;
            build( 0, ex(sink) ,mid );
            //printf("shaon 1\n");

            if ( dinic( ex(sink)+1,ex(source),in(sink) ) >=2 ){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        printf("Case %d: %d\n",kk,ans);

    }



    return 0;
}

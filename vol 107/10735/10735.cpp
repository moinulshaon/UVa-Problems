#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef long long LL;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;
//find_by_order
//order_of_key

#define FO(i,a,b) for (int i = (a); i < (b); i++)

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );
#define ALL(v) v.begin(),v.end()

#define X first
#define Y second
#define MP make_pair

typedef pair<int,int> pint;
typedef map<int,int> mint;

void show() {cout<<'\n';}
template<typename T,typename... Args>
void show(T a, Args... args) { cout<<a<<" "; show(args...); }
template<typename T>
void show_c(T& a) { for ( auto &x:a ){ cout<<x<<" ";}cout<<endl;  }

#define SIZE 105


vector<int> out[SIZE];
int cap[SIZE][SIZE];

int q[SIZE],prv[SIZE];


bool bfs( int s,int t  ){
    // find an augmenting path
    memset( prv, -1, sizeof( prv ) );
    int qf = 0, qb = 0;
    prv[q[qb++] = s] = -2;
    while( qb > qf && prv[t] == -1 )
        for( int u = q[qf++], i = 0, v; i < out[u].size(); i++ )
            if( prv[v = out[u][i]] == -1 && cap[u][v] )
                prv[q[qb++] = v] = u;

    // see if we're done
    return  prv[t] != -1;
}

int dinic( int n, int s, int t ){

    for (int i=0;i<n;++i){
        out[i].clear();
    }

    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            if ( cap[i][j]>0 || cap[j][i] >0 ){
                out[i].PB( j );
            }
        }
    }

    int flow = 0;
    while( bfs( s,t ) ){

        // try finding more paths
        for( int z = 0; z < n; z++ ) {
            if( cap[z][t] && prv[z] != -1 ){
                int bot = cap[z][t];
                for( int v = z, u = prv[v]; u >= 0; v = u, u = prv[v] )
                    bot = (bot>cap[u][v])?cap[u][v]:bot;
                if( !bot ) continue;

                cap[z][t] -= bot;
                cap[t][z] += bot;


                for( int v = z, u = prv[v]; u >= 0; v = u, u = prv[v] ){
                    cap[u][v] -= bot;
                    cap[v][u] += bot;

                }
                flow += bot;
            }
        }
    }
    return flow;
}


struct Edge{
    int u,v;
};
Edge dir[5*SIZE];
Edge undir[5*SIZE];

int outdeg[SIZE];
int indeg[SIZE];

int ini[SIZE][SIZE];


set<int> edge[SIZE];
set<int> edge2[SIZE];
vector<int> path;

int adj2[SIZE][SIZE];
int adj[SIZE][SIZE];

void dfs(int x){
    for (auto&y:edge[x]){
        if ( adj[x][y] >0 ){
            adj[x][y]--;
            dfs( y );
        }
    }
    for (auto&y:edge2[x]){
        if ( adj2[x][y] >0 ){
            adj2[x][y]--;
            adj2[y][x]--;
            dfs( y );
        }
    }
    path.PB( x );
}

void add_edge(int x,int y){
    edge[y].insert( x );
    adj[y][x]++;
}
void add_edge2(int x,int y){
    edge2[y].insert( x );
    edge2[x].insert( y );
    adj2[y][x]++;
    adj2[x][y]++;
}


const int inf = 1000000;

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){

        int n,m;
        scanf("%d %d",&n,&m);

        int cnt = 0;
        int u,v;

        int A = 0,B=0;
        char str[10];
        while ( m-- ){
            scanf("%d %d %s",&u,&v,&str);
            if ( str[0] == 'D' ){
                dir[A++] = {u,v};
            }else{
                undir[B++] = {u,v};
            }
        }

        FO( i,1,n+1 ){
            indeg[i] = 0;
            outdeg[i] = 0;
        }
        FO( i,0,A ){
            outdeg[ dir[i].u ]++;
            indeg[ dir[i].v ]++;
        }
        FO(i,1,n+1){
            int tmp = min( outdeg[i],indeg[i] );
            outdeg[i] -= tmp;
            indeg[i] -= tmp;
        }

        int sumo = 0;
        int sumi = 0;
        FO (i,1,n+1){
            sumo += outdeg[i];
            sumi += indeg[i];
        }


        int source= 0;
        int sink= n+1;

        FO(i,0,sink+1)FO( j,0,sink+1 )ini[i][j] = 0;

        for (int i=1;i<=n;++i){
            if ( indeg[i] >0 ){
                ini[source][i] = indeg[i];
            }
            if ( outdeg[i] >0 ){
                ini[i][sink] = outdeg[i];
            }
        }

        for( int i=0;i<B;++i ){
            u=undir[i].u;
            v=undir[i].v;

            ini[u][v]++;
            ini[v][u]++;

        }

        FO(i,0,sink+1)FO( j,0,sink+1 )cap[i][j] = ini[i][j];

        int flow = dinic( sink+1,source,sink );

        FO(i,1,n+1)FO( j,1,n+1 ){
            adj[i][j] = 0;
            adj2[i][j] = 0;
        }
        FO(i,1,n+1){
            edge[i].clear();
            edge2[i].clear();
        }

        for (int i=0;i<A;++i){
            add_edge( dir[i].u ,dir[i].v );
        }

        for (int i=0;i<B;++i){
            u=undir[i].u;
            v=undir[i].v;
            if ( cap[u][v] < ini[u][v] ){
                add_edge( u,v );
                ini[u][v]--;
            }else if( cap[v][u] < ini[v][u] ){
                add_edge( v,u );
                ini[v][u]--;
            }else{
                add_edge2( u,v );
            }
        }


        bool pos = true;
        for (int i=1;i<=n;++i){

            int sum = 0;
            for (int j=1;j<=n;++j){
                sum += adj[i][j];
            }
            for (int j=1;j<=n;++j){
                sum -= adj[j][i];
            }
            if ( sum != 0 ){
                pos = false;
            }
        }

        if ( !pos ){
            printf("No euler circuit exist\n");
            if ( kase )printf("\n");
            continue;
        }

        path.clear();
        dfs( 1 );
        for (int i=0;i<path.size();++i){
            if ( i )printf(" ");
            printf("%d",path[i]);
        }printf("\n");
        if ( kase )printf("\n");
    }

    return 0;
}

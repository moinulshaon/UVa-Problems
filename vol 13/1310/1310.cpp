#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

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


#define SIZE 2010


struct BRG{

    vector<int> out[SIZE];
    int level[SIZE];
    int low[SIZE];

    vector<pint> vault;
    bool bridge[SIZE][SIZE];

    void dfs( int x ){
        //printf("%d %d\n",x,level[x]);
        low[x]=level[x];
        int y;
        for (int i=0;i<out[x].size();++i){
            y=out[x][i];
            if ( level[ y ]== -1 ){

                level[ y ]=level[x]+1;

                dfs( y );

                low[x]=min( low[x],low[y] );

                if ( low[y]>=level[x] ){
                    bridge[x][y] = bridge[y][x] = true;
                    vault.PB( MP(x,y) );
                }
            }else if ( level[y]< level[x]-1 ){
                low[x]=min( low[x],level[y] );
            }
        }
    }
    void add_edge(int x,int y){
        out[x].PB( y );
        out[y].PB( x );
    }
    void ini(){
        for (auto&p:vault){
            bridge[p.X][p.Y]= bridge[p.Y][p.X]=false;
        }
        vault.clear();
        NEG(level);
        for (int i=0;i<SIZE;++i){
            out[i].clear();
        }
    }

}super;

struct SCC{

    vector <int> out [SIZE];
    vector <int> rev [SIZE];
    bool vis [SIZE];
    vector <int> stk;
    int component [SIZE];
    int order[SIZE];

    void ini(){
        for (int i=0;i<SIZE;++i){
            out[i].clear();
            rev[i].clear();
        }
        CLR(vis);
        stk.clear();
    }


    void dfs1 (int x){
        vis [x] = true;
        for ( int u = 0; u < out [x].size (); u++ )
            if ( !vis [ out [x] [u]] )
                dfs1 (out [x] [u]);

        stk.push_back (x);
        order[x] = stk.size();
    }

    void dfs2 (int x, int c){
        vis [x] = false;
        component [x] = c;

        for ( int u = 0; u < rev [x].size (); u++ )
            if ( vis [rev [x] [u]] )
                dfs2 (rev [x] [u], c);
    }
    void add_edge(int x,int y){
        out[x].PB( y );
        rev[y].PB( x );
    }

}graph;

vector<pint> candidate;

int main(){

    FRO

    int n,m;
    while ( scanf("%d %d",&n,&m)==2 ){

        graph.ini();
        candidate.clear();

        int u,v,t;
        while ( m-- ){
            scanf("%d %d %d",&u,&v,&t);
            if ( t == 1 ){
                graph.add_edge(u,v);
            }else{
                candidate.PB( MP(u,v) );
            }
        }


        for (int i=1;i<=n;++i){
            if ( !graph.vis[i] ){
                graph.dfs1(i,);
            }
        }
        int com = 0;
        for (int i=graph.stk.size()-1;i>=0;--i){
            if ( graph.vis[ graph.stk[i] ] ){
                graph.dfs2( graph.stk[i],++com );
            }
        }

        super.ini();

        for (auto&e:candidate){
            if ( graph.component[ e.X ] != graph.component[ e.Y ]  ){
                super.add_edge( graph.component[ e.X ],graph.component[ e.Y ] );
            }
        }

        for (int i=1;i<=com;++i){
            if ( super.level[i] == -1 ){
                super.dfs( i );
            }
        }

        show( super.vault.size() );

        for (auto&e:candidate){
            if ( graph.component[ e.X ] != graph.component[ e.Y ]  ){
                if ( super.bridge[ graph.component[ e.X ] ][ graph.component[ e.Y ] ] ){
                    printf("%d %d 2\n",e.X,e.Y);
                }else{
                    if ( graph.order[e.X] > graph.order[e.Y] ){
                        printf("%d %d 1\n",e.X,e.Y);
                    }else{
                        printf("%d %d 1\n",e.Y,e.X);
                    }
                }
            }else{
                printf("d %d 1\n",e.X,e.Y);
            }
        }

    }

    return 0;
}

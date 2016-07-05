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



#define SIZE 1010

struct u_find{
    int parent[SIZE];
    int size[SIZE];
    void ini(int n){
        for (int i=1;i<=n;++i){
            parent [i] = i;
            size[i]=1;
        }
    }
    int parentOf (int n){
        if ( n == parent [n] ) return n;
        return parent [n] = parentOf (parent [n]);
    }
    void make_union(int x,int y){
        int p = parentOf (x);
        int q = parentOf (y);

        if ( p != q ) {
            if (size[p]>size[q])swap(p,q);
            size[q]+=size[p];
            parent [p] = q;
        }
    }
}tree;

vector<int> out[SIZE];
int level[SIZE];
int low[SIZE];

bool bridge[SIZE][SIZE];

void dfs( int x ){

    low[x]=level[x];
    int y;
    for (int i=0;i<out[x].size();++i){
        y=out[x][i];
        if ( level[ y ]== -1 ){

            level[ y ]=level[x]+1;

            dfs( y );

            low[x]=min( low[x],low[y] );

            if ( low[y]>level[x] ){
                bridge[x][y] = bridge[y][x] = true;
            }
        }else if ( level[y]< level[x]-1 ){
            low[x]=min( low[x],level[y] );
        }
    }
}

int deg[SIZE];

int main(){

    FRO

    int n,m;
    while ( scanf("%d %d",&n,&m)==2 ){
        int u,v;
        tree.ini(n);
        for (int i=1;i<=n;++i){
            out[i].clear();
            for (int j=1;j<=n;++j){
                bridge[i][j] = false;
            }
        }

        while ( m-- ){
            scanf("%d %d",&u,&v);
            out[u].PB( v );
            out[v].PB( u );
        }

        NEG( level );
        for (int i=1;i<=n;++i){
            if ( level[i] == -1 ){
                dfs(i);
            }
        }

        CLR(deg);
        for (int x=1;x<=n;++x){
            for ( auto&y:out[x] ){
                if ( !bridge[x][y] ){
                    tree.make_union(x,y);
                }
            }
        }
        for (int x=1;x<=n;++x){
            for ( auto&y:out[x] ){
                if ( tree.parentOf( x ) != tree.parentOf( y ) ){
                    deg[tree.parentOf(x)]++;
                }
            }
        }

        int zero = 0,one=0;
        int cnt = 0;
        for (int i=1;i<=n;++i){
            if ( tree.parentOf(i) == i  ){
                if ( deg[i]==0 )zero++;
                else if ( deg[i] == 1 )one++;
                cnt++;
            }
        }
        if ( cnt == 1 )printf("0\n");
        else  printf("%d\n",zero+one/2+one%2);

    }

    return 0;
}


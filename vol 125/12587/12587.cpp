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

#define SIZE 10100


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
}dsu;

vector<int> out[SIZE];
vector<int> weight[SIZE];

LL ini[SIZE];

int level[SIZE];
int low[SIZE];

int subtree[SIZE];
int n;

vector<pair<int,LL>>  lowp[SIZE];
vector<pair<int,LL>>  highp[SIZE];

bool cover[SIZE];
int ind;
void add_edge(int x,int y,LL w){

    lowp[y].PB( MP(ind,w) );
    highp[x].PB( MP(ind,w) );

    ind++;
}


void dfs( int x ){
    //printf("%d %d\n",x,level[x]);
    low[x]=level[x];
    subtree[x] = 1;
    int y;
    for (int i=0;i<out[x].size();++i){
        y=out[x][i];
        if ( level[ y ]== -1 ){

            level[ y ]=level[x]+1;

            dfs( y );

            low[x]=min( low[x],low[y] );

            if ( low[y]>level[x] ){
                add_edge( x,y,LL(weight[x][i])* subtree[y]*( dsu.size[ dsu.parentOf(x) ]-subtree[y] ) );
            }
            subtree[x] += subtree[y];
        }else if ( level[y]< level[x]-1 ){
            low[x]=min( low[x],level[y] );
        }

    }

}

pint ser[SIZE];

bool cmp( const pint &a,const pint &b ){
    return a.Y>b.Y;
}

LL cost[SIZE];

bool pos(LL mid){

    for (int i=1;i<=n;++i){
        cost[i] = ini[i];
        if ( cost[i] > mid )return false;
    }

    for (int i=0;i<ind;++i){
        cover[i]=false;
    }

    for (int i=1;i<=n;++i){
        int &x = ser[i].X;

        for ( auto&p:highp[x] ){
            if ( !cover[p.X] && cost[x]+p.Y <= mid ){
                cost[x]+= p.Y;
                cover[p.X] = true;
            }
        }

        for ( auto&p:lowp[x] ){
            if ( !cover[p.X] && cost[x]+p.Y <= mid ){
                cost[x]+= p.Y;
                cover[p.X] = true;
            }
        }

    }

    for (int i=0;i<ind;++i){
        if ( !cover[i] ){
            return false;
        }
    }
    return true;
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        int m;
        scanf("%d %d",&n,&m);

        for (int i=0;i<=n;++i){
            out[i].clear();
            weight[i].clear();
            lowp[i].clear();
            highp[i].clear();
        }
        dsu.ini(n);
        ind = 0;

        for (int i=1;i<=n;++i){
            scanf("%lld",&ini[i]);
        }

        int u,v,w;
        while ( m-- ){
            scanf("%d %d %d",&u,&v,&w);

            dsu.make_union( u,v );

            out[u].PB( v );
            weight[u].PB( w );

            out[v].PB( u );
            weight[v].PB( w );

        }

        memset( level,-1,sizeof(level));

        for (int i=1;i<=n;++i){
            if ( level[i] == -1 ){
                level[i] = 0;
                dfs(i);
           }
        }

        for (int i=1;i<=n;++i){
            ser[i]= MP( i,level[i] );
        }
        sort( ser+1,ser+n+1,cmp );

        LL low = 0,high = (1LL<<35);
        LL ans = 0;
        while ( low<=high ){
            LL mid = (low+high)/2;
            if ( pos(mid) ){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }


        printf("Case %d: %lld\n",kk,ans);
    }

    return 0;
}

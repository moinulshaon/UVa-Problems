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
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 10100

vector<int> out[SIZE];
int level[SIZE];
int low[SIZE];


int parent[SIZE];
int size[SIZE];

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

            if (  low[y]>level[x] ){
                make_union(x,y);
            }
        }else if ( level[y]< level[x]-1 ){
            low[x]=min( low[x],level[y] );
        }

    }

}

int main(){

    FRO

    int n,m,q;

    while ( scanf("%d %d %d",&n,&m,&q)==3 && (n+m+q) ){

        for (int i=1;i<=n;++i){
            out[i].clear();
            parent[i] = i;
            size[i] = 1;
        }
        NEG(level);


        int u,v;
        while ( m-- ){
            scanf("%d %d",&u,&v);
            out[u].PB( v );
            out[v].PB( u );
        }

        for (int i=1;i<=n;++i){
            if ( level[i] == -1 ){
                level[i] = 0;
                dfs(i);
            }
        }

        while ( q-- ){
            scanf("%d %d",&u,&v);
            if ( parentOf(u) == parentOf(v) ){
                printf("Y\n");
            }else{
                printf("N\n");
            }
        }
        printf("-\n");

    }


    return 0;
}

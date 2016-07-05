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

#define MAX 20010
#define NIL 0
#define INF (1<<28)

vector <int> G[MAX];
int n,m, match[MAX], dist[MAX];

bool bfs() {
    int i, u, v, len;
    queue< int > Q;
    for(i=1; i<=n; i++) {
        if(match[i]==NIL) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u!=NIL) {
            len = G[u].size();
            for(i=0; i<len; i++) {
                v = G[u][i];
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}

bool dfs(int u) {
    int i, v, len;
    if(u!=NIL) {
        len = G[u].size();
        for(i=0; i<len; i++) {
            v = G[u][i];
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int matching = 0, i;
    memset(match,0,sizeof(match));
    while(bfs())
        for(i=1; i<=n; i++)
            if(match[i] == NIL && dfs(i))
                matching++;
    return matching;
}

int num[MAX];
int lim;


void calc( int x ){
    num[x] = ++n;
    for (int i=0;i<15;++i){
        if ( ( x & (1<<i) ) && x+(1<<i) <= lim && num[ x+(1<<i) ] == 0 ){
            calc( x+(1<<i) );
        }
    }
}

bool vis[MAX];

void build( int x ){
    vis[x] = true;
    for (int i=0;i<15;++i){
        if ( ( x & (1<<i) ) && x+(1<<i) <= lim ){
            G[ num[x] ].PB( n+num[ x+(1<<i) ] );
            if ( !vis[ x+(1<<i) ] ){
                build( x+(1<<i) );
            }
        }
    }
}

int arr[MAX];

int main(){


    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        CLR(num);

        n = 0;

        int x;
        scanf("%d %d",&x,&lim);

        for (int i=0;i<x;++i){
            scanf("%d",&arr[i]);
            if ( arr[i] <=lim )
                calc( arr[i] );
        }

        for (int i=0;i<=2*n+1;++i){
            G[i].clear();
        }

        CLR(vis);
        for (int i=0;i<x;++i){
            if ( arr[i]<=lim ){
                build( arr[i] );
            }
        }

        printf("Case %d: %d\n",kk,n-hopcroft_karp());
    }


    return 0;
}

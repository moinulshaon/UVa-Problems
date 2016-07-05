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

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define MAX 100
#define NIL 0
#define INF (1<<28)

vector <int> G[MAX];
int n,m, match[MAX], dist[MAX];
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = NIL[0] ? G1[G[1---n]] ? G2[G[n+1---n+m]]

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
    // match[] is assumed NIL for all vertex in G
    while(bfs())
        for(i=1; i<=n; i++)
            if(match[i]==NIL && dfs(i))
                matching++;
    return matching;
}

int row;
char board[10][10];

int func( int r,int c ){
    return r*row+c+1;
}

pint num[10][10];

int main(){

    FRO

    while ( scanf("%d",&row) == 1 && row ){
        int col= row;

        for (int i=0;i<row;++i){
            scanf("%s",board[i]);
        }

        for (int i=0;i<MAX;++i){
            G[i].clear();
        }

        int tmp=1;
        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( board[i][j] == 'X' ){
                    tmp++;
                }else{
                    num[i][j].first = tmp;
                }
            }
            tmp++;
        }
        tmp-- ;

        n=tmp;

        tmp=1;
        for (int i=0;i<col;++i){
            for (int j=0;j<row;++j){
                if ( board[j][i] == 'X' ){
                    tmp++;
                }else{
                    num[j][i].second = tmp;
                }
            }
            tmp++;
        }
        tmp-- ;
        m=tmp;


        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( board[i][j] == '.' ){
                    G[ num[i][j].first ].PB( n+ num[i][j].second );
                    //printf("%d %d\n",num[i][j].first,num[i][j].second);
                }
            }
        }

        printf("%d\n",hopcroft_karp());

    }


    return 0;
}

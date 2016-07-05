#include <vector>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 1000
#define NIL 0
#define INF (1<<28)

vector <int> G[MAX];
int n, match[MAX], dist[MAX];
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

char board[50][50];
int dr[]={-1,0,1,0};
int dc[]={0,-1,0,1};
int row,col;

int mark[50][50];

inline bool isLeft(int r,int c){
    if ( (r+c)%2==0 )return true;
    else return false;
}
int main(){

    freopen("in.txt","r",stdin);

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&row,&col);


        for (int i=1;i<=MAX;++i)
            G[i].clear();
        for (int i=0;i<row;++i){
            scanf("%s",board[i]);
        }
        int tmp=1;
        for (int i=0;i<row;++i){
            for (int j=0;j<col;j+=2){
                mark[i][j]=mark[i][j+1]=tmp++;
            }
        }
        n=mark[row-1][col-1];

        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( board[i][j]=='*' ){
                    if ( isLeft(i,j) ){
                        for (int k=0;k<4;++k){
                            if ( i+dr[k]>=0 && i+dr[k]<row && j+dc[k]>=0 && j+dc[k]<col && board[ i+dr[k] ][ j+dc[k] ]=='*' ){
                                G[ mark[i][j] ].push_back( n+mark[ i+dr[k] ][ j+dc[k] ] );
                            }
                        }
                    }
                }
            }
        }

        int cnt=0;
        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( board[i][j]=='*' )
                    ++cnt;
            }
        }

        printf("%d\n",cnt-hopcroft_karp());

    }
    return 0;

}

#include <vector>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 2100
#define NIL 0
#define INF (1<<28)

vector <int> G[MAX];
int n, match[MAX], dist[MAX];
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = NIL[0] ? G1[G[1---n]] ? G2[G[n+1---n+m]]


int q[MAX];

bool bfs() {
    int i, u, v, len;
    int top=0;

    for(i=1; i<=n; i++) {
        if(match[i]==NIL) {
            dist[i] = 0;
            q[top++]=i;
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(top) {
        u = q[--top];
        if(u!=NIL) {
            len = G[u].size();
            for(i=0; i<len; i++) {
                v = G[u][i];
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;

                    q[top++]=match[v];
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


int main(){

    //freopen("in.txt","r",stdin);

    int kase,a,b,m;
    scanf("%d",&kase);

    while (kase--){
        scanf("%d %d",&n,&m);


        for (int i=1;i<=n;++i)
            G[i].clear();






        for (int j=1;j<=m;++j){
            scanf("%d %d",&a,&b);

            G[a].push_back(n+b);


        }
        printf("%d\n",n-hopcroft_karp());


    }
    return 0;

}

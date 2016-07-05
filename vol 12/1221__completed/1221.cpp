#include <vector>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 600
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
int hum[MAX][2],all[MAX][2];
int dis[MAX][MAX];

typedef long long LL;

void build( int mid ){

    for (int i=1;i<=n;++i){
        G[i].clear();
    }

    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if ( hum[i][0]+LL(hum[i][1])*(mid-dis[i][j]) >= all[j][0]+ LL(all[j][1])*( mid )  ){
                G[i].push_back( n+j );
            }
        }
    }
}

int main(){

    freopen("in.txt","r",stdin);

    while (scanf("%d %d",&n,&m)==2 && (n+m) ){

        for (int i=1;i<=n;++i){
            scanf("%d %d",&hum[i][0],&hum[i][1]);
        }

        for (int i=1;i<=m;++i){
            scanf("%d %d",&all[i][0],&all[i][1]);
        }

        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                scanf("%d",&dis[i][j]);
            }
        }

        int mid,ans=-1,low=0,high=(1<<29);

        while( low<=high ){
            mid=(low+high)/2;

            build(mid);

            //printf("%d\n",hopcroft_karp());
            if ( hopcroft_karp()>=m ){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        if ( ans<0 ){
            printf("IMPOSSIBLE\n");
        }else{
            printf("%d\n",ans);
        }
    }
    return 0;

}

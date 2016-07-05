#include <vector>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 300
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


int main(){

    freopen("in.txt","r",stdin);

    int kase,a,b,m;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){



        for (int i=1;i<=n;++i)
            G[i].clear();

        vector<int>line1;
        vector<int>line2;


        scanf("%d",&n);
        for (int i=0;i<n;++i){
            scanf("%d",&a);

            line1.push_back(a);
        }
        scanf("%d",&m);

        for (int i=0;i<m;++i){
            scanf("%d",&a);

            line2.push_back(a);


        }


        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                if ( (line1[i] &&  line2[j]%line1[i]==0) || (line1[i]==0 && line2[j]==0) ) {
                    G[ i+1 ].push_back( n+j+1 );
                }
            }
        }


        printf("Case %d: %d\n",kk,hopcroft_karp());


    }
    return 0;

}

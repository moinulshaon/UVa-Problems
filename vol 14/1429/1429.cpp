#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define N 2005
using namespace std;

vector <int> outarrow [N + 10];
vector <int> inarrow [N + 10];
bool vis [N + 10];
vector <int> stk;
int component [N + 10];



void dfs1 (int x){
	vis [x] = true;
	for ( int u = 0; u < outarrow [x].size (); u++ )
		if ( !vis [ outarrow [x] [u]] )
            dfs1 (outarrow [x] [u]);
	stk.push_back (x);
}

void dfs2 (int x, int c){
	vis [x] = false;
	component [x] = c;
	for ( int u = 0; u < inarrow [x].size (); u++ )
		if ( vis [inarrow [x] [u]] )
            dfs2 (inarrow [x] [u], c);
}

#define MAX 2005
#define NIL 0
#define INF (1<<28)

vector <int> G[MAX];
int total, match[MAX], dist[MAX];
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = NIL[0] ? G1[G[1---n]] ? G2[G[n+1---n+m]]

bool bfs() {
    int i, u, v, len;
    queue< int > Q;
    for(i=1; i<=total; i++) {
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
        for(i=1; i<=total; i++)
            if(match[i]==NIL && dfs(i))
                matching++;
    return matching;
}


int main ()
{
    freopen("in.txt","r",stdin);
	int testCase;
	scanf ("%d", &testCase);

	for (int kk=1; testCase-- ;++kk){
		int n, m;
		scanf ("%d %d", &n, &m);

        for ( int i = 0; i <= n ; i++ ){
            outarrow [i].clear ();
            inarrow [i].clear ();
            vis[i]=false;
        }

        stk.clear ();

		for ( int i = 0; i < m; i++ ){
			int a, b;
			scanf ("%d %d", &a, &b);
			outarrow [a].push_back (b);
			inarrow [b].push_back (a);
		}

		for ( int i = 1; i <= n; i++ )
			if ( !vis [i] )
                dfs1 (i);

		int c = 0;

		for ( int i = stk.size () - 1; i >= 0; i-- )
			if ( vis [stk [i]] )
                dfs2 (stk [i], ++c);

        total=c;
        printf("%d\n",total);
        for (int i=1;i<=total;++i)
            G[i].clear();
        for (int i=1;i<=n;++i)
            for (int j=0;j<outarrow[i].size();++j){
                if ( component[ i ] != component[ outarrow[i][j] ] ){
                    G[ component[ i ] ].push_back(total+component[ outarrow[i][j] ]);
                }
            }
        printf("Case %d: %d\n",kk,total-hopcroft_karp());
	}

	return 0;
}

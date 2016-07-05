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

const int maxBufSize = (1 << 22);

struct Input
{
	int bufSize, bufEnd, bufPos;
	char buffer[maxBufSize];
	void grabBuffer() {
		bufSize = (maxBufSize); bufPos = 0;
		bufEnd = fread(buffer, sizeof (char), bufSize, stdin);
		buffer[bufEnd] = '\0';
	}
	bool bufEof() {return bufPos == bufEnd;}
	int getChar() {return buffer[bufPos++];}
	void skipWS() {
		while ((buffer[bufPos] == '\n' ||
			buffer[bufPos] == ' ' || buffer[bufPos] == '\t'))
			bufPos++;
	}
	int rInt() {
		int n = 0, x; skipWS();
		bool neg=false;
		if (  ( x = getChar() )=='-'  ){
            neg=true;
            x=getChar();
		}

		for (; x <= '9' && x >= '0'; x = getChar())
			n = (n << 3) + (n << 1) + (x - '0');
        if ( neg )return -n;
        else return n;
	}
	inline bool isWhiteSpace(char x) {
		return x == ' ' || x == '\n' || x == '\t';
	}
	char rChar() {skipWS(); return getChar();}
}input;

int main(){

    freopen("in.txt","r",stdin);

    input.grabBuffer();
    while (true ){

        n=input.rInt();
        m=input.rInt();

        if ( !n && !m )break;

        for (int i=1;i<=n;++i){
            hum[i][0]=input.rInt();
            hum[i][1]=input.rInt();
        }

        for (int i=1;i<=m;++i){
            all[i][0]=input.rInt();
            all[i][1]=input.rInt();
        }

        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                dis[i][j]=input.rInt();
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

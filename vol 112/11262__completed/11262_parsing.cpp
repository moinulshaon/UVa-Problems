#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int total,mn;
int blue,red;

struct ttt{
    int x,y;
}pointBlue[105],pointRed[105];

int dis( ttt&a,ttt&b ){
    return int(ceil( sqrt( (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) ) )+1e-6);
}



#define MAX 105
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




bool pos( int lim ){

    n=blue;

    for (int i=0;i<=blue;++i)
            G[i].clear();

    for (int i=1;i<=blue;++i)
        for (int j=1;j<=red;++j){
            if ( dis(pointBlue[i],pointRed[j])<=lim ){
                G[i].push_back(blue+j);
            }
        }
    //printf("%d\n",hopcroft_karp());
    return hopcroft_karp()>=mn;
}
const int maxBufSize = (1 << 23);

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

    int kase,x,y;
    kase=input.rInt();
    char str,ccc;

    while(kase--){
        total=input.rInt();
        mn=input.rInt();
        blue=red=0;
        for (int i=0;i<total;++i){
            x=input.rInt();
            y=input.rInt();
            input.skipWS();
            str=input.getChar();


            while( ( ccc=input.getChar() )!='\n' )
                ;


            if ( str=='b' ){
                pointBlue[++blue].x=x;
                pointBlue[blue].y=y;
            }else{
                pointRed[++red].x=x;
                pointRed[red].y=y;
            }
        }

        int low=0,high=3000,ans=-1,mid;
        while( low<=high ){
            mid=(low+high)/2;
            if ( pos(mid) ){
                high=mid-1;
                ans=mid;
                //printf("works\n");
            }else{
                low=mid+1;
            }
        }
        if ( ans== -1 )printf("Impossible\n");
        else printf("%d\n",ans);
    }
    return 0;
}

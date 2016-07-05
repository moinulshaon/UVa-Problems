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

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

const int maxBufSize = (6000000);

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


int n;
#define SIZE 110
int xi[SIZE],yi[SIZE];
int wi[SIZE],ci[SIZE],si[SIZE];

const double EPS= 1e-4;


#define MAX 210
#define NIL 0
#define INF (1<<28)

vector <int> G[MAX];
int m, match[MAX], dist[MAX];
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

double save[SIZE][SIZE];

void calc(int p,int q){

    double tmp= abs( si[p]- xi[q] );
    tmp/= wi[p];
    tmp += double ( yi[p] )/ ci[p];

    save[p][q]=tmp;

}

void build( double mid ){

    for (int i=0;i<MAX;++i){
        G[i].clear();
    }


    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            if ( save[i][j] < mid+ 1e-6 ){
                G[i].PB(n+j);
            }
        }
    }

}

int main(){

    FRO

    input.grabBuffer();

    while ( true ){
        n=input.rInt();
        if ( n==0 )break;

        for (int i=0;i<n+2;++i){
            xi[i]=input.rInt();
            yi[i]=input.rInt();
        }

        for (int i=1;i<=n;++i){
            ci[i]=input.rInt();
            wi[i]=input.rInt();
            si[i]=input.rInt();
        }

        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j){
                calc(i,j);
                printf("%6.2lf",save[i][j]);
            }printf("\n");
        }


        double low=0,high=1000000,ans= -1 ;
        while ( low<high+EPS ){
            double mid=(low+high)/2;
            build(mid);

            if ( hopcroft_karp() == n ){
                ans=mid;
                printf("pos %lf\n",ans);
                high=mid-EPS;
            }else{
                low=mid+EPS;
            }

        }

        printf("%.2lf\n",ans);
    }


    return 0;
}

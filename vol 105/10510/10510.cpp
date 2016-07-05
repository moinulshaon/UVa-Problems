#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define SIZE 10010

vector<int> outarrow[SIZE];
int level[SIZE];
int backEdge[SIZE];
int prv[SIZE];
char vis[SIZE];

const int WHITE= -1;
const int GRAY= 1;
const int BLACK= 2;

bool cactus;

void dfs( int x ){

    if ( !cactus )return ;

    vis[x]=GRAY;
    int y;
    for (int i=0;i<outarrow[x].size();++i){
        y=outarrow[x][i];
        if ( vis[y]==BLACK ){
            if (  level[y]>=level[x]){
                cactus=false;
                return ;
            }else{
                if ( prv[y]!=x ){
                    backEdge[y]++;
                    prv[y]=x;
                }
            }
        }
        if ( level[ y ] == -1 ){
            level[ y ]=level[x]+1;
            dfs( y );
        }
    }
    vis[x]=BLACK;
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
    int a,b,n,m,tmp,kase;
    kase=input.rInt();
    while ( kase-- ){
        n=input.rInt();
        m=input.rInt();
        for (int i=0;i<n;++i){
            outarrow[i].clear();
        }
        while (m--){
            a=input.rInt();
            b=input.rInt();
            outarrow[a].push_back(b);
        }
        memset(vis,WHITE,sizeof(vis));
        memset(backEdge,0,sizeof(backEdge));
        memset(prv,-1,sizeof(prv));
        memset(level,-1,sizeof(level));
        cactus=true;
        level[0]=0;
        dfs(0);
        for (int i=0;i<n && cactus;++i){
            if  ( level[i]== -1 || backEdge[i]>1 ){
                cactus=false;
            }
        }
        if ( cactus ){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;

}

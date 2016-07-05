#include <cstdio>
#include <vector>
#include <cstring>
#include <set>
#include <queue>

using namespace std;

#define SIZE 1100

vector<int> outarrow[SIZE];
int level[SIZE];
int low[SIZE];

int stk[SIZE];
int top;
bool bcc[SIZE][SIZE];
int bccCnt;

bool adjMat[SIZE][SIZE];

void dfs( int x ){
    //printf("%d %d\n",x,level[x]);
    low[x]=level[x];
    stk[top++] = x;
    int y;
    for (int i=0;i<outarrow[x].size();++i){
        y=outarrow[x][i];
        if ( level[ y ]== -1 ){

            level[ y ]=level[x]+1;


            dfs( y );


            low[x]=min( low[x],low[y] );

            if (low[y] >= level[x]){
                int tmp;
                do{
                    tmp = stk[--top];
                    bcc[bccCnt][tmp] = true;
                } while (tmp != y);
                bcc[bccCnt++][x] = true;
            }


        }else if ( level[y]< level[x]-1 ){
            low[x]=min( low[x],level[y] );
        }

    }


}

int color[SIZE];
int v;
bool isBipartite[SIZE];
int checkBipartite(int n){
    int x;
    for (int i=1;i<=v;++i){
        if( bcc[n][i] ){
            x=i;
            break;
        }
    }


    queue<int> q;
    memset( color,-1,sizeof(color));
    q.push(x);
    color[x]=0;
    bool bipartitePossible=true;


    while ( !q.empty() ){
        int tmp=q.front();
        q.pop();

        for (int i=0;i<outarrow[tmp].size();++i){
            if( ! bcc[n][ outarrow[tmp][i] ] )continue;

            if ( color[ outarrow[tmp][i] ]== -1 ){
                color[ outarrow[tmp][i] ]=  !color[tmp];
                q.push( outarrow[tmp][i] );
            }
            else if ( color[ outarrow[tmp][i] ] ==  color[tmp]){
                bipartitePossible=false;
            }
        }
    }
    isBipartite[n]= bipartitePossible;
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

    int a,b,e;
    input.grabBuffer();
    while (true){

        v=input.rInt();
        e=input.rInt();

        if ( !v && !e )return 0;

        for (int i=0;i<=v;++i){
            outarrow[i].clear();
        }
        memset(adjMat,true,sizeof(adjMat));

        while(e-- ){
            a=input.rInt();
            b=input.rInt();
            adjMat[a][b]=adjMat[b][a]=false;
        }

        for (int i=1;i<=v;++i){
            for (int j= i+1 ;j<=v;++j){
                if (i!=j && adjMat[i][j] ){
                    outarrow[i].push_back(j);
                    outarrow[j].push_back(i);
                }
            }
        }



        memset( level,-1,sizeof(level));
        memset( bcc,false,sizeof(bcc));
        bccCnt=0;
        top=0;

        for (int i=1;i<=v;++i){
            //printf("%d %d %d\n",i,level[i],low[i]);
            if ( level[i]== -1 ){
                level[i]=0;
                dfs(i);
            }
        }

        int cnt=0;

        memset( isBipartite,false,sizeof(isBipartite));

        for (int i=0;i<bccCnt;++i){
            checkBipartite(i);
        }
        //printf("%d\n",bccCnt);
        for (int i=0;i<bccCnt;++i){
            if ( !isBipartite[i] ){
                for (int j=1;j<=v;++j){
                    if ( bcc[i][j]  ){
                        //printf("%d %d\n",i,j);
                        ++cnt;
                    }
                }
            }
        }
        printf("%d\n",v-cnt);


    }
    return 0;

}



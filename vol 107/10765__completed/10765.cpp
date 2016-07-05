#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define SIZE 10100

vector<int> outarrow[SIZE];
int isArtic[SIZE];
int level[SIZE];
int low[SIZE];
int childrenCnt[SIZE];


void dfs( int x ){
    //printf("%d %d\n",x,level[x]);
    low[x]=level[x];
    int y;
    for (int i=0;i<outarrow[x].size();++i){
        y=outarrow[x][i];
        if ( level[ y ]== -1 ){

            level[ y ]=level[x]+1;
            childrenCnt[ x ]++;

            dfs( y );

            low[x]=min( low[x],low[y] );

            if ( level[x]!=0 && low[y]>=level[x] ){
                isArtic[x]++;
            }
        }else if ( level[y]< level[x]-1 ){
            low[x]=min( low[x],level[y] );
        }

    }
    if ( level[x]==0 && childrenCnt[x]>1){
        isArtic[x]++;
    }

}

struct rr{
    int ind,cnt;
}result[SIZE];

bool cmp(const rr&a,const rr&b){
    if ( a.cnt!=b.cnt )
        return a.cnt>b.cnt;
    else
        return a.ind<b.ind;
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

    int kase,a,b,v,m;
    input.grabBuffer();
    while(true){

        v=input.rInt();
        m=input.rInt();
        if ( !v && !m )return 0;


        for (int i=0;i<v;++i){
            outarrow[i].clear();
        }

        while(true){
            a=input.rInt();
            b=input.rInt();

            if ( a== -1 && b== -1)break;
            outarrow[a].push_back(b);
            outarrow[b].push_back(a);
        }


        memset( level,-1,sizeof(level));
        memset( childrenCnt,0,sizeof(childrenCnt));
        memset( isArtic,0,sizeof(isArtic) );

        for (int i=0;i<v;++i){
            if ( level[i]== -1 ){
                level[i]=0;
                dfs(i);
            }
        }
        for (int i=0;i<v;++i){
            result[i].ind=i;
            result[i].cnt=isArtic[i]+1;
        }
        sort(result,result+v,cmp);
        for (int i=0;i<m;++i){
            printf("%d %d\n",result[i].ind,result[i].cnt);
        }
        printf("\n");
    }
    return 0;

}



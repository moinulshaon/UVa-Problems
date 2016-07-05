#include <cstdio>
#include <vector>
#include <cstring>
#include <set>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define SIZE 100010

vector<int> outarrow[SIZE];
bool isArtic[SIZE];
int level[SIZE];
int low[SIZE];
int childrenCnt[SIZE];

set<int> sset;

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
                isArtic[x]=true;
            }
        }else if ( level[y]< level[x]-1 ){
            low[x]=min( low[x],level[y] );
        }

    }
    if ( level[x]==0 && childrenCnt[x]>1){
        isArtic[x]=true;
    }

}
typedef unsigned long long LL;

int v;
LL cnt;
bool vis[SIZE];

void DFS2(int u){
    vis[u] = true;
    cnt++;

    for(int i=0;i<outarrow[u].size();i++){
        long v = outarrow[u][i];
        if( isArtic[v] ){
            sset.insert( v );
            continue;
        }
        if( vis[v] ) continue;
        DFS2( v );
    }
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
    int a,b,e;

    for (int kk=1;true;++kk){
        e=input.rInt();
        if ( !e )return 0;
        int v=1;
        while(e-- ){
            a=input.rInt();
            b=input.rInt();
            v=max(v,a);
            v=max(v,b);
            outarrow[a].push_back(b);
            outarrow[b].push_back(a);
        }




        memset( level,-1,sizeof(level));
        memset( childrenCnt,0,sizeof(childrenCnt));
        memset( isArtic,false,sizeof(isArtic) );
        memset(vis,false,sizeof(vis));


        for (int i=1;i<=v;++i){
            //printf("%d %d %d\n",i,level[i],low[i]);
            if ( level[i]== -1 ){
                level[i]=0;
                dfs(i);
            }
        }

        int tunnel=0;
        LL way=1;
        for (int i=1;i<=v;++i){
            if ( isArtic[i] || vis[i] )continue;
            cnt=0;

            sset.clear();
            DFS2(i);

            if( !sset.size() ){
                if( cnt==1 ){
                    tunnel++;
                }
                else{
                    tunnel += 2;
                    way *= (cnt*(cnt-1))/2;
                }
            }else if( sset.size()==1 ){
                tunnel++;
                way *= cnt;
            }

        }

        printf("Case %d: %d %llu\n",kk,tunnel,way);
        for (int i=0;i<=v;++i){
            outarrow[i].clear();
        }
    }
    return 0;

}

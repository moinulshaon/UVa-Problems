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

#define SIZE 100100

vector<int> out[SIZE];
vector<int> outcost[SIZE];

int parent[SIZE][17];
LL cost[SIZE][17];
int depth[SIZE];

void dfs(int x,int p,int w){

    parent[x][0]=p;
    cost[x][0]=w;
    depth[x]=depth[p]+1;


    for (int i=1;i<17;++i){
        parent[x][i]=parent[ parent[x][i-1] ][i-1];
        cost[x][i]=cost[x][i-1]+cost[ parent[x][i-1] ][i-1];
    }


    for (int i=0;i<out[x].size();++i){
        int y=out[x][i];
        if ( y!=p ){
            dfs(y,x,outcost[x][i]);
        }
    }


}

LL modifiedlca(int x,int y){
    if ( depth[x]>depth[y] ){
        swap(x,y);
    }
    LL rr=0;
    for (int i=0;i<17;++i){
        if( ( ( depth[y]-depth[x] )>>i )&1){
            rr+= cost[y][i];
            y=parent[y][i];
        }
    }
    if ( x==y ){
        return rr;
    }
    for(int i=16;i>=0;--i)
        if(parent[x][i]!=parent[y][i] ){
            rr+=cost[x][i];
            rr+=cost[y][i];
            x=parent[x][i],y=parent[y][i];

        }

    return rr+cost[x][0]+cost[y][0];
}

const int maxBufSize = (15000000);

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
    FRO
    input.grabBuffer();
    int node;
    while(true){

        node=input.rInt();
        if ( !node )break;
        int a,w;

        for (int i=0;i<=node;++i){
            out[i].clear();
            outcost[i].clear();
        }

        for (int i=2;i<=node;++i){
            a=input.rInt();
            w=input.rInt();
            a++;
            //printf("%d %d %d\n",a-1,i-1,w);
            out[a].PB( i );
            outcost[a].PB( w );
        }


        dfs(1,0,0);

        int query;
        query=input.rInt();
        //printf("q %d\n",query);
        for (int i=0;i<query;++i){
            a=input.rInt();
            w=input.rInt();
            if ( i )printf(" ");
            printf("%lld",modifiedlca(a+1,w+1));
        }
        printf("\n");
    }

    return 0;
}


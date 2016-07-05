#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>


#define SIZE 5010

using namespace std;

vector<int>out[SIZE];
bool vis[SIZE];
int parent[SIZE][14];
int depth[SIZE];

void dfs(int x,int p){
    vis[x]=true;

    parent[x][0]=p;
    depth[x]=depth[p]+1;


    for (int i=1;i<14;++i)
        parent[x][i]=parent[ parent[x][i-1] ][i-1];

    for (int i=0;i<out[x].size();++i){
        int y=out[x][i];
        if ( !vis[y] ){
            dfs(y,x);
        }
    }

}

int lca(int x,int y){
    if ( depth[x]>depth[y] ){
        swap(x,y);
    }
    for (int i=0;i<14;++i){
        if( ( ( depth[y]-depth[x] )>>i )&1){
            y=parent[y][i];
        }
    }
    if ( x==y ){
        return x;
    }
    for(int i=13;i>=0;--i)
        if(parent[x][i]!=parent[y][i] )
            x=parent[x][i],y=parent[y][i];
    return parent[x][0];
}

int dis(int x,int y){
    int dis=0;
    for (int i=0;i<14;++i){
        if( ( ( depth[y]-depth[x] )>>i )&1){
            y=parent[y][i];
            dis |=(1<<i);
        }
    }
    return dis;
}

int up(int x,int val){
    //printf("me %d\n",val);
    if ( val==0 ){
        return x;
    }else{
        for(int i=13;i>=0;--i){
            if ( (val>>i)&1 ){
                x=parent[x][i];
            }
        }
        return x;
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
    int n;
    input.grabBuffer();
    while(true){
        n=input.rInt();

        if ( !n )return 0;

        for (int i=1;i<=n;++i){
            out[i].clear();
        }
        int a,b;
        for (int i=1;i<n;++i){
            a=input.rInt();
            b=input.rInt();

            out[a].push_back(b);
            out[b].push_back(a);
        }

        memset(vis,false,sizeof(vis));
        depth[1]=0;
        dfs(1,0);

        int query=input.rInt();

        while(query--){
            a=input.rInt();
            b=input.rInt();

            int d=lca(a,b);

            int x=dis( d,a );
            int y=dis( d,b );

            //printf("lca %d val %d %d\n",d,x,y);
            if ( (x+y)%2 == 0 ){
                if ( x>=y ){
                    printf("The fleas meet at %d.\n", up(a,(x+y)/2) );
                }else{
                    printf("The fleas meet at %d.\n", up(b,(x+y)/2) );
                }
            }else{
                int u,v;
                if ( x>=y ){
                    u=up(a,(x+y)/2);
                    v=up(a,(x+y)/2+1);
                }else{
                    u=up(b,(x+y)/2);
                    v=up(b,(x+y)/2+1);
                }
                printf("The fleas jump forever between %d and %d.\n",min(u,v),max(u,v));
            }
        }
    }

}

#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define SIZE 20100

vector<int> outarrow[SIZE];
bool isArtic[SIZE];
int level[SIZE];
int low[SIZE];
int childrenCnt[SIZE];
vector<int> com[SIZE];
int after[SIZE];

int parent [SIZE];
int sz[SIZE];

int parentOf (int n){
    if ( n == parent [n] ) return n;
    return parent [n] = parentOf (parent [n]);
}

int dfs( int x ){
    //printf("%d %d\n",x,level[x]);
    low[x]=level[x];
    after[x]=1;
    int y;
    for (int i=0;i<outarrow[x].size();++i){
        y=outarrow[x][i];
        if ( level[ y ]== -1 ){

            level[ y ]=level[x]+1;
            childrenCnt[ x ]++;

            dfs( y );
            after[x]+=after[y];


            low[x]=min( low[x],low[y] );

            if ( level[x]!=0 && low[y]>=level[x] ){
                isArtic[x]=true;
                com[x].push_back(after[y]);
            }
        }else if ( level[y]< level[x]-1 ){
            low[x]=min( low[x],level[y] );
        }
    }
    if ( level[x]==0 && childrenCnt[x]>1){
        isArtic[x]=true;
        for (int i=0;i<outarrow[x].size();++i){
            y=outarrow[x][i];
            if ( level[y] == 1 )
                com[x].push_back(after[y]);
        }
    }
}
typedef long long LL;

const int maxBufSize = 5000000;

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
    //freopen("output.txt","w",stdout);
    int kase,a,b,v,e;
    input.grabBuffer();
    kase=input.rInt();

    for (int kk=1;kase--;++kk){

        v=input.rInt();
        e=input.rInt();
        for (int i=1;i<=v;++i){
            outarrow[i].clear();
            com[i].clear();
        }
        for (int i=0;i<=v; ++i ){
            parent [i] = i;
            sz[i]=1;
        }

        while(e-- ){
            a=input.rInt();
            b=input.rInt();
            outarrow[a].push_back(b);
            outarrow[b].push_back(a);

            int p = parentOf (a);
            int q = parentOf (b);

            if ( p != q ) {
                if (sz[p]>sz[q])swap(p,q);
                sz[q]+=sz[p];
                parent [p] = q;
            }

        }


        memset( level,-1,sizeof(level));
        memset( childrenCnt,0,sizeof(childrenCnt));
        memset( isArtic,false,sizeof(isArtic) );
        memset( after,0,sizeof(after) );

        for (int i=1;i<=v;++i){
            if ( level[i] == -1 ){
                level[i]=0;
                dfs(i);
            }
        }
        LL ans=0;
        for (int i=1;i<=v;++i){
            if ( isArtic[i]  ){

                //printf("artic %d\n",i,ans);
                int sum=0;
                int tmp=sz[ parentOf(i) ];
                for (int j=0;j<com[i].size();++j){
                    ans+= com[i][j] * (  tmp- com[i][j]-1  );
                    sum+= com[i][j];
                    //printf("%d %d\n",com[i][j],( sz[ parentOf(i) ] - com[i][j] -1  ) );
                }
                //printf("%d %d\n",( sz[ parentOf(i) ] - sum -1 ),sum );
                ans+= sum* ( tmp - sum -1 ) ;
                //printf("%d\n",ans);
            }
        }
        printf("Case %d: %lld\n",kk,ans);
    }
    return 0;

}



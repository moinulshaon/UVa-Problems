#include <cstdio>
#include <cstring>
#include <vector>
#define N 51000
using namespace std;

vector <int> outarrow [N + 10];
vector <int> inarrow [N + 10];
bool vis [N + 10];
vector <int> stk;
int component [N + 10];



void dfs1 (int x)
{
	vis [x] = true;

	for ( int u = 0; u < outarrow [x].size (); u++ )
		if ( !vis [ outarrow [x] [u]] )
            dfs1 (outarrow [x] [u]);

	stk.push_back (x);
}

int minInComponent[N+10];

void dfs2 (int x, int c)
{
	vis [x] = false;
	component [x] = c;

    if ( minInComponent[c]>x ){
        minInComponent[c]=x;
    }

	for ( int u = 0; u < inarrow [x].size (); u++ )
		if ( vis [inarrow [x] [u]] )
            dfs2 (inarrow [x] [u], c);
}



vector<int> superOutarrow[N];
int superNodeCnt[N];
int dp[N];
int n, m;
void createDAG(){

    for (int i=1;i<=n;++i){
        superOutarrow[i].clear();
        superNodeCnt[i]=0;
        dp[i]= -1;
    }

    for (int i=1;i<=n;++i){
        for (int j=0;j<outarrow[i].size();++j){
            if (  component[i]!=component[ outarrow[i][j] ] ){
                superOutarrow[ component[i]].push_back( component[ outarrow[i][j] ]);
            }
        }
        superNodeCnt[ component[i] ]++;
    }

}
int againDFS(int x){

    if ( dp[x]!= -1 )return dp[x];
    int tmp=0;
    for (int i=0;i<superOutarrow[x].size();++i){
        tmp=max(tmp,againDFS(superOutarrow[x][i]));
    }
    return dp[x]=superNodeCnt[x]+tmp;

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

int main ()
{


    input.grabBuffer();
	int testCase,kk=0;
	testCase=input.rInt();

	while ( testCase-- ){

		n=input.rInt();
		m=n;

        for ( int i = 0; i <= n ; i++ )
        {
            outarrow [i].clear ();
            inarrow [i].clear ();
            vis[i]=false;
            minInComponent[i]=(1<<30);
        }

        stk.clear ();

		for ( int i = 0; i < m; i++ )
		{
			int a, b;
			a=input.rInt();
			b=input.rInt();
			outarrow [a].push_back (b);
			inarrow [b].push_back (a);
		}

		for ( int i = 1; i <= n; i++ )
			if ( !vis [i] )
                dfs1 (i);

		int c = 0;

		for ( int i = stk.size () - 1; i >= 0; i-- )
			if ( vis [stk [i]] )
                dfs2 (stk [i], ++c);

        createDAG();

        int ans=0,person=0;;
        for (int i=1;i<=c;++i){
            if ( ans<againDFS(i) ){
                ans=againDFS(i);
                person=minInComponent[i];
            }
            else if ( ans== againDFS(i) ){
                person=min(person,minInComponent[i]);
            }
        }
        printf("Case %d: %d\n",++kk,person);

    }

	return 0;
}

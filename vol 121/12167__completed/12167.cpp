#include <vector>
#include <cstdio>
#define N  20100
using namespace std;

vector <int> outarrow [N + 10];
vector <int> inarrow [N + 10];
bool vis [N + 10];
vector <int> stk;
int component [N + 10];
bool in [N + 10];
bool out[N+10];



void dfs1 (int x)
{
	vis [x] = true;

	for ( int u = 0; u < outarrow [x].size (); u++ )
		if ( !vis [ outarrow [x] [u]] )
            dfs1 (outarrow [x] [u]);

	stk.push_back (x);
}

void dfs2 (int x, int c)
{
	vis [x] = false;
	component [x] = c;

	for ( int u = 0; u < inarrow [x].size (); u++ )
		if ( vis [inarrow [x] [u]] )
            dfs2 (inarrow [x] [u], c);
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
    freopen("in.txt","r",stdin);
    input.grabBuffer();
	int testCase;
	testCase=input.rInt();

	while (testCase-- )
	{
		int n, m;
		n=input.rInt();
		m=input.rInt();

        for ( int i = 0; i <= n ; i++ )
        {
            outarrow [i].clear ();
            inarrow [i].clear ();
            vis[i]=false;
            in[i]=false;
            out[i]=false;
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

		for ( int i = 1; i <= n; i++ )
			for ( int j = 0; j < outarrow [i].size (); j++ )
				if ( component [i] != component [outarrow [i] [j]] ){
                    out[ component[i] ]=true;
                    in [component [outarrow [i] [j]]]=true;
				}






        int source=0,sink=0;
        bool on=false;
        for (int i=1;i<=c;++i){
            if  ( out[i] && !in[i] ){
                source++;
            }
            if ( in[i] && !out[i]){
                sink++;
            }
            if ( in[i] || out[i] ){
                on=true;
            }
        }


        int cnt=0,rr=max(source,sink);
        //cout<<rr<<endl;
        for (int i=1;i<=c;++i){
            if (c>1 && !in[i] && !out[i] ){
                if ( rr ==0 && on ){
                    rr=1;
                }
                cnt++;
            }
        }
        //cout<<rr<<' '<<cnt<<endl;

		printf("%d\n",rr+cnt);
	}

	return 0;
}

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
#include <climits>

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
};
struct Output
{
	int bufSize, bufEnd, bufPos;
	char buffer[maxBufSize];
	Output() {bufPos = bufEnd = 0; bufSize = maxBufSize;}
	void print(int x) {
		if (x < 0) {
			print('-'); print(-x); return;
		}
		char temp[1 << 4]; int idx = 0;
		do {
			temp[idx++] = '0' + (x % 10);
			x /= 10;
		} while (x != 0);
		temp[idx] = '\0';
		reverse(temp, temp + idx);
		print(temp);
	}
	inline void print(char ch) {buffer[bufEnd++] = ch;}
	inline void print(const char* s) {while (*s) buffer[bufEnd++] = *s++;}
	inline void print(const string& s) {print(s.c_str());}
	inline void flushBuffer() {buffer[bufEnd] = '\0'; printf("%s", buffer); bufEnd = 0;}
	template <class A, class B>
	void print(const A& a, const B& b) {print(a); print(b);}
	template <class A, class B, class C>
	void print(const A& a, const B& b, const C& c) {print(a); print(b); print(c);}
};

Output output;
Input input;

#define SIZE 2505

vector<int> out[SIZE];
int cost[SIZE][SIZE];

vector<int> w;

vector<pint> qq;

int cnt;
void bfs( int s ){

    bool vis[SIZE]={false};

    queue<int> q;

    q.push( s );
    vis[ s ]=true;

    while ( !q.empty() ){
        int x=q.front();q.pop();


        for (int i=0;i<out[x].size();++i){
            if ( !vis[ out[x][i] ] ){
                vis[ out[x][i] ] = true;
                q.push( out[x][i] );
                cost[ x ][ out[x][i] ] = cost[ out[x][i] ][ x ] = w[cnt++];
            }
        }
    }
}

int main(){

    FRO

    input.grabBuffer();

    int kase;
    kase=input.rInt();

    for (int kk=1;kase--;++kk){

        output.print("Case ");
        output.print(kk);
        output.print(":\n");
        //printf("Case %d:\n",kk);

        int n,m,ss;
        n=input.rInt();
        m=input.rInt();
        ss=input.rInt();

        for (int i=0;i<=n;++i){
            out[i].clear();
        }
        w.clear();
        qq.clear();

        int u,v,tmp;
        for (int i=0;i<m;++i){
            u=input.rInt();
            v=input.rInt();
            tmp=input.rInt();

            out[u].PB( v );
            out[v].PB( u );

            qq.PB( make_pair( u,v ) );

            cost[ u ][ v ] =cost[ v ][ u ] = 0;

            w.PB( tmp );
        }

        sort( w.begin(),w.end() );


        cnt = 0;
        bfs(ss);

        for (int i=0;i<m;++i){

            output.print(qq[i].first);;
            output.print(' ');
            output.print(qq[i].second);
            output.print(' ');
            if ( cost[ qq[i].first ][ qq[i].second ] == 0 ){
                output.print(w[cnt++]);
            }else{
                output.print(cost[ qq[i].first ][ qq[i].second ]);
            }
            output.print('\n');
        }
    }

    output.flushBuffer();


    return 0;
}

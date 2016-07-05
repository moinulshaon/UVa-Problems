#include<iostream>
#include<vector>
#include <map>
#include <string>
#include<algorithm>
#include<queue>
#include<cstdio>
#include <cmath>
#include <cstring>
#include<ctime>
#define sz 110

using namespace std;

struct place{
    int x,y,r;
}island[sz];
int start=0,destination=1;
int capacity;
int total;
bool vis[sz];
int dp[sz][sz];

const int maxBufSize = (1 << 20);

struct Input
{
	int bufSize, bufEnd, bufPos;
	char buffer[maxBufSize];
	void grabBuffer() {
		bufSize = (maxBufSize); bufPos = 0;
		bufEnd = fread(buffer, sizeof (char), bufSize, stdin);
		buffer[bufEnd] = '\0';
	}
	bool bufEof() {return bufPos >= bufEnd;}
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


bool checkDistance( int a ,int b ){
    if (dp[a][b]!=-1 )return dp[a][b];

    return dp[a][b]=dp[b][a]=(island[a].x-island[b].x)*(island[a].x-island[b].x)+(island[a].y-island[b].y)*(island[a].y-island[b].y)
    <= ( capacity+island[a].r+island[b].r )*( capacity+island[a].r+island[b].r ) ;

}

void DFS( int n ){

    if (vis[1])return ;
    vis[n]=true;
    for( int i=0 ; i<total ;++i ){
        if (!vis[ i ] && i!=n && checkDistance( n , i ) ){
            DFS ( i );
        }
    }
}


int main(){

    freopen("in.txt","r",stdin);

    input.grabBuffer();

    int m,k;
    while (!input.bufEof() ){

        m=input.rInt();
        k=input.rInt();


        memset(vis,false,sizeof( vis) );
        memset(dp,-1,sizeof( dp ) );

        capacity=m*k;

        island[0].x=input.rInt();
        island[0].y=input.rInt();
        island[0].r=input.rInt();
        island[1].x=input.rInt();
        island[1].y=input.rInt();
        island[1].r=input.rInt();

        total=input.rInt();

        for (int i=0;i<total;++i){
            island[i+2].x=input.rInt();
            island[i+2].y=input.rInt();
            island[i+2].r=input.rInt();
        }
        total+=2;

        //printf("%d\n",checkDistance( 0 , 1 ) );

        DFS( 0 );
        if (vis[1])
            output.print("Larry and Ryan will escape!\n");
        else
            output.print("Larry and Ryan will be eaten to death.\n");

    }
    output.flushBuffer();
    return 0;

}

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define INF 10000000

int set(int N,int pos){
    return N=N | (1<<pos);
}
int reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool check(int N,int pos){
    return (bool)(N & (1<<pos));
}


struct gg{

    int a,b,c;
    int val;

}group[100];
int groupNo;

int dp[1<<9+2];

int func( int state,int depth ){
    if ( depth==3 ){
        return 3*INF;
    }
    if ( dp[state]!= -1 )return dp[state];

    int ans= -1;
    for (int i=0;i<groupNo;++i){
        if (  check( state,group[i].a )==0 && check( state,group[i].b )==0  && check( state,group[i].c )==0 ){
            ans=max( ans,-INF+group[i].val+func( set( set(set(state,group[i].a),group[i].b),group[i].c),depth+1 ) );
        }
    }
    return dp[state]=ans;

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
    input.grabBuffer();
    for (int kk=1;true;++kk){
        groupNo=input.rInt();
        if  ( !groupNo )break;

        for (int i=0;i<groupNo;++i){
            group[i].a=input.rInt();
            group[i].b=input.rInt();
            group[i].c=input.rInt();
            group[i].val=input.rInt();
            group[i].a--;
            group[i].b--;
            group[i].c--;
        }
        memset(dp,-1,sizeof(dp));

        if ( func(0,0) >= 0 )
            printf("Case %d: %d\n",kk,func(0,0));
        else
            printf("Case %d: -1\n",kk);
    }
    return 0;

}

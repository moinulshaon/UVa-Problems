#include <cstdio>
#include <cstring>


typedef unsigned long long LL;

LL dp[65][65];

LL count;

LL trib(int n, int back){
    LL tmp=count++;
    if(n<=0) return 1;
    if(n==1) return 1;

    if ( dp[n][back]!=-1 ){
        return count+=dp[n][back]-1;
    }
    for(int i=1;i<=back;i++)
         trib(n-i,back);
    return dp[n][back]=count-tmp;
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

    input.grabBuffer();
    int a,b,cc=1;
    memset(dp,-1,sizeof(dp));
    while ( true ){
        a=input.rInt();
        b=input.rInt();
        if ( a>60 )return 0;
        count=0;
        printf("Case %d: %llu\n",cc++,trib(a,b));
    }
    return 0;
}

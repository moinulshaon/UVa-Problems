#include <cstdio>
#include <cstring>

using namespace std;


int f(int m,int n){
	if (m==1)
		return n-1;
	else
		return n+f(m-1,n);
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
	bool bufEof() {skipWS();return bufPos == bufEnd;}
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
int main()
{
    freopen("in.txt","r",stdin);
    input.grabBuffer();

	int m,n;


	while (!input.bufEof()){
	    m=input.rInt();
	    n=input.rInt();
		if (m>n)
			printf("%d\n",f(m,n));
		else
			printf("%d\n",f(n,m));
	}
	return 0;
}

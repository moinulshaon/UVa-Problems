#include <cstdio>
#include <cmath>

using namespace std;

long long sumOfAllDigitFromZeroToX(long long x){
    if(x<=0) return 0;
    long long m = x % 10;
    return (x / 10) * 45 + (m * m + m) / 2 + sumOfAllDigitFromZeroToX(x / 10);
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
};

Input input;

int main(){

    long long a,b;

    input.grabBuffer();

    while (true){

        a=input.rInt();
        b=input.rInt();

        if (a<0 && b<0)return 0;

        printf("%lld\n",sumOfAllDigitFromZeroToX(b)-sumOfAllDigitFromZeroToX(a-1));

    }

}

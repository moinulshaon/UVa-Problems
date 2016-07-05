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

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

LL func( int k,int r ){
    if ( r<=0 ){
        return 0;
    }
    if ( k==0 ){
        return 1;
    }

    if ( r<= (1<<(k-1) ) ){
        return 2*func( k-1,r );
    }else{
        return 2*LL( pow(3,k-1)+1e-6 )+func( k-1, r-(1<<(k-1) ) );
    }
}

const int maxBufSize = 1000000;

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

    int kase;

    input.grabBuffer();

    kase=input.rInt();

    for (int kk=1;kase--;++kk){

        int k,a,b;
        k=input.rInt();
        a=input.rInt();
        b=input.rInt();
        //scanf("%d %d",&k,&a);
        //printf("%d\n",func(k,a));

        printf("Case %d: %lld\n",kk,func(k,b)-func(k,a-1));
    }


    return 0;
}

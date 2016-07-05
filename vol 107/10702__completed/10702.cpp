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

#define maxi(a,b) ( (a)>(b) )?(a):(b)
#define sz 110
#define INF 2147483647

const int maxBufSize = (1 << 20);

using namespace std;

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

int main()
{
    freopen("in.txt","r",stdin);

    input.grabBuffer();

    int c,s,nDest,intermidate;
    int G[sz][sz];
    int end[sz];
    int dp[sz][1100];

    while (true)
    {

        c=input.rInt();
        s=input.rInt();
        nDest=input.rInt();
        intermidate=input.rInt();

        if (!c  && !s && !nDest && !intermidate){
            return 0;
        }

        for (int i = 1; i <=c; i++)
            for (int  j = 1; j <= c; j++)
                G[i][j]=input.rInt();
        for (int  i = 0; i < nDest; i++)
            end[i]=input.rInt();

        for (int i = 0; i <= c; ++i)
            for (int j=0;j<=intermidate;++j)
                dp[i][j]=-INF;
        for (int i = 0; i < nDest; i++)
            dp[end[i]][intermidate] = 0;
        for (int i = intermidate - 1; i >= 0; i--)
            for (int j = 1; j <=c; j++)
                for (int k = 1; k <= c; k++)
                    dp[j][i] = maxi(dp[j][i], G[j][k] + dp[k][i + 1]);
        printf("%d\n",dp[s][0]);

	}
}

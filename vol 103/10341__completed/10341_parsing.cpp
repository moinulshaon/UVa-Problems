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

#define INF 100000001

const int maxBufSize = (1 << 16);

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

	int getChar() {return buffer[bufPos++];}
	void skipWS() {
		while ((buffer[bufPos] == '\n' ||
			buffer[bufPos] == ' ' || buffer[bufPos] == '\t'))
			bufPos++;
	}
	bool bufEof() {return bufPos >= bufEnd;}
	int rInt() {
		int n = 0, x; skipWS();
		bool neg=false;
		if ( x=getChar() ){
            if ( x== '-' ){
                neg=true;
                x=getChar();
            }
		}
		for (; x <= '9' && x >= '0'; x = getChar())
			n = (n << 3) + (n << 1) + (x - '0');
        if ( neg )
            return -n;
        else
            return n;
	}
	inline bool isWhiteSpace(char x) {
		return x == ' ' || x == '\n' || x == '\t';
	}
	char rChar() {skipWS(); return getChar();}
};

Input input;

int p,q,r,s,t,u;

double prv;

double F()
{
	return p*exp(-prv)+q*sin(prv)+r*cos(prv)+s*tan(prv)+t*prv*prv+u;
}

double F1()
{
	double temp=cos(prv);
	return -p*exp(-prv)+q*cos(prv)-r*sin(prv)+s/(temp*temp)+2*t*prv;
}


int main(){

    freopen("in.txt","r",stdin);

    input.grabBuffer();

    double now,temp,x,y;

	while ( true )
	{
	    if  ( input.bufEof() )break;
	    p=input.rInt();
	    q=input.rInt();
	    r=input.rInt();
	    s=input.rInt();
	    t=input.rInt();
	    u=input.rInt();


	    //printf("%d %d %d %d %d %d\n",p,q,r,s,t,u);

		prv=0;
		x=F();
		prv=1;
		y=F();
		if (x > 0 && y > 0)printf("No solution\n");
		else if (x < 0 && y < 0) printf("No solution\n");
		else if ( x<.00001 && x>-.00001 ) printf("0.0000\n");
		else if ( y<.00001 && y>-.00001) printf("1.0000\n");
		else
		{
			now=temp=.5;
			while (temp>.0001)
			{
				prv=now;
				now=prv-F()/F1();
				temp=fabs(prv-now);

			}
            printf("%.4lf\n",now);
		}

	}
    return 0;

}

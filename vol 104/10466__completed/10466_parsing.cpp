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
	bool bufEof() {return bufPos >= bufEnd;}
	int getChar() {return buffer[bufPos++];}
	void skipWS() {
		while ((buffer[bufPos] == '\n' ||
			buffer[bufPos] == ' ' || buffer[bufPos] == '\t'))
			bufPos++;
	}
	int rInt() {
		int n = 0, x; skipWS();
		for (x = getChar(); x <= '9' && x >= '0'; x = getChar())
			n = (n << 3) + (n << 1) + (x - '0');
		return n;
	}
	inline bool isWhiteSpace(char x) {
		return x == ' ' || x == '\n' || x == '\t';
	}
	char rChar() {skipWS(); return getChar();}
};
Input input;




double powerOfTwo(double x){
    return x*x;
}

int main(){

    freopen("in.txt","r",stdin);

    input.grabBuffer();

    int total,time,t,r;

    double PI=acos(-1),theta,vx,vy,result;

    while (!input.bufEof()  ){
        vx=vy=0;

        total=input.rInt();
        time=input.rInt();

        for (int i=1;i<total;++i){
            r=input.rInt();
            t=input.rInt();

            theta=2*PI*time/t;

            vy+=r*sin(theta);
            vx+=r*cos(theta);

            result=sqrt( powerOfTwo(vx)+powerOfTwo(vy) );

            printf("%.4lf ",result);
        }
        r=input.rInt();
        t=input.rInt();

        theta=2*PI*time/t;

        vy+=r*sin(theta);
        vx+=r*cos(theta);

        result=sqrt( powerOfTwo(vx)+powerOfTwo(vy) );

        printf("%.4lf\n",result);

    }
    return 0;

}

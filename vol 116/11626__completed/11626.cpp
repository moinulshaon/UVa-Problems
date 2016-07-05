#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define INF 100000000

typedef long long LLL;

struct mathv{
    mathv(){x=0;y=0;}
    mathv(int a,int b){x=a;y=b;}
    int x,y;

    mathv operator + (const mathv & p){
        mathv tmp( x+p.x,y+p.y );
        return tmp;
    }
    mathv operator - (const mathv & p){
        mathv tmp( x-p.x,y-p.y );
        return tmp;
    }

};
LLL cross2D(mathv v1, mathv v2){
    return LLL(v1.x) * v2.y - LLL(v1.y) * v2.x;
}

mathv basePoint;
int distance2DPointAndPointSqueredVersion(const mathv& v1,const  mathv& v2){
    return (v2.x - v1.x) * (v2.x - v1.x)+ (v2.y - v1.y) * (v2.y - v1.y);
}
bool cmp(const mathv& a, const mathv& b){
    if ( a.x!=b.x ){
        return a.x<b.x;
    }else{
        return a.y<b.y;
    }
}
int convexHull(mathv points[],mathv convexPoints[],  int n){
    sort(points, points+n, cmp);

    int m = 0;
    for(int i = 0; i < n; i++){
        while(m >= 2 && cross2D(convexPoints[m-2]- convexPoints[m-1],convexPoints[m-2]- points[i]) < 0)
            m--;
        convexPoints[m++] = points[i];
    }

    for(int i = n-2, t = m+1; i >= 0; i--){
        while(m >= t && cross2D(convexPoints[m-2]- convexPoints[m-1],convexPoints[m-2]- points[i]) < 0)
            m--;
        convexPoints[m++] = points[i];
    }
    return m-1;
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

int main(){
    freopen("in.txt","r",stdin);

    input.grabBuffer();

    int kase;
    kase=input.rInt();

    mathv points[100100];
    mathv convexPoints[100100];
    int totalVertex;

    char tmpc;

    while (kase--){
        totalVertex=input.rInt();
        int pointInConvex=0;
        for (int i=0;i<totalVertex;++i){
            points[pointInConvex].x=input.rInt();
            points[pointInConvex].y=input.rInt();

            tmpc=input.rChar();
            if ( tmpc=='Y' ){
                pointInConvex++;
            }
        }



        convexHull(points,convexPoints,pointInConvex);



        output.print(pointInConvex);
        output.print('\n');

        for (int i=0;i<pointInConvex;++i){
            output.print(convexPoints[i].x);
            output.print(' ');
            output.print(convexPoints[i].y);
            output.print('\n');

        }

    }
    output.flushBuffer();
    return 0;

}

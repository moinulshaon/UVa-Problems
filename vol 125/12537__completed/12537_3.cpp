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

const int maxBufSize = (1 << 24);

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
		for (x = getChar(); x <= '9' && x >= '0'; x = getChar())
			n = (n << 3) + (n << 1) + (x - '0');
		return n;
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


struct mathv{
    int x,y;
}points[210000],circle1,circle2;

int pointsTotal;

double distance2DPointAndPoint(mathv& v1, mathv& v2){
    return sqrt((v2.x - v1.x) * (v2.x - v1.x)+ (v2.y - v1.y) * (v2.y - v1.y));
}

int save[13001];
int save2[13001];

int main()
{

    freopen("in.txt","r",stdin);

    int leaf=13001,a,b;
    int numberofquery;

    input.grabBuffer();

    for (int kk=1;;++kk)
    {
        pointsTotal=input.rInt();
        if (!pointsTotal){
            output.flushBuffer();
            return 0;
        }
        for (int i=0;i<pointsTotal;++i){
            points[i].x=input.rInt();
            points[i].y=input.rInt();
        }
        circle1.x=input.rInt();;
        circle1.y=input.rInt();;
        circle2.x=input.rInt();;
        circle2.y=input.rInt();;
        numberofquery=input.rInt();;

        //scanf("%d %d %d %d %d",&circle1.x,&circle1.y,&circle2.x,&circle2.y,&numberofquery);

        for (int i=0;i<leaf;++i){
            save[i]=0;
            save2[i]=0;
        }


        for (int i=0;i<pointsTotal;++i){
            int tmp=int ( ceil( distance2DPointAndPoint( points[i],circle1 ) ) );

            if (tmp<13001){
                save[tmp]++;
            }
        }

        for (int i=1;i<leaf;++i){
            save[i]+=save[i-1];
        }

        for (int i=0;i<pointsTotal;++i){

            int tmp=int ( ceil( distance2DPointAndPoint( points[i],circle2 ) ) );

            if (tmp<13001){
                save2[tmp]++;
            }
        }

        for (int i=1;i<leaf;++i){
            save2[i]+=save2[i-1];
        }

        output.print("Case ");
        output.print(kk);
        output.print(':');
        output.print('\n');

        while (numberofquery--){
            a=input.rInt();
            b=input.rInt();

            int tmp=pointsTotal-save[a]-save2[b];
            if (tmp<0)tmp=0;

            output.print(tmp);
            output.print('\n');
        }
    }

}

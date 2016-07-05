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
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

const int maxBufSize = (6000000);

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

struct mathv{
    mathv(){x=0;y=0;}
    mathv(LL a,LL b){x=a;y=b;}
    LL x,y;

    mathv operator + (mathv & p){
        mathv tmp( x+p.x,y+p.y );
        return tmp;
    }
    mathv operator - (mathv & p){
        mathv tmp( x-p.x,y-p.y );
        return tmp;
    }

};
LL dot2D(mathv& v1, mathv& v2){
    return v1.x * v2.x + v1.y * v2.y;
}
LL cross2D(mathv v1, mathv v2){
    return v1.x * v2.y - v1.y * v2.x;
}

bool inConvexPolygon(mathv convexPoint[], int total, mathv p) {

	int left = 1, right = total - 1, mid;
	while(right - left > 1) {
		mid = (left + right)/2;
		if(cross2D(convexPoint[0]-convexPoint[mid],convexPoint[0]-p) < 0) right = mid;
		else left = mid;

	}
    //printf("%d %d\n",left,right);
	if(cross2D(convexPoint[0]- convexPoint[left],convexPoint[0]-p) < 0) return false;
	if(cross2D(convexPoint[left]-convexPoint[right],convexPoint[left]-p) < 0) return false;
	if(cross2D(convexPoint[right]-convexPoint[0],convexPoint[right]-p) < 0) return false;
	return true;
}


bool cmp(const mathv& a, const mathv& b){
    if ( a.y!=b.y ){
        return a.y<b.y;
    }else{
        return a.x<b.x;
    }
}

#define SIZE 100100

mathv given[SIZE];

int main(){

    FRO

    input.grabBuffer();

    int kase;
    kase = input.rInt();

    for (int kk=1;kase--;++kk){
        int n,qq;
        n= input.rInt();
        for (int i=0;i<n;++i){
            given[i].x= input.rInt();
            given[i].y= input.rInt();
        }

        //sort( given,given+n,cmp );
        //printf("Case %d:\n",kk);
        mathv tmp;
        qq= input.rInt();
        while ( qq-- ){
            tmp.x= input.rInt();
            tmp.y= input.rInt();

            if ( inConvexPolygon( given,n,tmp ) ){
                output.print("y\n");
            }else{
                output.print("n\n");
            }
        }
    }

    output.flushBuffer();


    return 0;
}

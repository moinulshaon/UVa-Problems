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

using namespace std;

struct lists {
    int start;
    int end;
    double distance;
} a [600000];

int parent [1000];
int size[1000];

int vertex;
int edges;


struct mathv{
    int x,y;
}location[1000];
double distance2DPointAndPoint(mathv& v1, mathv& v2){
    return sqrt((v2.x - v1.x) * (v2.x - v1.x)+ (v2.y - v1.y) * (v2.y - v1.y));
}


bool cmp (lists p, lists q)
{
    if ( p.distance < q.distance ) return true;
    return false;
}

int parentOf (int n)
{
    if ( n == parent [n] ) return n;
    return parent [n] = parentOf (parent [n]);
}



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


int main ()
{

    freopen("in.txt","r",stdin);

    input.grabBuffer();

    int test;
    test=input.rInt();

    while  ( test-- )
    {

        int costperairport;

        vertex=input.rInt();

        for (int i=0;i<vertex;++i){
            location[i].x=input.rInt();
            location[i].y=input.rInt();
        }

        for (int i=0;i< vertex; ++i ){
            parent [i] = i;
            size[i]=1;
        }


        int length_of_a=0;
        for (int i=0;i<vertex;++i){
            for (int j=i+1;j<vertex;++j){
                a [length_of_a].start = i;
                a [length_of_a].end = j;
                a [length_of_a].distance = distance2DPointAndPoint( location[i],location[j] );
                length_of_a++;
            }
        }


        sort (a, a + length_of_a, cmp);


        int selectedEdges = vertex - 1;
        int alreadyConnected,x,y;

        alreadyConnected=input.rInt();
        for ( int i = 0; i < alreadyConnected ; i++ ){
            x=input.rInt();
            y=input.rInt();

            int p = parentOf (x-1);
            int q = parentOf (y-1);

            if ( p != q ) {
                if (size[p]>size[q])swap(p,q);
                size[q]+=size[p];
                parent [p] = q;
                selectedEdges--;
            }
        }
        if ( !selectedEdges ){
            output.print("No new highways need\n");
        }

        for ( int i = 0; i < length_of_a && selectedEdges; i++ ) {
            int p = parentOf (a [i].start);
            int q = parentOf (a [i].end);

            if ( p != q ) {
                if (size[p]>size[q])swap(p,q);
                size[q]+=size[p];
                parent [p] = q;
                selectedEdges--;
                output.print(a[i].start+1);
                output.print(' ');
                output.print(a[i].end+1);
                output.print('\n');
            }
        }
        if (test )
            output.print("\n");

    }
    output.flushBuffer();
	return 0;
}

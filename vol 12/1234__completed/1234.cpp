#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct lists {
    int start;
    int end;
    int distance;
} a [110000];

int parent [11000];
int size[11000];
int vertex;
int edges;

bool cmp (lists p, lists q)
{
    if ( p.distance > q.distance ) return true;
    return false;
}

int parentOf (int n)
{
    if ( n == parent [n] ) return n;
    return parent [n] = parentOf (parent [n]);
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

int main ()
{
    freopen("in.txt","r",stdin);

    input.grabBuffer();

    int test;
    test=input.rInt();

    while ( test-- )
    {

        vertex=input.rInt();
        edges=input.rInt();


        for (int i=0;i< vertex; ++i )
        {
            parent [i] = i;
            size[i]=1;
        }


        int x,y,z,length_of_a=0;
        for ( int i = 0; i < edges; i++ )
        {
            x=input.rInt();
            y=input.rInt();
            z=input.rInt();
            a [length_of_a].start = x-1;
            a [length_of_a].end = y-1;
            a [length_of_a].distance = z;
            length_of_a++;
        }


        sort (a, a + length_of_a, cmp);

        int selectedEdges = vertex - 1;
        int i;
        int sum=0;

        for ( i = 0; i < length_of_a && selectedEdges; i++ ) {
            int p = parentOf (a [i].start);
            int q = parentOf (a [i].end);

            if ( p != q ) {
                if (size[p]>size[q])swap(p,q);
                size[q]+=size[p];
                parent [p] = q;
                selectedEdges--;
            }else{
                sum+=a[i].distance;
            }
        }



        for (;i<length_of_a;++i){
            sum+=a[i].distance;
        }
        output.print(sum);
        output.print('\n');
    }
    output.flushBuffer();
	return 0;
}

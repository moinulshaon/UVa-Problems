#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct lists {
    int start;
    int end;
    long long distance;
} a [1100000];

int parent [1100];
int size[1100];
int vertex;
int edges;

bool cmp (lists p, lists q)
{
    if ( p.distance < q.distance ) return true;
    return false;
}


struct mathv{
    long long x,y;
}location[1100];


double distance2DPointAndPoint(mathv& v1, mathv& v2){
    return sqrt((v2.x - v1.x) * (v2.x - v1.x)+ (v2.y - v1.y) * (v2.y - v1.y));
}


int parentOf (int n)
{
    if ( n == parent [n] ) return n;
    return parent [n] = parentOf (parent [n]);
}

const int maxBufSize (1<<20);

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

int main ()
{

    freopen("in.txt","r",stdin);

    input.grabBuffer();

    int test;
    test=input.rInt();

    while  (test-- )
    {

        int trasmiter;
        trasmiter=input.rInt();


        int x,y,z,length_of_a=0;

        vertex=0;
        while (true ){

            x=input.rInt();

            if ( x==-1 )break;
            y=input.rInt();
            location[vertex].x=x;
            location[vertex].y=y;
            vertex++;
        }

        for (int i=0;i< vertex; ++i )
        {
            parent [i] = i;
            size[i]=1;
        }


        for ( int i = 0; i < vertex; i++ ){

            for (int j=i+1;j<vertex;++j){
                a [length_of_a].start = i;
                a [length_of_a].end = j;
                a [length_of_a].distance = int( ceil( distance2DPointAndPoint(location[i],location[j]) ) );
                length_of_a++;
            }

        }

        sort (a, a + length_of_a, cmp);

        int selectedEdges = vertex  -trasmiter;

        //printf("%d\n",selectedEdges);

        long long  result=0;

        for ( int i = 0; i < length_of_a && selectedEdges; i++ ) {
            int p = parentOf (a [i].start);
            int q = parentOf (a [i].end);

            if ( p != q ) {
                if (size[p]>size[q])swap(p,q);
                size[q]+=size[p];
                parent [p] = q;
                selectedEdges--;

                result=a[i].distance;

            }
        }
        printf("%lld\n",result);

    }

	return 0;
}

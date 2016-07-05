#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int totalnode,totaledge;
struct EDGES
{
    int start,finish;
}edge[1100];

int d[110][210];


void bellmanford(int source,int day)
{
        for (int i = 1; i <= totalnode; ++i)
            for (int j=0;j<=day;++j)
                d[i][j] = 0;

        d[source][0] = 1;

        for (int i = 1; i <=day ; ++i)
                for (int j = 0; j < totaledge; ++j)
                        if ( d[ edge[j].start ][i-1] )
                            d[ edge[j].finish ][i] = 1;
}
const int maxBufSize = (1 << 19);

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


int main()
{
    freopen("in.txt","r",stdin);

    int tmp,start,end,day;
    input.grabBuffer();

    while (true)
    {
        totalnode=input.rInt();
        tmp=input.rInt();
        if ( !totalnode && !tmp){
            output.flushBuffer();
            return 0;
        }
        totaledge=0;
        for (int i=0;i<tmp;++i){
            edge[totaledge].start=input.rInt();
            edge[totaledge].finish=input.rInt();
            totaledge++;
            edge[totaledge].start=edge[totaledge-1].finish;
            edge[totaledge].finish=edge[totaledge-1].start;
            totaledge++;
        }
        start=input.rInt();
        end=input.rInt();
        day=input.rInt();
        bellmanford(start,day);
        if ( d[end][day] ){
            output.print("Yes, Teobaldo can travel.\n");
        }else{
            output.print("No, Teobaldo can not travel.\n");
        }
    }

}

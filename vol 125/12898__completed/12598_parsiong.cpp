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

using namespace std;

typedef long long LL;

const int maxBufSize = (8000000);

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

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 51000

int arr[SIZE];
int mp[SIZE];
int cnt;
int n;

int bsearch(int x){
    int low=1,high=cnt;
    while ( low<=high ){
        int mid=(low+high)/2;
        if ( x>=arr[mid] )low=mid+1;
        else high= mid-1;
    }

    return cnt+1-low;
}

int shaonsearch(int pos){
    int low=1,high=pos;
    while ( low<=high ){
        int mid=(low+high)/2;
        //printf("%d %d\n",mid, bsearch( mid ));
        if ( mid+ bsearch( mid )< pos ){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return low;
}

int main(){
    FRO

    input.grabBuffer();

    int kase;
    kase=input.rInt();

    for (int kk=1;kase--;++kk){
        int qq;
        n=input.rInt();
        cnt=input.rInt();
        qq=input.rInt();


        for (int i=1;i<=cnt;++i){
            arr[i]=input.rInt();
            mp[ i ]= arr[i];
        }

        //arr[cnt+1]= (1<<30);

        sort( arr+1,arr+cnt+1 );

        output.print("Case ");
        output.print(kk);
        output.print(":\n");
        int x;
        while ( qq-- ){
            x=input.rInt();

            if ( x <=cnt ){
                output.print(mp[x]);
            }else{
                output.print(shaonsearch(x));
            }
            output.print('\n');
        }
    }

    output.flushBuffer();

    return 0;
}

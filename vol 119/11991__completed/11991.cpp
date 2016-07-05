#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>

using namespace std;

typedef long long LL;

typedef map<int,int> mii;

#define SIZE 101000
#define PB push_back
#define FRO freopen("in.txt","r",stdin);

vector<int> v[SIZE];
const int maxBufSize = 5500000;

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
}input;
int main(){

    FRO
    input.grabBuffer();
    int n,q;

    while( !input.bufEof() ){

        n=input.rInt();
        q=input.rInt();

        int tmp,a,b,total=0;
        mii mp;
        for(int i=1;i<=n;++i){
            tmp=input.rInt();
            if ( mp.find(tmp)==mp.end() ){
                v[total].clear();
                mp[ tmp ]=total++;
            }

            v[ mp[tmp] ].PB( i );
        }

        while(q--){
            b=input.rInt();
            a=input.rInt();
            if ( mp.find(a)==mp.end() || b > v[ mp[a] ].size() ){
                printf("0\n");
                continue;
            }
            printf("%d\n",v[ mp[a] ][ b-1 ]);
        }

    }
    return 0;

}

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

#define SIZE 500100
#define MP make_pair

LL sum[SIZE];
set< pair<LL,int> > ss;

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
}input;

int main(){

    FRO

    input.grabBuffer();

    int kase;
    kase=input.rInt();

    while(kase--){
        int n,x;
        n=input.rInt();
        x=input.rInt();

        int tmp = 0;
        sum[0] = 0;
        for(int i=1;i<=n;++i){
            tmp=input.rInt();
            sum[i]= sum[i-1]+tmp;
            //cout<<sum[i]<<" ";
        }

        ss.clear();

        int ans = n+100;
        int cnt = 1;
        ss.insert( MP( sum[0],0 ) );

        for (int i=1;i<=n;++i){
            while ( cnt && sum[i]-(*ss.begin()).first>=x ){
                ans = min( ans , i-(*ss.begin()).second );
                ss.erase( ss.begin() );
                cnt--;
            }
            ss.insert( MP( sum[i],i ) );
            cnt++;
        }
        if ( ans>n )ans = -1;
        printf("%d\n",ans);
    }


    return 0;
}

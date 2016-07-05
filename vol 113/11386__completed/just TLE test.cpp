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

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<LL,int> pint;
typedef map<int,int> mint;

#define SIZE 5010

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
}input;

pint arr[SIZE];
LL save[SIZE];


int main(){
    FRO

    input.grabBuffer();
    int n;

    while ( !input.bufEof() ){
        n=input.rInt();

        LL tmp;
        for (int i=1;i<=n;++i){
            save[i]=input.rInt();
        }
        sort( save+1,save+n+1 );

        int len=0;
        for (int i=1;i<=n;++i){
            if ( arr[len].first  != save[i] ){
                arr[++len].first=save[i];
                arr[len].second=1;
            }else{
                arr[len].second++;
            }
        }


        LL ans=0;

        for (int i=1;i<=len;++i){
            int left=1,right=i+1;

            while ( right <=len && left<=i ){
                if ( arr[right].first-arr[left].first == arr[i].first ){
                    if ( left!= i )
                        ans+= arr[right].second*arr[left].second*arr[i].second ;
                    else
                        ans+= arr[right].second*( arr[left].second)*( arr[i].second -1 )/2;
                    right++;
                }else if ( arr[right].first-arr[left].first >arr[i].first ){
                    left++;
                }else{
                    right++;
                }
            }
            //printf("%d %lld\n",i,ans);
        }



        printf("%lld\n",ans);
    }

    return 0;
}

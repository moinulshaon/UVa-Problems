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
}input;

#define SIZE 500100

int tree[SIZE];

int MaxVal;
int read(int idx){
	int sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx ,int val){
	while (idx <= MaxVal){
		tree[idx] += val;
		idx += (idx & -idx);
    }
}
struct tt{
    bool bridge;
    int h;
}save[SIZE];

pint query[SIZE];

bool cmp( const tt& a ,const tt& b ){
    return a.h<b.h;
}

mint mp;

int main(){
    FRO

    input.grabBuffer();
    int n,m,k;

    for ( int kk=1; !input.bufEof()  ;++kk ){

        n=input.rInt();
        m=input.rInt();
        k=input.rInt();

        int total=0;

        for (int i=0;i<n;++i){
            save[total].h=input.rInt();
            save[total++].bridge=true;
        }

        int a,b;
        for (int i=0;i<m;++i){
            a=input.rInt();
            b=input.rInt();

            query[i]=make_pair( a,b );
            save[total].h=a;
            save[total++].bridge=false;

            save[total].h=b;
            save[total++].bridge=false;
        }

        sort( save,save+total,cmp );

        mp.clear();

        MaxVal=0;
        mp[1]=++MaxVal;
        for (int i=0;i<total;++i){
            if ( mp.find( save[i].h )== mp.end() ){
                mp[ save[i].h  ]=++MaxVal;
            }
        }
        CLR(tree);
        int le=1;
        for (int i=0;i<m;++i){
            update( le+1 ,1 );
            update( mp[ query[i].first ]+1 , -1 ) ;
            //printf("ss %d %d\n",le+1,mp[ query[i].first ]+1);
            le= mp[ query[i].second ];
        }


        int ans=0;
        for (int i=0;i<total;++i){
            if ( save[i].bridge ){
                ans+= ( read( mp[ save[i].h ] ) >= k );
                //printf("%d %d %d\n",save[i].h,mp[save[i].h],read( mp[ save[i].h ] ));
            }
        }
        printf("Case %d: %d\n",kk,ans);

    }


    return 0;
}

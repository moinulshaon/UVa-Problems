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

#define SIZE 60010

set<int> ss[SIZE];
int val[SIZE];
map<int,int> mp;

int n;
int tree[SIZE];

int read(int idx){
	int sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx ,int val){
	while (idx <= SIZE -3 ){
		tree[idx] += val;
		idx += (idx & -idx);
    	}
}

struct tt{
    int first,second,ser,result;
}query[50100];

bool cmp( const tt&x,const tt&y ){
    return x.first<y.first;
}
bool cmp2( const tt&x,const tt&y ){
    return x.ser<y.ser;
}



int main(){
    FRO

    input.grabBuffer();

    while ( !input.bufEof() ){
        n=input.rInt();
        int qq=input.rInt();

        for (int i=0;i<SIZE;++i){
            ss[i].clear();
        }

        CLR(tree);

        int cnt=1;
        for (int i=1;i<=n;++i){
            val[i]=input.rInt();
            if ( mp.find( val[i] ) == mp.end() ){
                mp[ val[i] ]=cnt++;
                update( i,1 );
            }
            ss[ mp[ val[i] ] ].insert( i );
        }


        bool res=false;

        int le,ri;
        int querynum=0;
        while ( qq-- ){
            char cc=input.rChar();
            le=input.rInt()+1;
            ri=input.rInt()+1;

            if ( cc== 'Q' ){

                if ( res ){

                }else{
                    query[ querynum ].first=le;
                    query[ querynum ].second=ri;
                    query[ querynum ].ser= querynum++;
                }
            }else{

                if ( querynum  ){

                    sort( query,query+querynum ,cmp);
                    int left=1,tmp;
                    for (int i=0;i<querynum;++i){

                        for (int j=left;j<query[i].first;++j,++left){

                            set<int>::iterator it=ss[ mp[ val[j] ] ].end();
                            it--;
                            update( v[ arr[j] ][tmp],-1 );
                            update( v[ arr[j] ][tmp-1],1 );


                            v[ arr[j] ].pop_back();

                        }

                        query[i].result=read(query[i].second)-read(query[i].first-1);
                    }

                    sort(query,query+qq,cmp2);
                }
            }
        }

    }


    return 0;
}

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

const int maxBufSize = 5000000;

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

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);
#define SIZE 100100

int MaxVal;

int read(int idx,int *tree){
	int sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx ,int val,int *tree){
	while (idx <= MaxVal){
		tree[idx] += val;
		idx += (idx & -idx);
    	}
}

int neg[SIZE];
int zero[SIZE];

int main(){


    input.grabBuffer();

    while( !input.bufEof() ){

        memset(neg,0,sizeof(neg));
        memset(zero,0,sizeof(zero));

        MaxVal=input.rInt();
        int query=input.rInt();
        int tmp;
        for (int i=1;i<=MaxVal;++i){
            tmp=input.rInt();
            if ( tmp<0 ){
                update(i,1,neg);
            }else if ( tmp==0 ){
                update(i,1,zero);
            }
        }
        int left,right,zz;
        char q;
        while(query--){
            q=input.rChar();
            if ( q=='C' ){
                left=input.rInt();
                right=input.rInt();
                tmp=read(left,neg)-read(left-1,neg) ;

                if ( tmp>0 ){
                    if ( right>=0 ){
                        update( left,-1,neg );
                    }
                }else if (right<0){
                    update( left,1,neg );
                }

                tmp=read(left,zero)-read(left-1,zero) ;

                if ( tmp>0 ){
                    if ( right!=0 ){
                        update( left,-1,zero );
                    }
                }else if (right==0){
                    update( left,1,zero );
                }
            }else {
                left=input.rInt();
                right=input.rInt();
                if ( read( right ,zero)-read( left-1 ,zero) > 0 ){
                    printf("0");
                }else {
                    //printf("\n%d\n",read( right ,neg )-read( left-1 ,neg));
                    if ( (read( right ,neg )-read( left-1 ,neg) ) %2==0 ){
                        printf("+");
                    }else{
                        printf("-");
                    }
                }
            }
        }
        printf("\n");
    }

    return 0;
}

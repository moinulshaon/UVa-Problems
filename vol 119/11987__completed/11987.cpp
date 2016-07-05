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

const int maxBufSize = 5*1024*1024+100;

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

#define SIZE 200100

int parent[SIZE];
int size[SIZE];
int sum[SIZE];

int parentOf (int n){
    if ( n == parent [n] ) return n;
    return parent [n] = parentOf (parent [n]);
}

void makeUnion(int p,int q){
    if (size[p]>size[q])swap(p,q);
    size[q]+=size[p];
    sum[q]+=sum[p];
    parent [p] = q;
}

int nxt[SIZE];
int val[SIZE];

int func(int x){
    if ( nxt[x]== -1 ){
        return x;
    }else{
        return nxt[x]=func(nxt[x]);
    }
}



int main(){

    FRO

    input.grabBuffer();

    while( !input.bufEof() ){

        int vertex=input.rInt();
        int query=input.rInt();

        int qq,a,b;

        for (int i=1;i<=vertex+query;++i){
            parent[i]=i;
            size[i]=1;
            sum[i]=i;
            val[i]=i;
            nxt[i]= -1;
        }
        int total=vertex;
        while(query--){
            qq=input.rInt();

            if ( qq==1 ){
                a=input.rInt();
                b=input.rInt();

                a=func(a);
                b=func(b);

                int p = parentOf (a);
                int q = parentOf (b);
                if ( p != q ) {
                    makeUnion(p,q);
                }
            }else if ( qq==2 ){
                a=input.rInt();
                b=input.rInt();

                a=func(a);
                b=func(b);

                int p = parentOf (a);
                int q = parentOf (b);

                if( p!=q ){
                    total++;
                    nxt[a]=total;
                    val[total]=val[a];
                    parent[total]=q;
                    val[a]=0;
                    sum[q]+=val[total];
                    size[q]++;
                    sum[p]-=val[total];
                    size[p]--;
                }
            }else{
                a=input.rInt();
                a=func(a);
                int p = parentOf (a);
                printf("%d %d\n",size[ p ],sum[p]);
            }
        }
    }
    return 0;
}

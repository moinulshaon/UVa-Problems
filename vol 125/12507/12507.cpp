#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct lists {
    int start;
    int end;
    int distance;
} a [100+ 10];

int parent [20];

bool cmp (lists p, lists q)
{
    if ( p.distance < q.distance ) return true;
    return false;
}

int parentOf (int n)
{
    if ( n == parent [n] ) return n;
    return parent [n] = parentOf (parent [n]);
}

int pop[20];

bool check(int N,int pos){
    return (bool)(N & (1<<pos));
}

const int maxBufSize = (1 << 22);

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
    //freopen("in.txt","r",stdin);
    input.grabBuffer();
    int n,m,lim,kase;

    kase=input.rInt();

    while(kase--){
        n=input.rInt();
        m=input.rInt();
        lim=input.rInt();

        for (int i=0;i<n;++i){
            pop[i]=input.rInt();
        }

        for (int i=0;i<m;++i){
            a[i].start=input.rInt();
            a[i].end=input.rInt();
            a[i].distance=input.rInt();
            a[i].start--;
            a[i].end--;
        }

        sort(a,a+m,cmp);
        int ans=0;

        for (int i=(1<<n)-1;i>0;--i){

            if ( check(i,0)==0 )continue;
            //printf("shoan %d\n",i);
            int sum=0,city=0;
            for (int j=0;j<n;++j){
                if ( check( i,j )==1 ){
                    sum+=pop[j];
                    ++city;
                }
            }
            if ( sum<=ans )continue;

            for (int j=0;j<n;++j){
                parent[j]=j;
            }
            int cost=0;
            for (int j=0;j<m;++j){
                if ( check( i,a[j].start )==1 && check( i,a[j].end )==1  ){

                    int p = parentOf (a [j].start);
                    int q = parentOf (a [j].end);
                    //printf("shoan %d %d\n",p,q);
                    if ( p != q ) {
                        parent [p] = q;
                        cost+= a[j].distance;
                        --city;
                        //printf("%d\n",a[j].distance);
                    }
                }
            }
            //printf("%d\n",cost);
            if ( cost<=lim && city==1 )ans=sum;
        }
        printf("%d\n",ans);
    }
    return 0;
}

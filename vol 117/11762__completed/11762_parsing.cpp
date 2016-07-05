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


#define SIZE 1000100

bool prime[SIZE];
vector<int> p;
int num[SIZE];

void fact( vector<int>& ff,int x ){

    for (int i=0;LL( p[i] )*p[i] <=x ;++i ){
        if ( x%p[i] ==0 ){
            while ( x%p[i]==0 ){
                x/=p[i];
            }
            ff.PB(p[i]);
        }
    }
    if ( x!= 1 ){
        ff.PB(x);
    }

}

bool vis[SIZE];
double dp[SIZE];

double func(int x){

    if ( x==0 )return 0;
    if ( !prime[x] )return num[x];

    if ( vis[x] )return dp[x];

    vector<int> fac;
    fact(fac,x);

    int cnt=fac.size();
    double sum=0;
    for (int i=0;i<cnt;++i){
        sum += ( 1.0/ num[x] )* func( x/fac[i] );
    }

    vis[x]=true;
    return dp[x] = ( 1 + sum )*num[ x ] / cnt;
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

    for (int i=2;i<=1000;++i){
        if ( !prime[i] ){
            for (int j=2*i;j<SIZE;j+=i){
                prime[j]=true;
            }
        }
    }
    int cnt=1;
    for (int i=2;i<SIZE;++i){
        if ( !prime[i] ){
            p.PB(i);
            num[i]=cnt++;
        }else{
            num[i]=num[i-1];
        }
    }

    //printf("%d\n",p.size());


    input.grabBuffer();

    int kase;
    kase=input.rInt();
    for (int kk=1;kase--;++kk){
        int n=input.rInt();

        printf("Case %d: %.10lf\n",kk,func(n));
    }

    return 0;
}

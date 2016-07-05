#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int set(int N,int pos){
    return N=N | (1<<pos);
}
int reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool check(int N,int pos){
    return (bool)(N & (1<<pos));
}
int row,col;

int rc(int a,int b){
    return a*row+b;
}

int dp[5][5][1<<16+2];

int numberOne(int s){
    int cnt=0;
    while ( s ){
        if ( s & 1  )
            ++cnt;
        s>>=1;
    }
    return cnt;
}

void print(int n){
    string s;
    while (n){
        s+=(n&1)?"1":"0";
        n>>=1;
    }
    reverse(s.begin(),s.end());
    printf("%16s\n",s.c_str());
}

int func( int state ){
    //print(state);
    //getchar();
    if ( numberOne(state)== 1 ){
        return 1;
    }

    if ( dp[row][col][state]!=-1 )return dp[row][col][state];
    int sum=0;
    for (int i=0;i<row;++i){
        for (int j=0;j<col;++j){
            if ( check( state,rc(i,j) )==0 )
                continue;

            if ( j+2<col && check( state, rc(i,j) )==1 && check( state,rc(i,j+1))==1 && check( state,rc(i,j+2))==0 ){
                sum+=func( reset( reset( set( state,rc( i,j+2 ) ) , rc(i,j+1) )  ,rc( i,j ) ) );
            }
            if (i+2<row && j+2<col && check( state, rc(i,j) )==1 && check( state, rc(i+1,j+1) )==1 &&check( state, rc(i+2,j+2))==0 ){
                sum+=func( reset( reset( set( state,rc( i+2,j+2 ) ) ,rc( i+1,j+1 ) ),rc(i,j) ) );
                //printf("here\n");
            }
            if ( i+2<row && check( state, rc(i,j))==1 && check( state,rc(i+1,j))==1 && check( state,rc(i+2,j))==0 ){
                sum+=func( reset( reset( set( state,rc( i+2,j ) ) ,rc( i+1,j ) ) ,rc(i,j) ) );
            }
            if (i+2<row && j-2 >=0 && check( state,rc(i,j))==1 && check( state,rc(i+1,j-1))==1 && check( state,rc(i+2,j-2))==0 ){
                sum+=func( reset( reset( set( state,rc( i+2,j-2 ) ) ,rc( i+1,j-1 ) ),rc(i,j) ) );
            }
            if ( j-2 >=0 && check( state,rc(i,j))==1 && check( state,rc(i,j-1))==1 && check( state,rc(i,j-2))==0 ){
                sum+=func( reset( reset( set( state,rc( i,j-2 ) ) ,rc( i,j-1 ) ),rc(i,j) ) );
            }
            if (i-2>=0 && j-2 >=0 && check( state,rc(i,j))==1 && check( state,rc(i-1,j-1))==1 && check( state,rc(i-2,j-2))==0 ){
                sum+=func( reset( reset( set( state,rc( i-2,j-2 ) ) ,rc( i-1,j-1 ) ) ,rc(i,j) ) );
            }
            if (i-2>=0 && check( state,rc(i,j) )==1 && check( state,rc(i-1,j))==1 && check( state,rc(i-2,j))==0 ){
                sum+=func( reset( reset( set( state,rc( i-2,j ) ) ,rc( i-1,j ) ) ,rc(i,j)  ) );
            }
            if (i-2>=0 && j+2 <col && check( state, rc(i,j))==1 && check( state,rc(i-1,j+1))==1 && check( state,rc(i-2,j+2))==0 ){
                sum+=func( reset( reset( set( state,rc( i-2,j+2 ) ) ,rc( i-1,j+1 ) ),rc(i,j) ) );
            }
        }
    }
    return dp[row][col][state]=sum;
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
    freopen("in.txt","r",stdin);
    input.grabBuffer();
    memset(dp,-1,sizeof(dp));
    int kase,num;
    kase=input.rInt();

    for (int kk=1;kase--;++kk){

        row=input.rInt();
        col=input.rInt();
        num=input.rInt();
        int n=0,a,b;
        while ( num-- ){
            a=input.rInt();
            b=input.rInt();
            n=set( n,rc(a-1,b-1) );
            //print(n);
        }

        printf("Case %d: %d\n",kk,func(n));

    }
    return 0;

}

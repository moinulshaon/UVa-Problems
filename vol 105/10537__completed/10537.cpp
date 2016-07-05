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
#include <cctype>
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

const int maxBufSize = (6500000);

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

int num(char c){
    if ( isupper(c) )return c-'A';
    else return c-'a'+26;
}

vector<int> out[60];

LL vis[60];

struct node{
    LL val;
    int city;
    int prv;
    bool operator < (const node & p)const{return val>p.val;}
};
LL costfunc( int num,LL cc ){
    if ( num>=26 )return cc+1;
    else{

        LL y= cc/20+( cc%20!=0 );
        LL x=  (cc+y)/20+( (cc+y) %20!=0 ) ;
        while ( x!= y ){
            //printf("%d %d\n",x,y);
            y= (cc+x)/20+( (cc+x) %20!=0 );
            x=  (cc+y)/20+( (cc+y)%20!=0 );
        }
        return cc+y;
    }
}
char shaon(int x){
    if ( x>=26 )return x-26+'a';
    else return x+'A';
}

int prvnode[60];

void dijkstra(int s,int f,int mul){

    NEG(prvnode);

    for (int i=0;i<60;++i){
        vis[i]= (1LL<<50);
    }

    node place,temp,u;
    place.val=mul ;
    place.city=s;
    place.prv= -1;

    priority_queue<node> q;

    q.push(place);


    while (!q.empty()){

        temp=q.top();q.pop();

        //printf("xx %c %d %c\n",shaon(temp.city),temp.val,shaon(temp.prv) );


        if ( temp.val > vis[temp.city] ){
            if ( temp.city == f )break;
            else   continue;
        }

        if ( temp.val == vis[temp.city] ){
            prvnode[temp.city]=min( prvnode[temp.city], temp.prv );
            continue;
        }

        vis[temp.city]=temp.val;
        prvnode[temp.city]=temp.prv;

        for (int i=0;i<out[temp.city].size();++i){
            u.city=out[temp.city][i];
            u.val=costfunc(  temp.city , temp.val );
            u.prv= temp.city;

            if ( vis[u.city] >= u.val ){
                 q.push(u);
            }
        }
    }
    printf("%lld\n",vis[f]);

    int to=f;
    while (prvnode[to]!=-1){
        //printf("%d ",to);
        printf("%c-",shaon(to));
        to=prvnode[to];
    }
    //printf("%d\n",to);
    printf("%c\n",shaon(to));
}

int main(){

    FRO
    input.grabBuffer();

    int ee;
    for (int kk=1; true ;++kk){

        ee=input.rInt();
        if ( ee == -1 )break;

        for (int i=0;i<60;++i){
            out[i].clear();
        }

        int u,v;
        while ( ee-- ){
            u= num( input.rChar() );
            v= num( input.rChar() );

            out[u].PB(v);
            out[v].PB(u);
        }

        int mul=input.rInt();
        int ss=num( input.rChar() );
        int ff=num( input.rChar() );

        printf("Case %d:\n",kk);
        dijkstra( ff ,ss ,mul );

    }


    return 0;
}

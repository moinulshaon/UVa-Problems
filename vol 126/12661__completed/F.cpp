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

const int maxBufSize = (5000000);

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

#define SIZE 310

vector <int> edge[SIZE], cost[SIZE];
vector<pint> ww[SIZE];

struct node{
    LL val;
    int city;
    bool operator < (const node & p)const{return val>p.val;}
};


LL dijkstra(int s,int f){

    bool vis[SIZE]={false};

    node place,temp,u;
    place.val=0;
    place.city=s;


    priority_queue<node> q;

    q.push(place);

    int a,b;

    while (!q.empty()){
        temp=q.top();q.pop();
        if (temp.city==f)return temp.val;

        if (vis[temp.city])
            continue;
        vis[temp.city]=true;

        //printf("%d %d\n",temp.city,temp.val);

        for (int i=0;i<edge[temp.city].size();++i){
            u.val=cost[temp.city][i]+temp.val;

            a= ww[temp.city][i].first;
            b= ww[temp.city][i].second;

            if ( a-temp.val%(a+b)< cost[temp.city][i] ){
                u.val = u.val + a+b -temp.val%(a+b) ;
            }

            u.city=edge[temp.city][i];

            if ( !vis[ u.city ] )
                q.push(u);
        }
    }
    exit(5);
    return -1;
}

int main(){
    FRO

    input.grabBuffer();
    int n,m,s,t;

    for (int kk=1;!input.bufEof() ;++kk ){
        n=input.rInt();
        m=input.rInt();
        s=input.rInt();
        t=input.rInt();

        int u,v,a,b,cc;

        for (int i=0;i<SIZE;++i){
            edge[i].clear();
            cost[i].clear();
            ww[i].clear();
        }

        while ( m-- ){
            u=input.rInt();
            v=input.rInt();
            a=input.rInt();
            b=input.rInt();
            cc=input.rInt();


            if ( cc>a ){
                cc=(1<<29);
            }

            edge[u].PB( v );
            cost[u].PB( cc );
            ww[u].PB( make_pair(a,b) );
        }

        printf("Case %d: %lld\n",kk,dijkstra(s,t));
    }


    return 0;
}

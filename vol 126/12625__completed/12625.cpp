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

int n,ee;

bool gas[260];

vector <int> edge[260], cost[260];

struct node{
    int val,city,rem;
    bool operator < (const node & p)const{return val>p.val;}
};


bool vis[260][101];

int dijkstra(int s,int f){

    CLR(vis);

    node place,temp,u;
    place.val=0;
    place.city=s;
    place.rem=100;


    priority_queue<node> q;

    q.push(place);


    while (!q.empty()){

        temp=q.top();q.pop();
        if (temp.city==f)return temp.val;

        if (vis[temp.city][temp.rem])
            continue;
        vis[temp.city][temp.rem]=true;


        for (int i=0;i<edge[temp.city].size();++i){

            if ( cost[temp.city][i]<=temp.rem ){
                u.val=cost[temp.city][i]+temp.val;
                u.city=edge[temp.city][i];

                if ( gas[ u.city ] )u.rem=100;
                else u.rem=temp.rem-cost[temp.city][i];

                if ( !vis[u.city][u.rem] )
                    q.push(u);
            }
        }
    }
    return -1;
}


int main(){
    FRO

    input.grabBuffer();

    int kase;
    kase=input.rInt();
    char cc;
    for (int kk=1;kase--;++kk){
        int qq;
        n=input.rInt();
        ee=input.rInt();
        qq=input.rInt();

        for (int i=1;i<=n;++i){
            cc=input.rChar();
            if ( cc=='O' ){
                gas[i]=false;
            }else{
                gas[i]=true;
            }
            edge[i].clear();
            cost[i].clear();
        }

        int u,v,w;
        for (int i=0;i<ee;++i){
            u=input.rInt();
            v=input.rInt();
            w=input.rInt();
            edge[u].PB(v);
            cost[u].PB(w);

            edge[v].PB(u);
            cost[v].PB(w);

        }


        printf("CASE %d\n",kk);
        while( qq-- ){
            u=input.rInt();
            v=input.rInt();

            int ans=dijkstra(u,v);

            if ( ans== -1 )printf("NO GAS PATH\n");
            else printf("%d\n",ans);
        }

    }


    return 0;
}

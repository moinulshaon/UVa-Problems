#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;
#define SIZE 1005

vector <int> edge[SIZE], cost[SIZE];
int total;
int dis[SIZE];

struct node{
    int val,city;
    bool operator < (const node & p)const{return val>p.val;}
};


void dijkstra(int s,int f){
    bool vis[SIZE]={false};

    node place,temp,u;
    place.val=0;
    place.city=s;




    priority_queue<node> q;

    q.push(place);


    while (!q.empty()){
        temp=q.top();q.pop();

        if (vis[temp.city])
            continue;
        vis[temp.city]=true;
        dis[ temp.city ]=temp.val;

        for (int i=0;i<edge[temp.city].size();++i){
            u.val=cost[temp.city][i]+temp.val;
            u.city=edge[temp.city][i];
            if ( !vis[u.city] )
                q.push(u);
        }
    }
}

int dp[SIZE];
int func(int x){
    if ( x==2 )return 1;
    if ( dp[x]!= -1 )return dp[x];

    int sum=0,y;
    for (int i=0;i<edge[x].size();++i){
        y=edge[x][i];
        if ( dis[y]<dis[x] ){
            sum+=func(y);
        }
    }
    return dp[x]=sum;
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
    int ee,a,b,w;
    while (true){

        total=input.rInt();
        if ( !total )return 0;
        ee=input.rInt();


        for (int i=0;i<=total;++i){
            edge[i].clear();
            cost[i].clear();
        }

        while( ee-- ){
            a=input.rInt();
            b=input.rInt();
            w=input.rInt();

            edge[a].push_back( b );
            cost[a].push_back( w );

            edge[b].push_back( a );
            cost[b].push_back( w );
        }

        dijkstra(2,1);
        memset(dp,-1,sizeof(dp));
        printf("%d\n",func(1));
    }

    return 0;
}

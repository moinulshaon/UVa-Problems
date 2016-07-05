#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

#define SIZE 105

vector <int> edge[SIZE];
vector <double> cost[SIZE],deg[SIZE];
int total;

const double EPS=1e-2;

int prvnode[SIZE];
int save[SIZE];

struct node
{
    double val;
    int city;
    int prv;
    bool operator < (const node & p)const{return val>p.val;}
};

double ansdis;

bool dijkstra(int s,int f,double lim){
    bool vis[SIZE]={false};
    memset(prvnode,-1,sizeof(prvnode));

    node place,temp,u;
    place.val=0;
    place.city=s;
    place.prv=-1;

    priority_queue<node> q;

    q.push(place);


    while (!q.empty()){
        temp=q.top();q.pop();
        if (temp.city==f){
            ansdis=temp.val;
            prvnode[ temp.city ]=temp.prv;
            return true;
        }

        if (vis[temp.city])
            continue;
        vis[temp.city]=true;
        prvnode[ temp.city ]=temp.prv;

        for (int i=0;i<edge[temp.city].size();++i){

            if ( deg[ temp.city ][i] > lim )continue;

            u.val=cost[temp.city][i]+temp.val;
            u.city=edge[temp.city][i];
            u.prv=temp.city;
            q.push(u);
        }
    }
    return false;
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
};

int main()
{

    freopen("in.txt","r",stdin);
    int e;
    int a,b;
    double dd,tt;

    while (scanf("%d %d",&total,&e)==2){
        for (int i=0;i<=total;++i){
            edge[i].clear();
            cost[i].clear();
            deg[i].clear();
        }

        int s,f;
        scanf("%d %d",&f,&s);
        double high=0;
        while( e-- ){
            scanf("%d %d %lf %lf",&a,&b,&tt,&dd);
            edge[a].push_back( b );
            cost[a].push_back( dd );
            deg[a].push_back(tt);

            edge[b].push_back( a );
            cost[b].push_back( dd );
            deg[b].push_back(tt);

            if ( tt>high ){
                high=tt;
            }
        }



        double low=0;
        high+=1;
        double ansdeg=0;
        while( low<high ){
            double mid=(low+high)/2;
            //printf("%lf\n",mid);
            if ( dijkstra(s,f,mid) ){
                high=mid-EPS;
                ansdeg=mid;
                memcpy(save,prvnode,sizeof(save));
            }else{
                low=mid+EPS;
                //printf("fail\n");
            }
        }
        int to=f,frm;
        printf("%d",to);
        while (save[to]!=-1){
            frm=save[to];
            printf(" %d",frm);
            to=frm;
        }
        printf("\n");

        printf("%.1lf %.1lf\n",ansdis,ansdeg);
    }

    return 0;
}

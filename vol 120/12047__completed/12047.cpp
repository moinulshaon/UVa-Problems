#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define SIZE 10010
const int INF=(1<<29);

vector <int> edge[SIZE], cost[SIZE],redge[SIZE],rcost[SIZE];
int total;

struct node
{
    int val,city;
    bool operator < (const node & p)const{
        return val>p.val;
    }
};

int forwardd[SIZE];
int backwardd[SIZE];


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
        forwardd[ temp.city ]=temp.val;

        for (int i=0;i<edge[temp.city].size();++i){
            u.val=cost[temp.city][i]+temp.val;
            u.city=edge[temp.city][i];
            q.push(u);
        }
    }
}


void dijkstra2(int s,int f){
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
        backwardd[ temp.city ]=temp.val;

        for (int i=0;i<redge[temp.city].size();++i){
            u.val=rcost[temp.city][i]+temp.val;
            u.city=redge[temp.city][i];
            q.push(u);
        }
    }
}

struct ttt{
    int start,end,w;
}hhh[100100];



void makeinf(int arr[]){
    for (int i=1;i<=total;++i){
        arr[i]=INF;
    }
}

bool cmp( const ttt&a,const ttt&b ){
    return a.w>b.w;
}

template<class T>
    inline T fastIn() {
    register char c=0;
    register T a=0;
    bool neg=false;
    while ( c<33 ) c=getchar();
    while ( c>33 ) {
        if ( c=='-' ) {
            neg=true;
        } else {
            a= ( a*10 ) + ( c-'0' );
        }
        c=getchar();
    }
    return neg?-a:a;
}


int main()
{

    //freopen("in.txt","r",stdin);
    int kase;
    kase=fastIn<int>();
    for (int m=1;kase--;++m){
        int s,f,taka,ee;
        total=fastIn<int>();
        ee=fastIn<int>();
        s=fastIn<int>();
        f=fastIn<int>();
        taka=fastIn<int>();

        for (int i=1;i<=total;++i){
            edge[i].clear();
            cost[i].clear();

            rcost[i].clear();
            redge[i].clear();
        }

        int x,y,w,cnt=0;
        while(ee--){
            x=fastIn<int>();
            y=fastIn<int>();
            w=fastIn<int>();
            edge[x].push_back(y);
            cost[x].push_back(w);

            redge[y].push_back( x );
            rcost[y].push_back( w );

            hhh[cnt].start=x;
            hhh[cnt].end=y;
            hhh[cnt].w=w;
            cnt++;
        }
        makeinf(forwardd);
        dijkstra(s,f);
        makeinf(backwardd);
        dijkstra2(f,s);

        sort(hhh,hhh+cnt,cmp);
        int ans= -1;
        for (int i=0;i<cnt;++i){
            if ( forwardd[ hhh[i].start ]+hhh[i].w+backwardd[ hhh[i].end ]<=taka ){
                ans=hhh[i].w;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

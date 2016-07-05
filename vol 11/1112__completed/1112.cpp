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
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 110

vector <int> edge[SIZE], cost[SIZE];
int total;

struct node
{
    int val,city;
    bool operator < (const node & p)const{return val>p.val;}
};

bool vis[SIZE];
int dis[SIZE];
void dijkstra(int s,int lim )
{
    CLR(vis);
    memset( dis,63,sizeof(dis) );

    node place,temp,u;
    place.val=0;
    place.city=s;


    priority_queue<node> q;

    q.push(place);


    while (!q.empty())
    {
        temp=q.top();q.pop();

        if (vis[temp.city])
            continue;
        vis[temp.city]=true;
        dis[ temp.city ]=temp.val;

        if ( temp.val>lim )break;

        for (int i=0;i<edge[temp.city].size();++i)
        {
            u.val=cost[temp.city][i]+temp.val;
            u.city=edge[temp.city][i];

            if ( !vis[ u.city ] )
                q.push(u);
        }
    }
}

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){
        int node,cell,tt,ee;
        scanf("%d %d %d",&node,&cell,&tt);

        for (int i=0;i<=node;++i){
            edge[i].clear();
            cost[i].clear();
        }

        scanf("%d",&ee);

        int a,b,w;
        while ( ee-- ){
            scanf("%d %d %d",&a,&b,&w);
            edge[ b ].PB(a);
            cost[ b ].PB(w);
        }

        dijkstra(  cell ,tt );

        int ans=0;
        for (int i=1;i<=node;++i){
            if ( dis[i]<=tt ){
                ++ans;
            }
        }
        printf("%d\n",ans);

        if ( kase )printf("\n");

    }


    return 0;
}

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

int main(){

    //freopen("in.txt","r",stdin);
    int ee,a,b,w;
    while (true){

        scanf("%d %d",&total,&ee);
        if ( !total )return 0;

        for (int i=0;i<=total;++i){
            edge[i].clear();
            cost[i].clear();
        }

        while( ee-- ){
            scanf("%d %d %d",&a,&b,&w);
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

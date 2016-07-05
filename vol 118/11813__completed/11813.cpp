#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

#define SIZE 100010

vector <int> edge[SIZE], cost[SIZE];
int total;

struct node{
    int val,city;
    bool operator < (const node & p)const{return val>p.val;}
};
int dis[11][11],store;
map<int,int> mp;

void dijkstra(int s){

    bool vis[SIZE]={false};

    node place,temp,u;
    place.val=0;
    place.city=s;
    dis[s][s]=0;


    priority_queue<node> q;

    q.push(place);


    while (!q.empty()){
        temp=q.top();q.pop();


        if (vis[temp.city])
            continue;
        vis[temp.city]=true;

        if ( mp.find( temp.city )!=mp.end() ){
            dis[ mp[s] ][ mp[temp.city] ]=temp.val;
        }

        for (int i=0;i<edge[temp.city].size();++i){
            u.val=cost[temp.city][i]+temp.val;
            u.city=edge[temp.city][i];
            if ( !vis[u.city] )
                q.push(u);
        }
    }
}
int set(int N,int pos){
    return N=N | (1<<pos);
}
int reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool check(int N,int pos){
    return (bool)(N & (1<<pos));
}

int dp[(1<<12)+5][12];
int func(int state,int now){
    //printf("%d %d\n",state,now);
    if ( state == (1<< (store+1) )-1 ){
        return dis[now][0];
    }
    if ( dp[state][now]!= -1 )return dp[state][now];

    int sum=(1<<29);
    for (int i=1;i<=store;++i){
        if ( check(state,i)==0 ){
            sum=min(sum, dis[now][i]+func( set(state,now),i ) );
        }
    }
    return dp[state][now]=sum;
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
int main(){

    freopen("in.txt","r",stdin);

    int kase,ee;
    kase=fastIn<int>();

    for (int kk=1;kase--;++kk){

        total=fastIn<int>();
        ee=fastIn<int>();

        for (int i=0;i<=total;++i){
            edge[i].clear();
            cost[i].clear();
        }

        int temp,temp2,temp3;
        while(ee--){
            temp=fastIn<int>();
            temp2=fastIn<int>();
            temp3=fastIn<int>();
            edge[temp].push_back(temp2);
            cost[temp].push_back(temp3);

            edge[temp2].push_back(temp);
            cost[temp2].push_back(temp3);
        }
        mp.clear();
        scanf("%d",&store);
        mp[0]=0;
        for (int i=1;i<=store;++i){
            scanf("%d",&temp);
            mp[temp]=i;
        }
        for (map<int,int>::iterator it=mp.begin();it!=mp.end();++it){
            dijkstra(it->first);
        }


        int ans=(1<<29);
        memset(dp,-1,sizeof(dp));
        for (int i=1;i<=store;++i){
            ans=min( ans, dis[0][i] + func( set(0,0),i ) );
        }
        printf("%d\n",ans);
    }

    return 0;
}

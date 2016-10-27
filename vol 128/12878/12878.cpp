#include<bits/stdc++.h>
using namespace std;


#define SIZE 10010

typedef pair<int,int> pint;
#define X first
#define Y second


vector<pint> edge[SIZE];
int dist[SIZE];

const int inf = (1<<29);

int n;

struct node{
    int num,cost;
    bool operator<(const node&v)const{
        return cost>v.cost;
    }
};

void dijkstra( int s ){

    for (int i=0;i<n;++i){
        dist[i] = inf;
    }

    priority_queue<node> q;
    q.push( {s,0} );

    while ( !q.empty() ){

        node f = q.top();q.pop();
        if ( dist[f.num] <= f.cost )continue;
        dist[f.num] = f.cost;

        //cout<<f.num<<" "<<f.cost<<endl;

        for (auto&p:edge[f.num]){
            node tar = { p.X,f.cost+p.Y };
            if ( dist[tar.num] > tar.cost ){
                q.push( tar );
            }
        }

    }
}

bool vis[SIZE];

int track(int x){

    if ( vis[x] )return 0;

    int ret = 0;
    for (auto&p:edge[x]){
        if ( dist[p.X]+p.Y == dist[x] ){
            ret += p.Y;
            ret += track( p.X );
        }
    }
    vis[x] = true;
    return ret;
}

int main(){

    //freopen("in.txt","r",stdin);

    int m;
    while ( scanf("%d %d",&n,&m) == 2 ){

        for (int i=0;i<n;++i)edge[i].clear();

        int u,v,w;
        while ( m-- ){
            scanf("%d %d %d",&u,&v,&w);
            edge[u].push_back( {v,w} );
            edge[v].push_back( {u,w} );
        }

        dijkstra( 0 );

        for (int i=0;i<n;++i)vis[i]=false;

        printf("%d\n",2*track(n-1) );

    }

    return 0;
}

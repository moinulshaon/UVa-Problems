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

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 100100

vector <int> edge[SIZE], cost[SIZE];
int n;

struct node{
    int val,city,prv;
    bool operator < (const node & p)const{return val>p.val;}
};

int inf = (1<<30);
int dist[SIZE];

int parent[SIZE][20];
int depth[SIZE];

int lca(int x,int y){
    if ( depth[x]>depth[y] ){
        swap(x,y);
    }
    for (int i=0;i<20;++i){
        if( ( ( depth[y]-depth[x] )>>i )&1){
            y=parent[y][i];
        }
    }
    if ( x==y ){
        return x;
    }
    for(int i=19;i>=0;--i)
        if(parent[x][i]!=parent[y][i] )
            x=parent[x][i],y=parent[y][i];
    return parent[x][0];
}

int save[SIZE];

void dijkstra( int s ){

    for (int i=0;i<=n;++i){
        dist[i]=inf;
    }

    node place,temp,u;
    place.val= 0;
    place.city=s;
    place.prv =0;


    priority_queue<node> q;

    q.push(place);


    while (!q.empty()){
        temp=q.top();q.pop();

        if (dist[temp.city]<temp.val){
            continue;
        }else if ( dist[temp.city] == temp.val ){

            save[ temp.city ] = lca( save[temp.city],temp.prv );

            parent[temp.city][0]=save[ temp.city ];
            depth[temp.city] = depth[ save[ temp.city ] ]+1;

            for (int i=1;i<20;++i)
                parent[temp.city][i]=parent[ parent[temp.city][i-1] ][i-1];

            continue;
        }

        dist[temp.city] = temp.val;

        save[temp.city] = temp.prv;

        parent[temp.city][0]=temp.prv;
        depth[temp.city] = depth[ temp.prv ]+1;


        for (int i=1;i<20;++i)
            parent[temp.city][i]=parent[ parent[temp.city][i-1] ][i-1];

        for (int i=0;i<edge[temp.city].size();++i){
            u.val=cost[temp.city][i]+temp.val;
            u.city=edge[temp.city][i];
            u.prv = temp.city;

            if ( dist[u.city]>= u.val )
                q.push(u);
        }
    }
}

int sz[SIZE];

vector<int> out[SIZE];

void dfs(int x,int p){

    sz[x] = 1;

    for (int i=0;i<out[x].size();++i){
        int y=out[x][i];
        if ( y!=p ){
            dfs(y,x);
            sz[x] += sz[y];
        }
    }

}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int m;
        scanf("%d %d",&n,&m);

        for (int i=0;i<=n;++i){
            edge[i].clear();
            cost[i].clear();
            out[i].clear();
            save[i] = 0;
        }

        int u,v,w;
        while ( m-- ){
            scanf("%d %d %d",&u,&v,&w);
            u++,v++;

            edge[u].PB( v );
            cost[u].PB( w );

            edge[v].PB( u );
            cost[v].PB( w );

        }



        dijkstra(1);

        for (int i=1;i<=n;++i){
            //cout<<"out "<<save[i]<<" "<<i<<endl;
            out[ save[i] ].PB( i );
        }

        dfs(1,0);


        printf("Case %d:\n",kk);

        int qq,tmp;
        scanf("%d",&qq);
        for (int sss=1; qq--;++sss ){
            printf("Query %d:\n",sss);
            scanf("%d",&tmp);

            vector<int> vec;

            while ( tmp-- ){
                scanf("%d",&u);
                u++;
                if ( dist[u] < inf ){
                    vec.PB( u );
                }

            }
            if ( vec.empty() ){
                printf("Will not sabotage.\n");
                continue;
            }
            int dd= vec[0];
            for (int i=1;i<vec.size();++i){
                //cout<<dd<<" "<<vec[i]<<" "<<lca(dd,vec[i])<<endl;
                dd= lca( dd,vec[i] );
            }
            //cout<<dd<<endl;
            printf("%d possible way(s) to sabotage the contest.\nTeams from at least %d cities will be late.\n",depth[dd],sz[dd]);

        }

    }

    return 0;
}

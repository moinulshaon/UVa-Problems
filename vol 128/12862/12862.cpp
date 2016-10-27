#include<bits/stdc++.h>
using namespace std;

#define SIZE 100100
#define X first
#define Y second
typedef pair<int,int> pint;
typedef long long LL;

vector<pint> out[SIZE];

bool land[SIZE];
int n;

int sub[SIZE];
int cost[SIZE];
int parent[SIZE];
void dfs(int x,int cum,int p){
    sub[x] = land[x];
    cost[x] = cum;
    parent[x] = p;
    for (auto&p:out[x]){
        dfs(p.X,cum+p.Y,x);
        sub[x] += sub[p.X];
    }
}

LL calc(int x,int cum){
    if ( sub[x] == 0 )return 0;
    LL ret = cum;
    for (auto&p:out[x]){
        ret = max( ret, calc(p.X,cum+p.Y) );
    }
    return ret;
}

int main(){

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int f;
    while ( scanf("%d %d",&n,&f)==2 ){

        for (int i=1;i<=n;++i){
            out[i].clear();
            land[i]=false;
        }

        int u,v,w;
        for (int i=1;i<n;++i){
            scanf("%d %d %d",&u,&v,&w);
            out[u].push_back( {v,w} );
        }

        while (f--){
            scanf("%d",&u);
            land[u]=true;
        }
        dfs(1,0,0);

        LL ans = 0;
        for (int i=1;i<=n;++i){
            if ( sub[i] > 0 ){
                ans += LL( cost[i] )-cost[ parent[i] ];
            }
        }
        //cout<<ans<<" x "<<endl;

        printf("%lld\n",ans-calc(1,0));
    }

    return 0;
}

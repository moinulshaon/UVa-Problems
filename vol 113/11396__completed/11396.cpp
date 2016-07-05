#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#define sz 400

using namespace std;

vector <int> outarrow[sz];
int vis[sz];

bool checkBipartite(int start){

    queue<int> q;
    memset(vis,-1,sizeof(vis));

    q.push(start);
    vis[start]=0;
    bool bipartitePossible=true;
    int cnt[2]={0};

    while (!q.empty() && bipartitePossible){
        int tmp=q.front();
        q.pop();
        cnt[ vis[tmp] ]++;

        for (int i=0;i<outarrow[tmp].size();++i){
            if ( vis[ outarrow[tmp][i] ]==-1 ){
                vis[ outarrow[tmp][i] ]=  !vis[tmp];
                q.push( outarrow[tmp][i] );
            }
            else if ( vis[ outarrow[tmp][i] ]==  vis[tmp]){
                bipartitePossible=false;
                break;
            }
        }
    }
    return bipartitePossible;
}

int main(){

    freopen("in.txt","r",stdin);

    int kase,n,tmp,a,b,tx,ty,e;

    while (true){
        scanf("%d",&n);
        if (!n)return 0;

        for (int i=0;i<=n;++i)
            outarrow[i].clear();

        while (true){
            scanf("%d %d",&a,&b);
            if (!a && !b)break;

            outarrow[a].push_back(b);
            outarrow[b].push_back(a);
        }


        if  ( checkBipartite(1) )
            printf("YES\n");
        else
            printf("NO\n");

    }
    return 0;
}

#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#define sz 800

using namespace std;

vector <int> outarrow[sz];
int parent[sz];
int vis[sz];

int find(int x)
{
    if (parent[x]==x)
        return x;
    else
        return parent[x]=find(parent[x]);
}

int checkBipartite(int start){

    queue<int> q;
    memset(vis,-1,sizeof(vis));

    q.push(start);
    vis[start]=0;
    bool bipartitePossible=true;
    int cnt[2]={0};

    while (!q.empty() && bipartitePossible){
        int tmp=q.front();
        q.pop();
        if (vis[tmp]==0)
            cnt[0]++;
        else if (vis[tmp]==1)
            cnt[1]++;

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
    if (bipartitePossible){
        if (cnt[0] && cnt[1])
            return max(cnt[0],cnt[1]);
        else if (cnt[0] && !cnt[1])
            return cnt[0];
        else
            return cnt[1];
    }
    else
        return 0;
}


int main(){

    freopen("in.txt","r",stdin);

    int kase,n,tmp,a,tx,ty;
    scanf("%d",&kase);
    while (kase--){
        scanf("%d",&n);

        for (int i=0;i<=n;++i)
            outarrow[i].clear();
        for (int i=0;i<=n;++i)
            parent[i]=i;
        int mx=n;
        for (int i=1;i<=n;++i){
            scanf("%d",&tmp);

            while (tmp--){
                scanf("%d",&a);
                if (a>mx)
                    mx=a;
                outarrow[i].push_back(a);
                outarrow[a].push_back(i);

                tx=find(a);
                ty=find(i);

                if (tx!=ty)
                {
                    parent[ty]=parent[tx];
                }
            }
        }
        n=mx;
        int result=0;
        for (int i=1;i<=n;++i)
        {
            if (find(i)==i){
                result+=checkBipartite(i);
            }
        }
        printf("%d\n",result);
    }
    return 0;
}

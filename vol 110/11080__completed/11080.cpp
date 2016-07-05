#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#define sz 300

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
    if (bipartitePossible){
        if (cnt[0] && cnt[1])
            return min(cnt[0],cnt[1]);
        else if (cnt[0] && !cnt[1])
            return cnt[0];
        else
            return cnt[1];
    }
    else
        return -1;
}


int main(){

    freopen("in.txt","r",stdin);

    int kase,n,tmp,a,b,tx,ty,e;
    scanf("%d",&kase);
    while (kase--){
        scanf("%d %d",&n,&e);

        for (int i=0;i<n;++i)
            outarrow[i].clear();
        for (int i=0;i<n;++i)
            parent[i]=i;
        for (int i=0;i<e;++i){
            scanf("%d %d",&a,&b);

            outarrow[a].push_back(b);
            outarrow[b].push_back(a);

            tx=find(a);
            ty=find(b);

            if (tx!=ty){
                parent[ty]=parent[tx];
            }
        }

        int result=0;
        for (int i=0;i<n;++i)
        {
            if (find(i)==i){
                tmp=checkBipartite(i);
                if (tmp==-1){
                    result=-1;
                    break;
                }
                result+=tmp;
            }
        }
        printf("%d\n",result);
    }
    return 0;
}

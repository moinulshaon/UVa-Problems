#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define sz 11000

vector<int> outarrow[sz];

int taka[sz];
bool vis[sz];

int BFS(int n){

    queue<int> q;

    q.push(n);
    vis[n]=true;
    int sum=0;

    while (!q.empty()){
        int tmp=q.front();
        q.pop();

        sum+=taka[tmp];

        for (int i=0;i<outarrow[tmp].size();++i){
            if (!vis[ outarrow[tmp][i] ]){
                q.push(outarrow[tmp][i]);
                vis[ outarrow[tmp][i] ]=true;
            }
        }
    }
    return sum;

}


int main()
{
    freopen("in.txt","r",stdin);

    int kase,total,m,a,b;
    scanf("%d",&kase);

    while(kase--)
    {
        scanf("%d %d",&total,&m);

        for (int i=0;i<total;++i){
            scanf("%d",&taka[i]);
            outarrow[i].clear();
        }

        memset(vis,0,sizeof(vis));

        while (m--){
            scanf("%d %d",&a,&b);

            outarrow[a].push_back(b);
            outarrow[b].push_back(a);
        }

        bool pos=true;
        for (int i=0;i<total;++i)
        {
            if (!vis[i]){

                if (BFS(i)){
                    pos=false;
                    break;
                }
            }
        }
        if (pos){
            printf("POSSIBLE\n");
        }else{
            printf("IMPOSSIBLE\n");
        }

    }
    return 0;

}

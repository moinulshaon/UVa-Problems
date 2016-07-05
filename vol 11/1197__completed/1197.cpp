#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

#define sz 31000

vector<int>outarrow[sz];

bool vis[sz];

int BFS(){

    int cnt=0;

    queue<int>q;
    memset(vis,false,sizeof(vis));

    q.push(0);
    vis[0]=true;
    cnt++;

    while ( !q.empty() ){
        int tt=q.front();
        q.pop();

        for (int i=0;i<outarrow[tt].size();++i){
            if (!vis[ outarrow[tt][i] ]){
                q.push(outarrow[tt][i]);
                vis[outarrow[tt][i]]=true;
                cnt++;
            }
        }
    }
    return cnt;

}


int main(){

    int n,group,tmp,a,b;

    while (true){

        scanf("%d %d",&n,&group);

        if (!n && !group)return 0;

        for (int i=0;i<n;++i){
            outarrow[i].clear();
        }
        for (int i=0;i<group;++i){
            scanf("%d",&tmp);
            if (tmp){
                scanf("%d",&a);
                tmp--;
            }
            while (tmp--){
                scanf("%d",&b);

                outarrow[a].push_back(b);
                outarrow[b].push_back(a);
            }
        }

        printf("%d\n",BFS());

    }

}

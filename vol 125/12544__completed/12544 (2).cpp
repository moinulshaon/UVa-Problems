#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define SIZE 505
const int INF = (1<<29);

vector<int> out[SIZE];
int dis[SIZE];
int par[SIZE];
int ans;

void bfs(int start){

    queue<int> q,sq;
    q.push(start);

    sq.push(0);
    dis[start]=0;

    while( !q.empty() ){

        int x=q.front();q.pop();
        int step=sq.front();sq.pop();

        for (int i=0;i<out[x].size();++i){
            int y=out[x][i];
            if ( dis[y] == -1 ){
                dis[y]=step+1;
                par[y]=x;
                q.push( y );
                sq.push( dis[y] );
            }else{
                if ( step+dis[y]+1 >=3 && par[y] != x && par[x]!=y ){
                    ans=min(ans,dis[x]+dis[y]+1);
                    //printf("%d %d %d %d\n",start,x,y,ans);
                }

            }
        }
    }
}


int main(){
    freopen("in.txt","r",stdin);
    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int v,e,a,b;

        scanf("%d %d",&v,&e);

        for (int i=0;i<v;++i){
            out[i].clear();
        }

        while(e--){
            scanf("%d %d",&a,&b);
            out[a].push_back(b);
            out[b].push_back(a);
        }

        ans=INF;

        for (int i=0;i<v;++i){
            memset(dis,-1,sizeof(dis));
            memset(par,-1,sizeof(par));
            bfs(i);
            //printf("%d\n",ans);
        }

        if ( ans==INF ){
            printf("Case %d: impossible\n",kk);
        }else{
            printf("Case %d: %d\n",kk,ans);
        }
    }
    return 0;
}

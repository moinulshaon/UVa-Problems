#include <cstdio>
#include <cstring>
#include <queue>
#define INF 100000000
#define sz 110

using namespace std;

int d[sz][sz];
bool vis[sz];
int prvnode[sz];
int nodes;

int dfs(int source,int destination)
{
    memset(vis,false,sizeof(vis));
    for (int i=0;i<nodes;++i)
        prvnode[i]=-1;

    queue <int> q;
    q.push(source);
    vis[source]=true;

    while (!vis[ destination ] && !q.empty() )
    {
        int tmp=q.front();
        q.pop();

        for (int i=0;i<nodes;++i)
        {
            if (!vis[i] && d[tmp][i]>0 )
            {
                vis[i]=true;
                prvnode[i]=tmp;
                q.push(i);
                if (i==destination)
                    break;
            }
        }
    }

    int to=destination,frm,path=INF;
    while (prvnode[to]!=-1)
    {
        frm=prvnode[to];
        path= ( path < d[frm][to] )?path:d[frm][to];
        to=frm;
    }
    if (path==INF)return 0;

    to=destination;
    while (prvnode[to]!=-1)
    {
        frm=prvnode[to];
        d[frm][to]-=path;
        d[to][frm]+=path;
        to=frm;
    }
    return path;

}

int maxflow(int s,int d)
{
    int path=0,perpath;

    while ( perpath=dfs(s,d) )
        path+=perpath;

    return path;
}


int main ()
{

    int cases=0;

    while ( scanf ("%d", &nodes) && nodes )
	{
        int source,destination,flow;

        for (int i=0;i<nodes;++i)
            for (int j=0;j<nodes;++j)
                d[i][j]=0;

        scanf("%d %d %d",&source,&destination,&flow);

        int a,b,dd;
        for (int i = 0; i < flow; i++ )
        {
            scanf("%d %d %d",&a,&b,&dd);
            d[a-1][b-1]+=dd;
            d[b-1][a-1]+=dd;
        }

        printf("Network %d\n",++cases);
        printf("The bandwidth is %d.\n\n",maxflow(source-1,destination-1) );

    }

    return 0;

}

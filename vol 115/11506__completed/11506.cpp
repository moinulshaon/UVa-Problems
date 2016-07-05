#include <cstdio>
#include <cstring>
#include <queue>
#define INF 2147483647
#define sz 120
#define in(p) (2*(p))
#define out(p) (2*(p)+1)

using namespace std;

int d[sz][sz];
bool vis[sz];
int prvnode[sz];
int nodes;

int bfs(int source,int destination)
{
    memset(vis,false,sizeof(vis));
    int tt=2*nodes;
    for (int i=0;i<tt;++i)
        prvnode[i]=-1;

    queue <int> q;
    q.push(source);
    vis[source]=true;

    while (!vis[ destination ] && !q.empty() )
    {
        int tmp=q.front();
        q.pop();

        for (int i=source;i<destination+1;++i)
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

        if (d[frm][to] < path )
        {
            path=d[frm][to];
        }
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

int maxedges(int s,int d)
{
    int path=0,perpath;

    while ( perpath=bfs(s,d) )
    {
        path+=perpath;
    }

    return path;
}
int main ()
{

    freopen("in.txt","r",stdin);

    int p,q,k,edges;
    while(true)
    {
        scanf("%d %d",&nodes,&edges);

        if(!nodes && !edges) return 0;

        int p=2*nodes;
        for (int i=0;i<p;++i)
            for (int j=0;j<p;++j)
                d[i][j]=0;

        for (int i=0;i<nodes-2;++i)
        {
            scanf("%d %d",&p,&q);
            d[in(p-1)][out(p-1)]=q;
        }
        while (edges--)
        {
            scanf("%d %d %d",&p,&q,&k);
            p--;
            q--;
            d[out(p)][in(q)]=d[out(q)][in(p)]=k;
        }

        printf("%d\n",maxedges(out(0),in(nodes-1)) );
    }

    return 0;

}

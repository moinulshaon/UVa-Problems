#include <cstdio>
#include <cstring>
#include <queue>
#define INF 2147483647
#define sz 250
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
    int tt=2*nodes+3;
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
        //printf("%d\t",to);
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

int maxflow(int s,int d)
{
    int path=0,perpath;

    while ( perpath=bfs(s,d) )
    {
        //printf("%d\n",perpath);
        path+=perpath;
    }

    return path;
}
int main ()
{

    freopen("in.txt","r",stdin);

    int p,q,k,edges;
    while(scanf("%d",&nodes)==1)
    {
        p=2*nodes+3;
        for (int i=0;i<p;++i)
            for (int j=0;j<p;++j)
                d[i][j]=0;

        for (int i=1;i<=nodes;++i)
        {
            scanf("%d",&p);
            d[ in(i) ][ out(i) ]=p;
        }
        scanf("%d",&edges);
        while (edges--)
        {
            scanf("%d %d %d",&p,&q,&k);
            d[out(p)][in(q)]=k;
        }
        scanf("%d %d",&p,&q);
        while (p--)
        {
            scanf("%d",&edges);
            d[out(0)][in(edges)]=INF;
        }
        while (q--)
        {
            scanf("%d",&edges);
            d[out(edges)][in(nodes+1)]=INF;
        }

        printf("%d\n",maxflow(out(0),in(nodes+1)) );
    }

    return 0;

}

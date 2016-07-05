#include <cstdio>
#include <cstring>
#include <queue>
#define INF 2147483647
#define sz 60

using namespace std;

int d[sz][sz];
bool vis[sz];
int prvnode[sz];
int nodes;
bool valid[sz][sz];
bool recursion[sz];

int bfs(int source,int destination)
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
        if (d[frm][to] < path )
            path=d[frm][to];
        to=frm;
    }
    if (path==INF)return 0;

    to=destination;
    while (prvnode[to]!=-1)
    {
        frm=prvnode[to];
        d[frm][to]-=path;
        //d[to][frm]+=path;
        to=frm;
    }
    return path;

}

int maxflow(int s,int d)
{
    int path=0,perpath;

    while ( perpath=bfs(s,d) )
        path+=perpath;

    return path;
}

void dfs(int n)
{
    recursion[n]=true;
    for (int i=0;i<nodes;++i)
    {
        if (valid[n][i] && d[n][i]>0  && !recursion[i])
            dfs(i);
        else if (d[n][i]==0 && valid[n][i])
            printf("%d %d\n",n+1,i+1);
    }
}


int main ()
{

    freopen("in.txt","r",stdin);

    int flow;

    while ( scanf ("%d %d", &nodes,&flow) && nodes && flow )
	{
        int source,destination;

        for (int i=0;i<nodes;++i)
            for (int j=0;j<nodes;++j)
            {
                d[i][j]=0;
                valid[i][j]=false;
            }

        source=1;
        destination=2;

        int a,b,dd;
        for (int i = 0; i < flow; i++ )
        {
            scanf("%d %d %d",&a,&b,&dd);
            d[a-1][b-1]+=dd;
            d[b-1][a-1]+=dd;
            valid[a-1][b-1]=valid[b-1][a-1]=true;
        }
        maxflow(source-1,destination-1);

        memset(recursion,false,sizeof(recursion));
        dfs(source-1);
        printf("\n");

    }

    return 0;

}

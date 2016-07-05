#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define INF 2147483647
#define sz 5100
#define in(p) (2*(p))
#define out(p) (2*(p)+1)

using namespace std;

bool vis[sz];
bool d[sz][sz];
int prvnode[sz];
int nodes;
vector<int> adj[sz];

bool bfs(int source,int destination)
{
    memset(vis,false,sizeof(vis));

    for (int i=0;i<sz;++i)
        prvnode[i]=-1;

    queue <int> q;
    q.push(source);
    vis[source]=true;

    while (!vis[ destination ] && !q.empty() )
    {
        int tmp=q.front();
        q.pop();


        for (int i=0;i<adj[tmp].size();++i)
        {
            if (!vis[  adj[tmp][i] ] && d[ tmp ][ adj[tmp][i] ])
            {
                vis[ adj[tmp][i] ]=true;
                prvnode[ adj[tmp][i] ]=tmp;
                q.push( adj[tmp][i] );
                if (adj[tmp][i] ==destination){
                    break;
                }
            }
        }
    }

    int to=destination,frm;

    if (!vis[destination])return false;

    while (prvnode[to]!=-1)
    {
        frm=prvnode[to];
        d[frm][to]=false;
        to=frm;
    }
    return true;

}

int maxedges(int s,int d)
{
    int path=0;

    while ( bfs(s,d) ){
        ++path;
    }

    return path;
}


int main ()
{

    //freopen("in.txt","r",stdin);

    int p,q,k,edges,kase,a,b,bank;

    scanf("%d",&kase);

    while(kase--)
    {
        scanf("%d %d %d",&p,&q,&bank);

        int nodes=p*q;
        for (int i=0;i<=out(nodes+1);++i){
            adj[i].clear();
        }
        memset(d,false,sizeof(d));

        for (int i=1;i<=nodes;++i){
            if ( i%q!=1){
                d[ out(i) ][in(i-1)]=true;
                adj[out(i)].push_back(in(i-1));
            }

            if ( i%q!=0){
                d[ out(i) ][in(i+1)]=true;
                adj[out(i)].push_back( in(i+1) );
            }

            if (i+q<=nodes){
                d[ out(i) ][in(i+q)]=true;
                adj[out(i)].push_back( in(i+q) );
            }

            if (i-q>0){
                d[ out(i) ][in(i-q)]=true;
                adj[out(i)].push_back( in(i-q) );
            }

        }

        for (int i=1;i<=nodes;++i){
            if (i<=q || i%q==1 || i%q==0 || nodes-i<q){
                d[ out(0) ][ in(i) ] =true;
                adj[ out(0) ].push_back( in(i) );
            }

        }


        for (int i=0;i<bank;++i)
        {
            scanf("%d %d",&a,&b);
            adj[out( (a-1) *q+b )].push_back(in(nodes+1));
            d[out( (a-1) *q+b)][in(nodes+1)]=true;
        }
        for (int i=0;i<=nodes+1;++i){
            adj[in(i)].push_back( out(i) );
            d[in(i)][out(i)]=true;
        }

        if ( maxedges(out(0),in(nodes+1) ) ==bank ){
            printf("possible\n");
        }
        else{
            printf("not possible\n");
        }
    }

    return 0;

}

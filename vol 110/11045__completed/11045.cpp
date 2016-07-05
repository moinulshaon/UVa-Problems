#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <string>
#include <iostream>
#define INF 2147483647
#define sz 60

using namespace std;

int d[sz][sz];
bool vis[sz];
int prvnode[sz];
int nodes;

int bfs(int source,int destination)
{
    memset(vis,false,sizeof(vis));
    memset(prvnode,-1,sizeof(prvnode));

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
        d[to][frm]+=path;
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

int main ()
{

    freopen("in.txt","r",stdin);

    int flow,kase,person;

    scanf("%d",&kase);

    map<string,int> myp;

    myp["XXL"]=1;
    myp["XL"]=2;
    myp["L"]=3;
    myp["M"]=4;
    myp["S"]=5;
    myp["XS"]=6;
    //XXL, XL, L, M , S, or XS
    string str;
    while ( kase-- )
	{

	    scanf("%d %d",&flow,&person);

        flow/=6;

        int source,destination;

        memset(d,0,sizeof(d));

        source=0;
        destination=6+person+1;
        nodes=destination+1;

        for (int i=1;i<=6;++i){
            d[source][i]=flow;
        }
        for (int i=7;i<=person+6;++i){
            d[i][destination]=1;
        }

        for (int i=1;i<=person;++i){
            cin>>str;
            d[ myp[str] ][6+i]=1;
            cin>>str;
            d[ myp[str] ][6+i]=1;
        }
        //printf("%d\n",maxflow(source,destination));

        if ( maxflow(source,destination)== person)
            printf("YES\n");
        else
            printf("NO\n");

    }

    return 0;

}

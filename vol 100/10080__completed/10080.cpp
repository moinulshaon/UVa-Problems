#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
#include <vector>
#define INF 2147483647
#define sz 400

using namespace std;

int d[sz][sz];
bool vis[sz];
int prvnode[sz];
int nodes1,nodes2;

struct place{
    double x,y;
    vector<int> outarrow;
}arr[sz];


int cccc=0;
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

        for (int i=0;i<arr[tmp].outarrow.size();++i)
        {
            if (!vis[ arr[tmp].outarrow[i] ] && d[tmp][ arr[tmp].outarrow[i] ] > 0 )
            {
                vis[ arr[tmp].outarrow[i] ]=true;
                prvnode[ arr[tmp].outarrow[i] ]=tmp;
                q.push( arr[tmp].outarrow[i] );
                if ( arr[tmp].outarrow[i] ==destination)
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
    //printf("%d\n",++cccc);
    if (path==INF)return 0;

    to=destination;
    while (prvnode[to]!=-1)
    {
        frm=prvnode[to];
        d[frm][to]-=path;
        d[to][frm]+=path;
        arr[to].outarrow.push_back(frm);
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

    //freopen("in.txt","r",stdin);

    int s,v;

    while ( scanf ("%d %d %d %d", &nodes1,&nodes2,&s,&v)==4 )
	{
	    s*=v;
        int source,destination;

        memset(d,0,sizeof(d));

        source=nodes1;
        destination=200+nodes2;


        for (int i = 0; i <nodes1; i++ ){
            scanf("%lf %lf",&arr[i].x,&arr[i].y);
            arr[i].outarrow.clear();
        }
        for (int i =200; i <nodes2+200; i++ ){
            scanf("%lf %lf",&arr[i].x,&arr[i].y);
            arr[i].outarrow.clear();
        }
        for (int i=0;i<nodes1;++i){
            for (int j=200;j<nodes2+200;++j){
                if ( !(  ( arr[i].x-arr[j].x)*( arr[i].x-arr[j].x)+( arr[i].y-arr[j].y)*( arr[i].y-arr[j].y)  > s*s ) ){
                    arr[i].outarrow.push_back(j);

                    d[i][j]=1;
                }

            }
        }
        //printf("ashodn\n");

        arr[source].outarrow.clear();

        for (int i=0;i<nodes1;++i){
            arr[source].outarrow.push_back(i);
            d[source][i]=1;
        }

        arr[destination].outarrow.clear();
        for (int j=200;j<nodes2+200;++j){
            arr[j].outarrow.push_back(destination);
            d[j][destination]=1;
        }
        //cout<<d[201][destination]<<endl;
        printf("%d\n",nodes1-maxflow(source,destination) );


    }

    return 0;

}

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;


struct EDGES
{
    int start,finish,weight;
}edge[2010];

int d[505];


const int  INF = (1<<29);
int totalnode,totaledge;
int parent[505];
int todelete[505];

int extra[505][505];

int bellmanford( int source,int dest ){

    for (int i = 0; i < totalnode; ++i){
        d[i] = INF;
        parent[i] = -1;
    }

    d[source] = 0;

    for (int i = 0; i < totalnode - 1; ++i)
        for (int j = 0; j < totaledge; ++j)
            if (d[edge[j].start] + edge[j].weight < d[edge[j].finish]){
                d[edge[j].finish] = d[edge[j].start] + edge[j].weight;
                parent[ edge[j].finish ] = edge[j].start;
                todelete[ edge[j].finish ] = j;
            }

    int save = d[dest];

    int to=dest;
    while (parent[to]!=-1){
        int frm=parent[to];

        int num = todelete[ to ];

        EDGES tmp = edge[num];
        tmp.weight += extra[frm][to];

        edge[totaledge++] = tmp;

        swap( edge[num].start ,edge[num].finish );
        edge[num].weight = -edge[num].weight;



        to=frm;
    }


    for (int i = 0; i < totalnode; ++i){
        d[i] = INF;
        parent[i] = -1;
    }

    d[source] = 0;

    for (int i = 0; i < totalnode - 1; ++i)
        for (int j = 0; j < totaledge; ++j)
            if (d[edge[j].start] + edge[j].weight < d[edge[j].finish]){
                d[edge[j].finish] = d[edge[j].start] + edge[j].weight;
                parent[ edge[j].finish ] = edge[j].start;
                todelete[ edge[j].finish ] = j;
            }
    return save+d[dest];

}
int main(){

    int kk=1;
    while( scanf("%d %d",&totalnode,&totaledge) == 2 ){

        EDGES tmp;
        for (int i=0;i<totaledge;++i){
            scanf("%d %d %d",&tmp.start,&tmp.finish,&tmp.weight);
            tmp.start--;
            tmp.finish--;
            scanf("%d",&extra[tmp.start][tmp.finish]);
            edge[i] = tmp;
        }
        printf("Case %d: %d\n",kk++,bellmanford(0,totalnode-1));
    }


    return 0;
}

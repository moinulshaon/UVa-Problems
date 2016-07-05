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
#define INF 1000000000


using namespace std;



int totalnode,totaledge;
struct EDGES{
    int start,finish;
    int weight;
}edge[200*200+200];

int d[220];


void bellmanford(int source){
    for (int i = 1; i <= totalnode; ++i)
        d[i] = INF;

    d[source] = 0;

    for (int i = 0; i < totalnode - 1; ++i)
        for (int j = 0; j < totaledge; ++j)
            if (d[edge[j].start] + edge[j].weight < d[edge[j].finish])
                d[edge[j].finish] = d[edge[j].start] + edge[j].weight;


    vector<int>ss,ff;
    for (int j = 0; j < totaledge; ++j)
        if (d[edge[j].start] + edge[j].weight < d[edge[j].finish]){
            ss.push_back(edge[j].start);
            ff.push_back(edge[j].finish);
        }

    for (int i=0;i<ss.size();++i){
        d[ss[i] ]=-INF;
        d[ff[i] ]=-INF;
    }

    for (int i = 0; i < totalnode - 1; ++i)
        for (int j = 0; j < totaledge; ++j)
            if (d[edge[j].start] + edge[j].weight < d[edge[j].finish])
                d[edge[j].finish] = d[edge[j].start] + edge[j].weight;

}

int busy[220];
int main(){

    int a,q;

    for (int kk=1;scanf("%d",&totalnode)==1;++kk){


        for (int i=1;i<=totalnode;++i){
            scanf("%d",&busy[i]);
        }
        scanf("%d",&totaledge);
        for (int i=0;i<totaledge;++i){
            scanf("%d %d",&edge[i].start,&edge[i].finish);
            edge[i].weight=(busy[edge[i].finish]-busy[edge[i].start] )*(busy[edge[i].finish]-busy[edge[i].start] )*
            (busy[edge[i].finish]-busy[edge[i].start] );
        }

        bellmanford(1);
        scanf("%d",&q);
        printf("Set #%d\n",kk);
        while (q--){
            scanf("%d",&a);
            //printf("%d\n",d[a]);
            if (d[a]>100000000 || d[a]< 3)
                printf("?\n");
            else{
                printf("%d\n",d[a]);
            }
        }
    }
    return 0;
}

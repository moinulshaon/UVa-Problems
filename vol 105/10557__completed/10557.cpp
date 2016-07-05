#include <cstdio>
#define INF 1000000


using namespace std;

int totalnode,totaledge;
struct EDGES
{
    int start,finish,weight;
}edge[201000];

int d[110];


void bellmanford(int source)
{
        for (int i = 0; i < totalnode; ++i)
            d[i] = 0;

        d[source] = 100;
        for (int i = 0; i < totalnode - 1; ++i)
                for (int j = 0; j < totaledge; ++j)
                        if (d[edge[j].start]>0 && d[edge[j].start] + edge[j].weight > d[edge[j].finish])
                                d[edge[j].finish] = d[edge[j].start] + edge[j].weight;

        bool poscycle=false;

        for (int j = 0; j < totaledge; ++j)
            if (d[edge[j].start]>0 && d[edge[j].start] + edge[j].weight > d[edge[j].finish])
            {
                poscycle=true;
                d[edge[j].start]=d[edge[j].finish]=INF;
            }

        if (poscycle)
        {
            for (int i = 0; i < totalnode - 1; ++i)
                for (int j = 0; j < totaledge; ++j)
                        if (d[edge[j].start]>0 && d[edge[j].start] + edge[j].weight > d[edge[j].finish])
                                d[edge[j].finish] = d[edge[j].start] + edge[j].weight;
        }


        if (d[totalnode-1]>0)
            printf("winnable\n");
        else
            printf("hopeless\n");

}


int main()
{

    while (true)
    {
        scanf("%d",&totalnode);
        if (totalnode<0)
            return 0;
        totaledge=0;
        int temp,cnt,to;
        for (int i=0;i<totalnode;++i)
        {
            scanf("%d %d",&temp,&cnt);
            while (cnt--)
            {
                scanf("%d",&to);
                edge[totaledge].start=i;
                edge[totaledge].finish=to-1;
                edge[totaledge].weight=temp;
                ++totaledge;
            }

        }

        bellmanford(0);
    }
    return 0;
}

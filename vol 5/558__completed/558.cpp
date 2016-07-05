#include <cstdio>
#define INF 100000000


using namespace std;

int totalnode,totaledge;
struct EDGES
{
    int start,finish,weight;
}edge[2010];

int d[1010];


void bellmanford(int source)
{
        for (int i = 0; i < totalnode; ++i)
            d[i] = INF;

        d[source] = 0;

        for (int i = 0; i < totalnode - 1; ++i)
                for (int j = 0; j < totaledge; ++j)
                        if (d[edge[j].start] + edge[j].weight < d[edge[j].finish])
                                d[edge[j].finish] = d[edge[j].start] + edge[j].weight;

        bool negcycle=false;

        for (int j = 0; j < totaledge; ++j)
            if (d[edge[j].start] + edge[j].weight < d[edge[j].finish])
            {
                negcycle=true;
                j=totaledge;
            }
        if (negcycle)
            printf("possible\n");
        else
            printf("not possible\n");


}


int main()
{
    int test;

    scanf("%d",&test);

    while (test--)
    {
        scanf("%d %d",&totalnode,&totaledge);

        for (int i=0;i<totaledge;++i)
        {
            scanf("%d %d %d",&edge[i].start,&edge[i].finish,&edge[i].weight);
        }

        bellmanford(0);
    }
    return 0;
}

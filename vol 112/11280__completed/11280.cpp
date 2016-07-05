#include <cstdio>
#include <map>
#include <iostream>
#define INF 100000000


using namespace std;

int totalnode,totaledge;
struct EDGES
{
    int start,finish,weight;
}edge[1010];

int d[110];
int result[110];
map <string,int> ind;


void bellmanford(int source,int des,int s)
{
        for (int i = 0; i < 110; ++i)
        {
            d[i] = INF;
            result[i]=INF;
        }

        d[source] = result[source]= 0;


        for (int i = 0; i <= s; ++i)
        {
            for (int j = 0; j < totaledge; ++j)
            {
                    if (result[edge[j].start] + edge[j].weight < d[edge[j].finish])
                                d[edge[j].finish] = result[edge[j].start] + edge[j].weight;
            }

            for (int j=0;j<totalnode;++j)
            {
                result[j]=d[j];
            }

        }


        if (d[des]!=INF)
            printf("Total cost of flight(s) is $%d\n",d[des]);
        else
            printf("No satisfactory flights\n");
}


int main()
{

    freopen("in.txt","r",stdin);

    int test;

    scanf("%d",&test);

    for (int m=1;m<=test;++m)
    {

        ind.clear();

        if (m!=1)printf("\n");

        scanf("%d",&totalnode);

        string a,b;
        for (int i=0;i<totalnode;++i)
        {
            cin>>a;
            ind[a]=i;
        }

        scanf("%d",&totaledge);

        int n;
        for (int i=0;i<totaledge;++i)
        {
            cin>>a>>b>>n;
            edge[i].start=ind[a];
            edge[i].finish=ind[b];
            edge[i].weight=n;
        }

        printf("Scenario #%d\n",m);

        int step;
        scanf("%d",&n);
        while (n--)
        {
            scanf("%d",&step);
            bellmanford(ind["Calgary"],ind["Fredericton"],step);
        }
    }
    return 0;
}

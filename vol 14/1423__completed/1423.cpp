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
        for (int i = 0; i <=totalnode; ++i)
            d[i] = INF;

        d[source] = 0;

        for (int i = 0; i < totalnode - 1; ++i)
                for (int j = 0; j < totaledge; ++j)
                        if (d[edge[j].start] + edge[j].weight < d[edge[j].finish])
                                d[edge[j].finish] = d[edge[j].start] + edge[j].weight;

        for (int i=1;i<totalnode;++i){
            if ( i!=1 )printf(" ");
            printf("%d",d[i]-d[i-1]);
        }
        printf("\n");
}


int main()
{
    freopen("in.txt","r",stdin);
    int test;

    scanf("%d",&test);
    char line[100];
    while (test--)
    {
        scanf("%d %s",&totalnode,line);

        totaledge=0;
        for (int i=0;i<=totalnode;++i){
            edge[totaledge].start=totalnode+1;
            edge[totaledge].finish=i;
            edge[totaledge].weight= 0 ;
            totaledge++;
        }

        int tmp=0;
        for (int i=1;i<=totalnode;++i){
            for (int j=i;j<=totalnode;++j){

                if ( line[tmp]=='+' ){
                    edge[totaledge].start=j;
                    edge[totaledge].finish=i-1;
                    edge[totaledge].weight= -1 ;
                    totaledge++;

                }else if ( line[tmp]== '-' ){

                    edge[totaledge].start=i-1;
                    edge[totaledge].finish=j;
                    edge[totaledge].weight= -1 ;
                    totaledge++;
                }else{

                    edge[totaledge].start=j;
                    edge[totaledge].finish=i-1;
                    edge[totaledge].weight= 0 ;
                    totaledge++;

                    edge[totaledge].start=i-1;
                    edge[totaledge].finish=j;
                    edge[totaledge].weight= 0 ;
                    totaledge++;
                }
                tmp++;
            }
        }

        totalnode++;
        bellmanford(totalnode);
    }
    return 0;
}

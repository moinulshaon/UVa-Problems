#include <cstdio>
#include <cstring>

using namespace std;

int parent[30];
int ans;
int node,edges;



void ini(int k)
{
    char line[5];
    int tx,ty;

    for (int i=0;i<=k;++i)
        parent[i]=-1;

    for (int i=0;i<edges;++i)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        //printf("%d %d\n",a,b);


        if (parent[a]!=parent[b])
        {
            //parent[tx]+=parent[ty];
            parent[ty]=-1;
            parent[tx]=-2;
        }
    }
}


void check(int n)
{
    ans=0;
    bool visparent[30]={false};
    for (int i=0;i<=n;++i)
    {
        if (!visparent[i])
        {
            ++ans;
            //printf("%d %d\n",i,ans);

            for (int j=i;j<=n;++j)
                if (find(j)==find(i))
                {
                    visparent[j]=true;
                    //printf("%d\n",j);
                }
        }
    }
    //printf("%d\n",ans);
}



int main()
{
    int test;

    //freopen("input.txt","r",stdin);

    scanf("%d",&test);
    getchar();
    getchar();

    while(test--)
    {
        scanf("%d %d",&node,&edges);
        getchar();
        ini(node);
        check(node);
        printf("%d\n",ans);
        if (test)printf("\n");
    }
    return 0;

}

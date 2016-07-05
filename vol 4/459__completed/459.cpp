#include <cstdio>
#include <cstring>

using namespace std;

int parent[30];
int ans;


int find(int x)
{
    if (parent[x]==x)
        return x;
    else
        return parent[x]=find(parent[x]);
}


void ini(int k)
{
    char line[5];
    int tx,ty;

    for (int i=0;i<=k;++i)
        parent[i]=i;

    while(gets(line) && strlen(line))
    {
        int a=line[0]-'A',b=line[1]-'A';
        //printf("%d %d\n",a,b);

        tx=find(a);
        ty=find(b);

        if (tx!=ty)
        {
            //parent[tx]+=parent[ty];
            parent[ty]=parent[tx];
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

    freopen("input.txt","r",stdin);

    scanf("%d",&test);
    getchar();
    getchar();

    char c;
    while(test--)
    {
        c=getchar();
        getchar();
        ini(c-'A');
        check(c-'A');
        printf("%d\n",ans);
        if (test)printf("\n");
    }
    return 0;

}

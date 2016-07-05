#include <cstdio>
#include <cstring>

using namespace std;

bool tree[2100000];
int totalNode;
int save[21][524289];


int f2(int k)
{
    if (k>totalNode)return k/2;
    if (tree[k])
    {
        tree[k]=false;
        return f2(2*k+1);
    }
    if (!tree[k])
    {
        tree[k]=true;
        return f2(2*k);
    }
}

int main()
{
    freopen("in.txt","r",stdin);


    for (int i=2;i<21;++i)
    {
        memset(tree,false,sizeof(tree));
        totalNode=(1<<i)-1;
        int tmp=totalNode+1;
        if (tmp>524289)
            tmp=524289;
        for (int j=1;j<tmp ;++j)
        {
            save[i][j]=f2(1);
        }
    }

    int test;
    while (true)
    {
        scanf("%d",&test);
        if (test<0)return 0;

        int depth,ball;
        while (test--)
        {
            scanf("%d %d",&depth,&ball);
            printf( "%d\n",save[depth][ball] );
        }
    }
}

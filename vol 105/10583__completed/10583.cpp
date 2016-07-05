#include <cstdio>


using namespace std;

int parent[50100];



int find(int x)
{
    if (parent[x]==x)
        return x;
    else
        return parent[x]=find(parent[x]);
}




int main()
{
    int m,n,tx,ty,a,b,ans,total;

    freopen("input.txt","r",stdin);

    for(n=1;;++n)
    {
        scanf("%d %d",&total,&m);

        if (!total && !m)return 0;

        for (int i=0;i<=total;++i)
            parent[i]=i;

        while (m--)
        {
            scanf("%d %d",&a,&b);
            tx=find(a);
            ty=find(b);

            if (tx!=ty)
            {
                parent[ty]=parent[tx];
            }
        }

        ans=0;
        for (int i=1;i<=total;++i)
        {
            if (find(i)==i)
                ++ans;
        }

        printf("Case %d: %d\n",n,ans);
    }
    return 0;

}

#include <cstdio>
#include <iostream>
#include <cstring>
#define size 100000

using namespace std;

int parent[size+5];


int find(int x)
{
    if (parent[x]==x)
        return x;
    else
        return parent[x]=find(parent[x]);
}




int main()
{
    int test;

    freopen("input.txt","r",stdin);

    scanf("%d",&test);
    getchar();
    getchar();

    int m,a,b,tx,ty,con,notcon;
    char c;
    while(test--)
    {
        con=notcon=0;

        scanf("%d",&m);
        getchar();
        for (int i=1;i<=m;++i)
                parent[i]=i;
        while (true)
        {
            c=getchar();
            if (c=='c')
            {
                getchar();
                scanf("%d",&a);
                getchar();
                scanf("%d",&b);
                getchar();
                tx=find(a);
                ty=find(b);

                if (tx!=ty)
                {
                    parent[ty]=parent[tx];
                }
            }
            else if (c=='q')
            {
                getchar();
                scanf("%d",&a);
                getchar();
                scanf("%d",&b);
                getchar();
                if (find(a)==find(b))++con;
                else ++notcon;
            }
            else
            {
                printf("%d,%d\n",con,notcon);
                break;
            }
        }

        if (test)printf("\n");
    }
    return 0;

}

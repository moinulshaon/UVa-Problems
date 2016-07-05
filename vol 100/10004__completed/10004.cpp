#include <cstdio>


int node[210];
bool mat[210][210];

int main()
{
    int total;

    freopen("input.txt","r",stdin);

    while (1)
    {
        scanf("%d",&total);

        if (!total)return 0;
        for (int i=0;i<total;++i)
            node[i]=100;

        for (int i=0;i<total;++i)
            for (int j=0;j<total;++j)
                mat[i][j]=false;
        int test;
        scanf("%d",&test);

        while(test--)
        {
            int a,b;
            scanf("%d %d",&a,&b);

            mat[a][b]=mat[b][a]=true;
        }

        bool flag=true;
        node[0]=0;
        for (int i=0;i<total;++i)
        {
            for (int j=i+1;j<total;++j)
            {
                if (mat[i][j])
                {
                    if (node[j]==100 )
                        node[j]=!node[i];
                    else if (node[j]==node[i])
                    {
                        flag=false;
                        i=j=total;
                    }

                }
            }
        }
        if (flag)
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
    }
}

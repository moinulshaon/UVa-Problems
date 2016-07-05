#include <cstdio>
#define INF 10000

using namespace std;

int arr[110][110];

int main()
{
    freopen("in.txt","r",stdin);

    int row,col;
    while (true)
    {
        scanf("%d %d",&row,&col);
        if (!row && !col)return 0;

        for (int i=1;i<=row;++i)
            for (int j=1;j<=col;++j)
            {
                scanf("%d",&arr[i][j]);
                if (arr[i][j])
                    arr[i][j]=-INF;
                else
                    arr[i][j]=1;
            }

        for (int i=1;i<=row;++i)
            for (int j=1;j<=col;++j)
            {
                arr[i][j]+=arr[i-1][j];
            }
        int mx=0;
        for (int i=1;i<=row;++i)
            for (int j=i;j<=row;++j)
            {
                int tmp=0;
                for (int k=1;k<=col;++k)
                {
                    tmp+=arr[j][k]-arr[i-1][k];
                    if (tmp<0)tmp=0;
                    else if (tmp>mx)mx=tmp;
                }
            }
        printf("%d\n",mx);
    }
}

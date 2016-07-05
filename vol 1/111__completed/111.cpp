#include <algorithm>
#include <cstdio>

using namespace std;

int mat[30][30];
int a[30],b[30];

int main()
{
    freopen("in.txt","r",stdin);
    int n,tmp;
    scanf("%d",&n);

    for (int i=1;i<=n;++i)
    {
        scanf("%d",&tmp);
        a[tmp]=i;
    }

    while (scanf("%d",&tmp)==1)
    {
        b[tmp]=1;
        for (int i=2;i<=n;++i)
        {
            scanf("%d",&tmp);
            b[tmp]=i;
        }

        for (int i=0;i<=n;++i)
            mat[i][0]=0;
        for (int i=0;i<=n;++i)
            mat[0][i]=0;

        for (int i=1;i<=n;++i)
        {
            for (int j=1;j<=n;++j)
            {
                if (b[i]==a[j])
                {
                    mat[i][j]=1+mat[i-1][j-1];
                }
                else
                    mat[i][j]=max( mat[i-1][j],mat[i][j-1] );
            }
        }

        printf("%d\n",mat[n][n]);
    }
    return 0;
}

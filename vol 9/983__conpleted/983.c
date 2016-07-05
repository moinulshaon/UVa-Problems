#include <stdio.h>
#define sz 1010

int arr[sz][sz];
int main()
{
    int n,m,i,j,k,tmp;
    char on=0;
    long long total;
    while (scanf("%d %d",&n,&m)==2)
    {
        total=0;
        if (on)
            printf("\n");
        else
            on=1;
        for (i=1;i<=n;++i)
            for (j=1;j<=n;++j)
            {
                scanf("%d",&arr[i][j]);
                arr[i][j]+=arr[i-1][j];
            }

        for (j=1;j<=n-m+1;++j)
        {
            for (i=1;i<=n-m+1;++i)
            {
                tmp=0;
                for (k=0;k<m;++k)
                    tmp+=arr[j+m-1][i+k]-arr[j-1][i+k];
                printf("%d\n",tmp);
                total+=tmp;
            }
        }
        printf("%lld\n",total);
    }
    return 0;

}

#include <stdio.h>

int arr[11000];

int main()
{
    int n,m,k,mx,tmp;
    while (1)
    {
        scanf("%d",&n);
        if (!n)return 0;

        for (k=0;k<n;++k)
            scanf("%d",&arr[k]);

        mx=0;

        tmp=0;
        for (k=0;k<n;++k)
        {
            tmp+=arr[k];
            if (tmp<0)
                tmp=0;
            else if (tmp>mx)
                mx=tmp;
        }
        if (mx)
            printf("The maximum winning streak is %d.\n",mx);
        else
            printf("Losing streak.\n",m);
    }
    return 0;
}

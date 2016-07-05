#include <stdio.h>

int main()
{
    int n,sum,a,i,nonnull;
    while (1)
    {
        scanf("%d",&n);
        if (!n)return 0;

        sum=0;
        nonnull=0;
        for (i=0;i<n;++i)
        {
            scanf("%d",&a);
            if (a)
                ++nonnull;
            sum+=a;
        }
        if  ( (sum & 1) ||  ( sum>nonnull*(nonnull-1) ) )
            printf("Not possible\n");
        else
            printf("Possible\n");
    }
}

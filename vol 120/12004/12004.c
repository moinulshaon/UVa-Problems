#include <stdio.h>

int main()
{
    int cases,m;
    long long in;
    scanf("%d",&cases);

    for (m=1;m<=cases;++m)
    {
        scanf("%lld",&in);
        in=in*(in-1);
        if (!(in&1))
        {
            in>>=1;
            if (!(in&1))
                printf("Case %d: %lld\n",m,in>>1);
            else
                printf("Case %d: %lld/2\n",m,in);
        }
        else
            printf("Case %d: %lld/4\n",m,in);
    }
    return 0;
}

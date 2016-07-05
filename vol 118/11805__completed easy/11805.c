#include <stdio.h>

int main()
{
    int test,i,n,k,pass,j;

    scanf("%d",&test);

    for (i=0;i<test;++i)
    {
        scanf("%d %d %d",&n,&k,&pass);

        for (j=0;j<pass;++j)
        {
            ++k;
            if (k>n)
                k%=n;
        }
        printf("Case %d: %d\n",i+1,k);
    }
    return (0);
}

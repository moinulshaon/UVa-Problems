#include <stdio.h>
#include <math.h>

int main()
{
    freopen("out.txt","w",stdout);
    int n;
    register int k;
    while (1)
    {
        scanf("%d",&n);
        if (!n)return 0;

        k=1;
        while (k<n)
            k<<=1;
        k=2*n-k;

        printf("%d\n",k);
    }

}

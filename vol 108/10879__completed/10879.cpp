#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int kase,n;
    scanf("%d",&kase);

    for (int m=1;kase--;++m)
    {
        scanf("%d",&n);

        printf("Case #%d: %d",m,n);
        int cnt=0;
        for (int i=2;cnt!=2;++i)
            if (n%i==0)
            {
                printf(" = %d * %d",i,n/i);
                ++cnt;
            }
        printf("\n");
    }
    return 0;
}

#include <cstdio>

int main()
{
    int kase,c,d;
    scanf("%d",&kase);

    for (int k=1;kase--;++k)
    {
        scanf("%d %d",&c,&d);

        double f=double(5*d)/9;

        printf("Case %d: %.2lf\n",k,c+f);

    }
    return 0;
}

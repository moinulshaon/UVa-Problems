#include <cstdio>

using namespace std;

int main()
{
    int test,a,b,c;
    scanf("%d",&test);

    for (int m=1;m<=test;++m)
    {
        scanf("%d %d %d",&a,&b,&c);

        if (a>20 || b>20 || c >20)
            printf("Case %d: bad\n",m);
        else
            printf("Case %d: good\n",m);
    }
    return 0;

}

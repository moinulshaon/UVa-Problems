#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int test,a,b;
    scanf("%d",&test);

    while (test--)
    {
        scanf("%d %d",&a,&b);
        if (!(b%a))
            printf("%d %d\n",a,b);
        else
            printf("-1\n");
    }
    return 0;
}

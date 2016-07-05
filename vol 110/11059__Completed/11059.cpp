#include <cstdio>

using namespace std;


long long arr[20];
int main()
{
    int cnt;
    for (int m=1;scanf("%d",&cnt)==1;++m)
    {
        for (int i=0;i<cnt;++i)
            scanf("%lld",&arr[i]);

        long long result=0;
        for (int i=0;i<cnt;++i)
        {
            long long tmp=1;
            for (int j=i;j<cnt;++j)
            {
                tmp*=arr[j];
                if (tmp>result)result=tmp;
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n",m,result);
    }
    return 0;

}

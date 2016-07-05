#include <cstdio>
#include <algorithm>

using namespace std;


int arr[1100];
int main()
{
    int n;
    bool printed;
    while (scanf("%d",&n)==1 && n)
    {
        for (int i=0;i<n;++i)
            scanf("%d",&arr[i]);

        printed=false;
        sort(arr,arr+n);
        for (int i=n-1;i>=0 && !printed;--i)
        {
            for (int j=0;j<n && !printed;++j)
            {
                if (i==j)continue;
                for (int k=0;k<n && !printed;++k)
                {
                    if (k==j || k==i)continue;
                    for (int p=0;p<n && !printed;++p)
                    {
                        if (p==k || p==j || p==i)continue;
                        if (arr[p]+arr[j]+arr[k]==arr[i])
                        {
                            printf("%d\n",arr[i]);
                            printed=true;
                        }
                    }
                }
            }
        }
        if (!printed)
            printf("no solution\n");
    }
    return 0;
}

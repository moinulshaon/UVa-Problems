#include <cstdio>
#include <algorithm>

using namespace std;

int arr1[500001];
int arr2[500001];

int main()
{
    int n;
    while (true)
    {
        scanf("%d",&n);
        if (!n)return 0;

        for (int i=0;i<n;++i)
            scanf("%d %d",&arr1[i],&arr2[i]);
        sort(arr1,arr1+n);
        sort(arr2,arr2+n);

        bool yes=true;
        for (int i=0;i<n;++i)
            if (arr1[i]!=arr2[i])
                yes=false;
        if (yes)
            printf("YES\n");
        else
            printf("NO\n");
    }

}

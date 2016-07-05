#include <cstdio>
#include <algorithm>

using namespace std;


bool cmp(int a,int b)
{
    if (a>b)return true;
    else return false;
}

int arr[20005];
int main()
{
    int kase;
    scanf("%d",&kase);

    while (kase--)
    {
        int n;
        scanf("%d",&n);

        for (int i=0;i<n;++i)
            scanf("%d",&arr[i]);
        sort(arr,arr+n,cmp);

        int result=0;
        for (int i=2;i<n;i+=3)
            result+=arr[i];
        printf("%d\n",result);
    }
    return 0;
}

#include <cstdio>
#include <algorithm>

using namespace std;

int arr[3];
int main()
{
    int kase;
    scanf("%d",&kase);
    while(kase--)
    {
        for (int i=0;i<3;++i)
            scanf("%d",&arr[i]);
        sort(arr,arr+3);
        if (arr[0]+arr[1]>arr[2])
            printf("OK\n");
        else
            printf("Wrong!!\n");
    }
    return 0;
}

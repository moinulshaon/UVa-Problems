#include <cstdio>
#include <vector>
#include <algorithm>
#define INF 1000000

using namespace std;

int arr[21000];

int main()
{
    int test;
    scanf("%d",&test);
    while (test--)
    {
        int money;
        scanf("%d",&money);

        arr[0]=0;
        for (int i=1;i<21000;++i)
            arr[i]=INF;

        int coins;
        scanf("%d",&coins);
        vector <int> v;
        int tmp;
        for (int i=0;i<coins;++i)
        {
            scanf("%d",&tmp);
            v.push_back(tmp);
        }
        int ind;

        for (int j=0;j<coins;++j)
        {
            for (ind=20999;ind>=0;--ind)
            {
                if (ind-v[j]>=0)
                    arr[ind]=min(arr[ind],1+arr[ind-v[j]]);
            }

        }
        for (int i=money;;++i)
            if (arr[i]!=INF)
            {
                printf("%d %d\n",i,arr[i]);
                break;
            }
    }
    return 0;
}

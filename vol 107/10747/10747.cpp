#include <cstdio>
#include <algorithm>
#define sz 11000

using namespace std;

int arr[sz];

bool cmp(int a,int b){
    if (a<b)return false;
    else return true;
}

int main()
{
    int n,r;
    while (true){
        scanf("%d %d",&n,&r);
        if (!n && !r)return 0;

        for (int i=0;i<n;++i)
            scanf("%d",&arr[i]);

        sort(arr,arr+n,cmp);

        int sum=0;
        for (int i=0;i<r;++i)
            sum+=arr[i];
        printf("%d\n",sum);
    }
}

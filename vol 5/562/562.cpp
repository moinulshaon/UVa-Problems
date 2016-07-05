#include <cstdio>
#include <algorithm>

using namespace std;

int arr[150];

int n;
int capacity;

int func(int i,int w)
{
    if (i==n || w>capacity)
        return 0;
    int p1,p2;
    if (w+arr[i]<=capacity)
        p1=arr[i]+func(i+1,w+arr[i]);
    else
        p1=0;
    p2=func(i+1,w);
    return max(p1,p2);
}

int main()
{
    int kase;
    scanf("%d",&kase);
    while (kase--)
    {
        capacity=0;
        scanf("%d",&n);
        for (int i=0;i<n;++i)
        {
            scanf("%d",&arr[i]);
            capacity+=arr[i];
        }
        int save=capacity;
        capacity/=2;



        int result=func(0,0);

        printf("%d\n",save-2*result);
    }
    return 0;
}

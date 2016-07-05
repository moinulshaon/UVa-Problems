#include <stdio.h>

long long arr[100005];

long long absolute(long long a)
{
    return (a<0)?-a:a;
}

int main()
{
    int n,i;
    while (1)
    {
        fscanf(stdin,"%d",&n);
        if (!n)return 0;
        for (i=0;i<n;++i)
            fscanf(stdin,"%lld",&arr[i]);

        long long cost=0;
        for (i=0;i<n-1;++i)
        {
            arr[i+1]+=arr[i];
            cost+=absolute(arr[i]);
        }
        fprintf(stdout,"%lld\n",cost);
    }
}

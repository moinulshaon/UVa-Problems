#include <cstdio>
#include <cmath>
#include <algorithm>
#define size 1000001
#define LONG long long
#define limit 80071

using namespace std;

bool prime[size];
LONG arr[limit];



int main()
{

    freopen("in.txt","r",stdin);

    for (int i=2;i<size;++i)
        prime[i]=true;
    for (int i=2;i<=1000;++i)
        if (prime[i])
            for (int j=i*2;j<size;j+=i)
                prime[j]=false;

    LONG temp;
    int cnt=0;
    for (int i=1;i<size;++i)
    {
        if (prime[i])
        {
            for (int j=2;(temp=pow(i,j))<1000000000000;++j)
                arr[cnt++]=temp;
        }
    }
    sort(arr,arr+cnt);

    LONG a,b;
    int test;
    scanf("%d",&test);
    int count;
    while (test--)
    {
        scanf("%lld %lld",&a,&b);
        count=0;
        for (int i=0;i<cnt;++i)
        {
            if (arr[i]>=a)
            {
                if (arr[i]>b)
                    break;
                else
                    ++count;

            }
        }
        printf("%d\n",count);

    }
    return 0;


}

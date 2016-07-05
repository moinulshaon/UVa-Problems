#include <cstdio>
#include <cmath>
#define size 5000001

using namespace std;

bool prime[size];
int sum[size];
int result[size];

int main()
{
    for (int i=2;i<size;++i)
        prime[i]=true;

    for (int i=2;i<=2500000;++i)
    {
        if  (prime[i])
            for (int j=i*2;j<size;j+=i)
            {
                prime[j]=false;
                sum[j]+=i;
            }
    }
    for (int i=2;i<size;++i)
    {
        if (!sum[i] || prime[sum[i]])
            result[i]=result[i-1]+1;
        else
            result[i]=result[i-1];
    }
    int a,b;
    while (true)
    {
        scanf("%d",&a);
        if (!a)return 0;
        scanf("%d",&b);

        printf("%d\n",result[b]-result[a-1]);

    }

}

#include <cstdio>
#include <cmath>
#define LONG long long

using namespace std;

LONG gcd(LONG a,LONG b)
{
    LONG temp;

    if (b>a)
    {
        temp=a;
        a=b;
        b=temp;
    }

    temp=a;
    while (b!=0)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    return temp;

}
LONG LCM(LONG a,LONG b)
{
    return a*b/gcd(a,b);
}


LONG arr[100];

int main()
{

    //freopen("in.txt","r",stdin);

    int n,q;
    LONG d;
    while (true)
    {
        scanf("%d %d",&n,&q);
        if (!n && !q)return 0;

        scanf("%lld",&arr[0]);


        d=arr[0];


        for (int i=1;i<n;++i)
        {
            scanf("%lld",&arr[i]);
            d=LCM(d,arr[i]);
            printf("%lld\n",d);
        }

        //printf("%lld\n",d);

        LONG now,temp;

        for (int i=0;i<q;++i)
        {
            scanf("%lld",&temp);

            now=0;
            while (now<temp)
                now+=d;
            if (now==temp)
                printf("%lld %lld\n",now,now);
            else
                printf("%lld %lld\n",now-d,now);

        }




    }
}

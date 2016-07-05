#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int arr[1010];

int gcd(int a,int b)
{
    int temp;
    if (b>a)
    {
        temp=b;
        b=a;
        a=temp;
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


int main()
{
    freopen("in.txt","r",stdin);

    int prv,now,d;
    while (true)
    {
        scanf("%d",&prv);
        if (!prv)return 0;

        int cnt=0;
        while (true)
        {
            scanf("%d",&now);
            if (!now)break;
            arr[cnt++]=abs(now-prv);
            prv=now;

        }


        d=arr[0];
        for (int j=1;j<cnt;++j)
        {

            d=gcd(d,arr[j]);

        }

        printf("%d\n",d);

    }
}

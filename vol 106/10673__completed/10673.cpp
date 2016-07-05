#include <cstdio>
#include <cmath>
#include <utility>
#define LONG long long


using namespace std;

pair < LONG , LONG  > result;

LONG gcd(LONG a,LONG b)
{
    LONG temp=a;
    while (b!=0)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    return temp;

}

void extendedgcd(LONG a,LONG b)
{
    LONG div,temp,x0=1,x1=0,y0=0,y1=1;

    while (b!=0)
    {
        div=a/b;
        temp=a;
        a=b;
        b=temp%b;

        temp=x1;
        x1=x0-div*x1;
        x0=temp;

        temp=y1;
        y1=y0-div*y1;
        y0=temp;
    }
    result=make_pair(x0,y0);

}

int main()
{
    int test;
    long long a,b,u,v,d;
    scanf("%d",&test);

    while (test--)
    {
        scanf("%lld %lld",&a,&b);

        u=floor(double(a)/b);
        v=ceil(double(a)/b);
        d=a/gcd(u,v);
        extendedgcd(u,v);
        result.first*=d;
        result.second*=d;
        printf("%lld %lld\n",result.first,result.second);

    }
    return 0;


}

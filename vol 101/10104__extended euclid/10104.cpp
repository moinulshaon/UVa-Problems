#include <cstdio>
#include <cmath>
#include <utility>

using namespace std;

pair < int, int > result;


int gcd(int a,int b)
{
    int temp=a;
    while (b!=0)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    return temp;

}

void extendedgcd(int a,int b)
{
    int div,temp,x0=1,x1=0,y0=0,y1=1;

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
    int a,b,temp;
    bool flagxneg,flagyneg,flagswap=false;

    while (scanf("%d %d",&a,&b)==2)
    {
        (a<0)?flagxneg=true:flagxneg=false;
        (b<0)?flagyneg=true:flagyneg=false;

        if (b>a)
        {
            temp=b;
            b=a;
            a=temp;
            flagswap=true;
        }

        int d=gcd(a,b);

        extendedgcd(a/d,b/d);
        if (flagswap)
        {
            temp=result.second;
            result.second=result.first;
            result.first=temp;
            flagswap=false;
        }
        result.first=(flagxneg)?-result.first:result.first;
        result.second=(flagxneg)?-result.second:result.second;


        printf("%d %d %d\n",result.first,result.second,d);
    }
    return 0;

}

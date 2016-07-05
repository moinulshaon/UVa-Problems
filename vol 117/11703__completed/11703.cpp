#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

long long x[1000001];
double EPS=1e-9;

long long func(long long n)
{
    if (x[n]!=-1)return x[n];
    else if (n==0)return x[n]=1;
    else
    {
        double tmp=sin(n);
        return x[n]=( func(  floor(n-sqrt(n)) )+func( floor( log(n)+EPS ) ) +func( floor( n*tmp*tmp ) ) )%1000000;
    }
}


int main()
{
    long long input;
    memset(x,-1,sizeof(x));

    while (true)
    {
        scanf("%lld",&input);
        if (input==-1)return 0;

        printf("%lld\n",func(input));
    }
}


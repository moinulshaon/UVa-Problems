#include <cstdio>
#include <cmath>
#include <vector>
#define sz 47000

using namespace std;

bool prime[sz];
vector <long long> p;

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

int main()
{

    //freopen("in.txt","r",stdin);

    for (int i=2;i<=216;++i)
        if (!prime[i])
            for (int j=i*2;j<sz;j+=i)
                prime[j]=true;
    for (int i=2;i<sz;++i)
        if (!prime[i])
            p.push_back(i);

    long long  in;
    while (true)
    {
        scanf("%lld",&in);
        if (!in)return 0;

        bool neg=false;
        if (in<0)
        {
            neg=true;
            in=-in;
        }

        int d=1;
        bool on=true;
        for (int i=0;p[i]*p[i]<=in && in!=1 && i<p.size();++i)
        {
            int cnt=0;
            while (in%p[i]==0)
            {
                in/=p[i];
                ++cnt;
            }

            if (cnt)
            {
                if (on)
                {
                    d=cnt;
                    on=false;
                }
                d=gcd(d,cnt);
            }
        }
        if ( d %2 )
            printf("%d\n",d);
        else
        {
            if (neg)
            {
                while (d%2==0)
                    d/=2;
                printf("%d\n",d);
            }

            else
                printf("%d\n",d);
        }
    }

}

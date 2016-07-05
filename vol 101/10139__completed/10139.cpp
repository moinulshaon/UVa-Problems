#include <cstdio>
#include <cmath>
#include <vector>
#define sz 46500

using namespace std;

bool prime[sz];
vector <long long> p;
int main()
{
    for (int i=2;i<sz;++i)
        prime[i]=true;
    for (int i=2;i<=215;++i)
        if (prime[i])
            for (int j=i*2;j<sz;j+=i)
                prime[j]=false;

    for (int i=2;i<sz;++i)
        if (prime[i])
            p.push_back(i);

    long long  fact,div;
    while (scanf("%lld %lld",&fact,&div)==2)
    {
        if (!div)
        {
            printf("0 does not divide %lld!\n",fact);
            continue;
        }
        bool divides=true;
        long long save=div;
        for (int i=0;p[i]*p[i]<=div && divides;++i)
        {
            if (div%p[i]==0)
            {
                long long  cnt=0;
                while (div%p[i]==0)
                {
                    div/=p[i];
                    ++cnt;
                }
                long long ss=p[i];
                while (fact/ss)
                {
                    cnt-=fact/ss;
                    ss*=p[i];
                }
                if (cnt>0)
                {
                    divides=false;
                    break;
                }
            }
        }
        if (divides)
        {
            if (div!=1)
            {
                long long cnt=1;
                long long ss=div;
                while (fact/ss)
                {
                    cnt-=fact/ss;
                    ss*=div;
                }
                if (cnt>0)
                    printf("%lld does not divide %lld!\n",save,fact);
                else
                    printf("%lld divides %lld!\n",save,fact);
            }
            else
                printf("%lld divides %lld!\n",save,fact);
        }
        else
            printf("%lld does not divide %lld!\n",save,fact);
    }
    return 0;


}

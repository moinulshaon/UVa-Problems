#include <cstdio>
#include <cmath>
#include <vector>
#include <climits>
#define sz 2097152
using namespace std;

bool prime[1000];
vector <int> p;
double lll[sz];

int main()
{
    int base,number,pi=acos(-1);

    for (int i=2;i<1000;++i)
        prime[i]=true;
    for (int i=2;i<=31;++i)
        if (prime[i])
            for (int j=i*2;j<1000;j+=i)
                prime[j]=false;

    for (int i=2;i<1000;++i)
        if (prime[i])
            p.push_back(i);

    for (int i=1;i<sz;++i)
        lll[i]=log(i);

    while (scanf("%d %d",&number,&base)==2)
    {
        double digit=0;
        for (int i=1;i<=number;++i)
            digit+=lll[i];
        digit/=lll[base];

        long long dd=ceil(digit+1e-10);
        long long zero=INT_MAX;
        for (int i=0;p[i]<=base;++i)
        {
            int cnt=0;
            while (base%p[i]==0)
            {
                ++cnt;
                base/=p[i];
            }
            int fact=0,save=p[i];
            if (cnt)
            {
                while (number/save)
                {
                    fact+=number/save;
                    save*=p[i];
                }
                fact/=cnt;
                zero=zero<fact?zero:fact;
            }
        }
        printf("%lld %lld\n",zero,dd);
    }
    return 0;
}

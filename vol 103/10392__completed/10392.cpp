#include <cstdio>
#include <cmath>
#include <vector>
#define sz 1000001

using namespace std;

bool prime[sz];
vector <int> p;

int main()
{

    for (int i=2;i<sz;++i)
        prime[i]=true;
    for (int i=2;i<=1000;++i)
        if (prime[i])
            for (int j=i*2;j<sz;j+=i)
                prime[j]=false;
    for (int i=2;i<sz;++i)
        if (prime[i])
            p.push_back(i);

    long long in;
    while (true)
    {
        scanf("%lld",&in);
        if (in<0)return 0;
        for (int i=0;i<p.size();++i)
            while (in%p[i]==0)
            {
                printf("    %d\n",p[i]);
                in/=p[i];
            }
        if (in!=1)
            printf("    %lld\n",in);
        printf("\n");
    }
}

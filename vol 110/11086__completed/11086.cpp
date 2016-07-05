#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

bool prime[1100];
vector <int> p;

int main()
{
    for (int i=2;i<1100;++i)
        prime[i]=true;
    for (int i=2;i<=33;++i)
        if (prime[i])
            for (int j=i*2;j<1100;j+=i)
                prime[j]=false;

    for (int i=2;i<1100;++i)
        if (prime[i])
            p.push_back(i);
    int total,in;
    while (scanf("%d",&total)==1)
    {
        int cnt=0;
        while (total--)
        {
            scanf("%d",&in);

            int tt=0;
            for (int i=0;i<p.size() && p[i]*p[i]<=in && tt<3;++i)
            {
                while (in%p[i]==0)
                {
                    in/=p[i];
                    ++tt;
                }

            }
            if (in!=1)
                ++tt;
            if (tt==2)
            {
                ++cnt;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}

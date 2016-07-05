#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

bool prime[101];
vector <int> p;

int main()
{
    int i,j;;
    prime[0]=prime[1]=true;
    for (i=2;i<=10;++i)
        if (!prime[i])
            for (j=i*2;j<101;j+=i)
                prime[j]=true;
    for (int i=2;i<101;++i)
        if (!prime[i])
            p.push_back(i);

    int n,d,cnt,cnt2,save;
    long long result;
    bool divides;
    while (true)
    {
        scanf("%d %d",&n,&d);
        if (!n && !d)return 0;

        if (d<0)d=-d;

        divides=true;
        result=1;
        for (int i=0;i!=p.size();++i)
        {
            cnt=0;
            while (d%p[i]==0)
            {
                d/=p[i];
                ++cnt;
            }
            cnt2=0,save=p[i];
            while(n/save)
            {
                cnt2+=n/save;
                save*=p[i];
            }
            if (cnt2<cnt)
            {
                divides=false;
                break;
            }
            else
                result*=cnt2-cnt+1;
        }
        if (divides && d==1)
            printf("%lld\n",result);
        else
            printf("0\n");
    }

}

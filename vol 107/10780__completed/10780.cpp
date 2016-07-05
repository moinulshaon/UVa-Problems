#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#define size 10000

using namespace std;


bool prime[size];


int main()
{

    freopen("in.txt","r",stdin);
    freopen("out1.txt","w",stdout);

    for (int i=2;i<size;++i)
        prime[i]=true;
    for (int i=2;i<=100;++i)
        if (prime[i])
            for (int j=i*2;j<size;j+=i)
                prime[j]=false;

    int test,m,n;
    scanf("%d",&test);
    for (int k=1;k<=test;++k)
    {
        scanf("%d %d",&m,&n);

        printf("Case %d:\n",k);
        int result=10000000;

        map <int,int> myp,myp2;
        map <int,int> :: iterator it;
        int sh=sqrt(m);
        for (int i=2;i<=sh;++i)
            if (prime[i] && m%i==0)
                while (m%i==0)
                {
                    ++myp[i];
                    m/=i;
                }
        if (m>sh)
            ++myp[m];


        for (int i=2;i<=n;++i)
        {
            int temp=i;
            int s=sqrt(temp);
            for (int j=2;j<=s;++j)
            if (prime[j] && temp%j==0)
                while (temp%j==0)
                {
                    ++myp2[j];
                    temp/=j;
                }
            if (temp>s)
                ++myp2[temp];
        }

        bool pos=true;
        for (it=myp.begin();it!=myp.end();++it)
        {
            if ( myp2.find(it->first)==myp2.end() || myp2[it->first] / it->second <1 )
            {
                pos=false;
                break;
            }
            if (result> (myp2[it->first] / it->second ))
                result=myp2[it->first] / it->second;

        }

        if (pos)
            printf("%d\n",result);
        else
            printf("Impossible to divide\n");
    }
    return 0;
}

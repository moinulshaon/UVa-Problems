#include <cstdio>
#include <cmath>
#define size 1000001

using namespace std;

bool prime[size];
int result[size];
int nod[size];
int N[size];

int main()
{

    freopen("input.txt","r",stdin);

    for (int i=2;i<size;++i)
        prime[i]=true;

    for (int i=0;i<size;++i)
        nod[i]=1;

    for (int i=2;i<=500000;++i)
    {
        if (prime[i])
        {
            for (int j=i*2;j<size;j+=i)
            {
                int count=1,temp=j;
                prime[j]=false;
                while (temp%i==0)
                {
                    temp/=i;
                    ++count;
                }
                nod[j]*=count;
            }
        }
    }
    for (int i=0;i<size;++i)
        if (prime[i])
            nod[i]=2;

    N[0]=result[1]=1;
    for (int i=1;N[i-1]<size;++i)
    {

        N[i]=N[i-1]+nod[N[i-1]];
        if (N[i]<size)
            ++result[N[i]];
    }
    for (int i=1;i<size;++i)
        result[i]+=result[i-1];

    int cases,a,b;

    scanf("%d",&cases);
    for (int m=1;m<=cases;++m)
    {
        scanf("%d %d",&a,&b);
        printf("Case %d: %d\n",m,result[b]-result[a-1]);
    }


    return 0;


}

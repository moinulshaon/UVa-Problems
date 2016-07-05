#include <cstdio>
#include <cmath>
#define size 200001
#define LONG long long

using namespace std;

bool prime[size];
int phi[size];
LONG sum[size];


int gcd(int a,int b)
{
    if (a==1 && b==0)return 1;
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
    for (int i=2;i<size;++i)
    {
        prime[i]=true;
        phi[i]=i;
    }

    phi[0]=phi[1]=1;
    for (int i=2;i<size;++i)
        if (prime[i])
        {
            phi[i]=i-1;
            for (int j=i*2;j<size;j+=i)
            {
                prime[j]=false;
                phi[j]=phi[j]/i*(i-1);
            }
        }
    sum[0]=1;
    for (int i=1;i<size;++i)
        sum[i]=sum[i-1]+phi[i];


    sum[0]=0;
    LONG input;
    int num,den;
    while (true)
    {
        scanf("%lld",&input);
        if (!input)return 0;
        for (den=1;sum[den]<input;++den)
            ;
        LONG temp=sum[den-1];
        int count=0;

        for ( num=0;;++num)
        {
            if (gcd(den,num)==1)
                ++count;
            if (temp+count==input)
                break;
        }
        printf("%d/%d\n",num,den);
    }


}

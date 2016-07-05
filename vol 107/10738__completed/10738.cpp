#include <cstdio>
#include <cmath>
#define size 1000001

bool prime[size];
int result[size];
bool vis[size];
int sum[size];

int main()
{
    for (int i=2;i<size;++i)
        prime[i]=true;

    for (int i=2;i<=500000;++i)
    {
        if (prime[i])
        {
            for (int j=i*2;j<size;j+=i)
            {
                prime[j]=false;
                if (!vis[j])
                {
                    int temp=j;
                    if (temp%i==0)
                    {
                        temp/=i;
                        if (temp%i==0)
                        {
                            vis[j]=true;
                            result[j]=0;
                        }
                        else
                            ++result[j];
                    }
                }
            }
        }
    }
    result[1]=1;
    for (int i=2;i<size;++i)
    {
        if (prime[i])
            result[i]=-1;
        if (!vis[i])
        {
            if (result[i] & 1)
                result[i]=-1;
            else
                result[i]=1;
        }
    }

    for (int i=1;i<size;++i)
        sum[i]=sum[i-1]+result[i];

    int input;

    while (true)
    {
        scanf("%d",&input);
        if (!input)return 0;

        printf("%8d%8d%8d\n",input,result[input],sum[input]);
    }

}

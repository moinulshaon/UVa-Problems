#include <cstdio>
#include <cmath>
#define size 10001

using namespace std;

bool prime[size];

int main()
{
    for (int i=2;i<size;++i)
        prime[i]=true;
    for (int i=2;i<=100;++i)
        if (prime[i])
            for (int j=i*2;j<size;j+=i)
                prime[j]=false;

    int test,input,max,maxprime;
    scanf("%d",&test);

    while (test--)
    {
        scanf("%d",&input);
        max=0;
        for (int i=input;i>input/2;--i)
        {
            if (prime[i])
            {
                if (input-i>max)
                {
                    max=input-i;
                    maxprime=i;
                }
            }
        }
        printf("%d\n",maxprime);

    }
    return 0;

}

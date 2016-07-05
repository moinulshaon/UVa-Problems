#include <cstdio>
#include <cmath>
#define size 1000001

using namespace std;

bool prime[size];

int main()
{
    prime[1]=prime[1]=true;

    for (int i=2;i<=1000;++i)
        if (!prime[i])
            for (int j=i*2;j<size;j+=i)
                prime[j]=true;

    int input;
    while (true)
    {
        scanf("%d",&input);
        if (!input)return 0;

        printf("%d:\n",input);

        if (input & 1)
        {
            if (!prime[input-2])
                printf("2+%d\n",input-2);
            else
                printf("NO WAY!\n");
        }
        else
        {
            if (input==4)
                printf("2+2\n");
            else
            {
                for (int i=3;;i+=2)
                    if (!prime[i] && !prime[input-i])
                    {
                        printf("%d+%d\n",i,input-i);
                        break;
                    }

            }



        }
    }
    return 0;


}

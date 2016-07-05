#include <cstdio>
#include <cstring>

using namespace std;
char input[10010];

void Stern_Brocot(long long cnt,long long num1,long long den1,long long num2,long long den2)
{
    if (!input[cnt])
        printf("%lld/%lld\n",num1+num2,den1+den2);
    else if (input[cnt]=='L')
        Stern_Brocot(1+cnt,num1,den1,num1+num2,den1+den2);
    else
        Stern_Brocot(1+cnt,num1+num2,den1+den2,num2,den2);
}

int main()
{
    int kase;
    scanf("%d",&kase);
    getchar();
    while (kase--)
    {
        gets(input);

        long long num1=0,den1=1,num2=1,den2=0;

        Stern_Brocot(0,num1,den1,num2,den2);
    }
    return 0;

}

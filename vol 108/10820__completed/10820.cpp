#include <cstdio>
#define size 50001

using namespace std;

int phi[size];
int result[size];
bool prime[size];

int main()
{

    freopen("in.txt","r",stdin);

    for (int i=2;i<size;++i)
    {
        prime[i]=true;
        phi[i]=i;
    }
    phi[1]=1;
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
    result[1]=1;

    for (int i=2;i<size;++i)
    {
        result[i]=result[i-1]+2*phi[i];
    }
    int input;
    while (true)
    {
        scanf("%d",&input);
        if (!input)return 0;
        printf("%d\n",result[input]);
    }

}

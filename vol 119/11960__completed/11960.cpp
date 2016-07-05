#include <cstdio>
#include <cmath>
#include <cstring>
#define size 1000001

bool prime[size];
int result[size];
int result2[size];
int main()
{

    //freopen("input.txt","r",stdin);

	int test,input;
	for (int i=2;i<size;++i)
		prime[i]=true;

    for (int i=0;i<size;++i)
        result[i]=1;





	for (int i=2;i<=1000;++i)
    {
        if (prime[i])
        {
            for (int j=i*2;j<size;j+=i)
            {
                prime[j]=false;
                int tempr=1,tempj=j;
                while (!(tempj%i))
                {
                    tempj/=i;
                    ++tempr;
                }
                result[j]*=tempr;
            }
        }
    }

    int tt;
    result2[1]=result[1]=1;
	for (int i=2;i<size;++i)
    {

        if (result[i]>=result[result2[i-1]])
            result2[i]=i;
        else
            result2[i]=result2[i-1];
    }
    scanf("%d",&test);
    while (test--)
    {
        scanf("%d",&input);
        printf("%d\n",result2[input]);
    }
    return 0;

}

#include <cstdio>
#define size 100000001


using namespace std;

bool prime[size];

int main()
{
    freopen("in.txt","r",stdin);

	int input;
	bool printed;
	for (int i=2;i<size;++i)
		prime[i]=true;

	for (int i=2;i<=10000;++i)
		if (prime[i])
			for (int j=i*2;j<size;j+=i)
				prime[j]=false;

	while (scanf("%d",&input)==1)
	{
	    printed=false;
        if (!(input & 1))
        {
            if (input==2)
                printf("2 is not the sum of two primes!\n");
            else if (input==4)
                printf("4 is not the sum of two primes!\n");
            else
            {
                int i=input/2-1;
                if (!(i & 1))
                    --i;

                for (;i>0;i-=2)
                {

                    if (prime[i] && prime[input-i])
                    {
                         printf("%d is the sum of %d and %d.\n",input,i,input-i);
                         printed=true;
                         break;
                    }
                }
                if (!printed)
                    printf("%d is not the sum of two primes!\n",input);
            }
        }
        else
        {
            if (input>3  && prime[2] && prime[input-2])
                printf("%d is the sum of %d and %d.\n",input,2,input-2);
            else
                printf("%d is not the sum of two primes!\n",input);
        }

	}
	return 0;


}

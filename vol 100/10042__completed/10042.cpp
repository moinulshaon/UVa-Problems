#include <cstdio>
#include <cmath>
#define size 31623


using namespace std;
bool prime[size];
bool p;

int sumofdigit(int input)
{
    int digit=0;
    while (input)
    {
        digit+=input%10;
        input/=10;
    }
    return digit;
}

int div(int input)
{
	int result=0,temp=input,temp2=sqrt(input);
	for (int i=0; input!=1  && i<=temp2;++i)
	{
		if (prime[i]&& input%i==0)
		{
			while (input%i==0)
			{
				input/=i;
				result+=sumofdigit(i);

			}
		}
	}

	if (input>temp2)
	{
	    result+=sumofdigit(input);
	    if (input==temp)
            p=true;
	}
    return result;

}




int main()
{

    freopen("in.txt","r",stdin);

    for (int i=2;i<size;++i)
		prime[i]=1;

	for (int i=2;i<=177;++i)
		if (prime[i])
			for (int j=i*2;j<size;j+=i)
				prime[j]=0;
    int test;
    scanf("%d",&test);

    int input;
    while (test--)
    {
        scanf("%d",&input);

        for (int i=input+1;;++i)
        {
            p=false;
            if (sumofdigit(i)==div(i) && !p)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;


}

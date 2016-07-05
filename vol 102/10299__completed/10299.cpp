#include <cstdio>
#include <cmath>
#include <vector>
#define size 32000

using namespace std;

bool prime[size];

vector <int> p;

int totient(int input)
{
    int srt=sqrt(input),result=input,save=input;

    for (int i=0;p[i]<=srt && input!=1 ;++i)
    {
        if (input%p[i]==0)
        {
            result=result/p[i]*(p[i]-1);
            while (input%p[i]==0)
                input/=p[i];
        }
    }
    if (input==save)
        result=input-1;
    else if (input>srt)
        result=result/input*(input-1);
    return result;

}



int main()
{
    for (int i=2;i<size;++i)
        prime[i]=true;
    for (int i=2;i<=177;++i)
        if (prime[i])
            for (int j=i*2;j<size;j+=i)
                prime[j]=false;

    for (int i=2;i<32000;++i)
        if (prime[i])
            p.push_back(i);


    int input;
    while (true)
    {
        scanf("%d",&input);
        if (!input)return 0;

        printf("%d\n",totient(input));
    }
}

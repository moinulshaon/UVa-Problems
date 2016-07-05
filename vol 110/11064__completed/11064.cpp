
#include <cstdio>
#include <cmath>
#include <vector>
#define size 47000

using namespace std;

bool prime[size];

vector <int> p;

int totient(int input)
{
    int plus=1,srt=sqrt(input),result=input,save=input,temp;

    for (int i=0;p[i]<=srt && input!=1 ;++i)
    {
        if (input%p[i]==0)
        {
            temp=0;
            result=result/p[i]*(p[i]-1);
            while (input%p[i]==0)
            {
                input/=p[i];
                ++temp;
            }
            plus*=(temp+1);
        }
    }
    if (input==save)
        return 0;
    else if (input>srt)
    {
        result=result/input*(input-1);
        plus*=2;
    }
    return save-result-plus+1;

}



int main()
{


    for (int i=2;i<size;++i)
        prime[i]=true;
    for (int i=2;i<=216;++i)
        if (prime[i])
            for (int j=i*2;j<size;j+=i)
                prime[j]=false;

    for (int i=2;i<size;++i)
        if (prime[i])
            p.push_back(i);


    int input;
    while (scanf("%d",&input)==1)
    {

        printf("%d\n",totient(input));
    }
    return 0;
}

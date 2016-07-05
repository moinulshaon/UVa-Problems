#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool prime[70];
unsigned long long mmax;
vector <unsigned long long> result;
int main()
{
    for (unsigned long long num=1,i=0;i<64;++i,num<<=1 )
        mmax |= num;

    //printf("%llu\n",mmax);
    for (int i=2;i<70;++i)
        prime[i]=true;
    for (int i=2;i<=8;++i)
        if (prime[i])
            for (int j=i*2;j<70;j+=i)
                prime[j]=false;
    for (unsigned long long i=2;i<65536;++i)
    {
        unsigned long long  tmp=i*i*i*i;
        for (int j=4; mmax/tmp>=i ;tmp*=i,++j)
        {
            if (!prime[j])
                result.push_back( tmp );
        }
    }
    int tmp=result.size();
    sort(result.begin(),result.end());


    printf("1\n");
    for (int i=0;i<tmp;++i)
        if (i==0 || ( i && result[i]!=result[i-1]) )
            printf("%llu\n",result[i]);
    return 0;

}

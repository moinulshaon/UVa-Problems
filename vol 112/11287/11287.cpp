#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

vector <int> prime;
bool p[32001];

bool isprime(int a)
{
    int srt=sqrt(a);
    for (int i=0; prime[i]<=srt ;++i)
        if (a%prime[i]==0)
            return false;
    return true;
}
long long square(long long k)
{
    return k * k;
}

long long BigMod(long long a, long long n, long long p)
{
    if(n == 1)  return a % p;
    else if(n % 2 == 0)  return square(BigMod(a, n/2, p)) % p;
    else return ((square(BigMod(a, n/2, p))%p)*(a % p)) % p;
}


int main()
{
    for (int i=2;i<=178;++i)
        if (!p[i])
            for (int j=i*2;j<32001;j+=i)
                p[j]=true;

    for (int i=2;i<32001;++i)
        if (!p[i])
            prime.push_back(i);


    long long  n,a,final;
    while (true)
    {
        scanf("%lld %lld",&n,&a);

        if (!n && !a)return 0;

        final=1;

        if (isprime(n))
        {
            printf("no\n");
            continue;
        }



        if (a==BigMod(a,n,n))
            printf("yes\n");
        else
            printf("no\n");


    }
}

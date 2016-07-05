#include <cstdio>
#include <cmath>

using namespace std;

long long square(long long k){
    return k * k;
}

long long BigMod(long long a, long long n, long long p)
{
    if(n == 1)  return a % p;
    else if(n % 2 == 0)  return square(BigMod(a, n/2, p)) % p;
    else return ((square(BigMod(a, n/2, p))%p)*(a % p)) % p;
}

int main(){

    int kase;
    scanf("%d",&kase);

    long long a,b;

    for (int kk=1;kase--;++kk){

        scanf("%lld %lld",&a,&b);

        double tmp=b*log10(a);
        tmp=tmp-floor(tmp);

        tmp=pow(10,tmp);

        printf("%03d...%03lld\n",int(tmp*100),BigMod(a,b,1000));

    }
    return 0;

}

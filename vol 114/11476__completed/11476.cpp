#include <cstdio>

using namespace std;

#define myabs(x) ( (x)<0 )?(-x):(x)

long long gcd(long long a,long long  b)
{
    int temp=a;
    while (b!=0)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    return temp;

}

void pollardRHO(long long n){

    long long i=1,x=2,y=2,k=2;

    while (true){
        i++;
        x=(x*x-1)%n;
        long long d= gcd( myabs(y-x),n ) ;
        d=myabs(d);
        if (d!=1 && d!=n)
            printf("%lld\n",d);
        printf("%d\n",d);
        if (i==k){
            y=x;
            k=2*k;
        }
        if (d<0)return;
    }


}

int main(){
    freopen("in.txt","r",stdin);

    int kase;

    scanf("%d",&kase);

    long long number;
    while (kase--){

        scanf("%lld",&number);

        pollardRHO(number);

    }
}

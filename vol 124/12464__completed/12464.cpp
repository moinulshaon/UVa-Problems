#include <cstdio>

using namespace std;

typedef long long LL;

int main(){

    LL a,b,n;
    while(true){
        scanf("%lld %lld %lld",&a,&b,&n);
        if ( !a && !b && !n )return 0;

        if ( n%5==0 ){
            printf("%lld\n",a);
        }else if ( n%5==1 ){
            printf("%lld\n",b);
        }else if ( n%5==2 ){
            printf("%lld\n",(1+b)/a);
        }else if ( n%5==3 ){
            printf("%lld\n",(1+a+b)/(a*b));
        }else{
            printf("%lld\n",(1+a)/b);
        }
    }
    return 0;
}

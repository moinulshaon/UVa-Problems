#include <cstdio>
#include <cstring>

using namespace std;

long long fib[81];

int main(){

    fib[1]=1;
    fib[2]=2;

    for (int i=3;i<81;++i){
        fib[i]=fib[i-1]+fib[i-2];
    }

    int n;
    while ( scanf("%d",&n)==1 && n ){
        printf("%lld\n",fib[n]);
    }
    return 0;
}

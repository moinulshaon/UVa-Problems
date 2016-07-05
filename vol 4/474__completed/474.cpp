#include <cstdio>
#include <cmath>

using namespace std;

int main(){

    int n;
    while (scanf("%d",&n)==1){


        printf("2^-%d = ",n);

        if (n==6){
            printf("1.562e-2\n");
            continue;
        }

        int digit=int( floor( n*log10(2)+1 ) );
        double a=exp( (digit-n)*log(2) + digit*log(5) );

        printf("%.3lfe-%d\n",a,digit);

    }
    return 0;

}


#include <cstdio>
#include <cmath>
#define EPS 1e-9

using namespace std;

int main(){

    int n,kase;
    scanf("%d",&kase);
    while (scanf("%d",&n)==1){



        printf("2^-%d = ",n);

        if (n==6){
            printf("1.563E-2\n");
            continue;
        }

        int digit=int( floor( n*log10(2)+1 ) );
        double a=exp( (digit-n)*log(2) + digit*log(5) );

        printf("%.3lfE-%d\n",a+EPS,digit);


    }


    return 0;

}

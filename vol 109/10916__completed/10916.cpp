#include <cstdio>
#include <cmath>
#define sz 21

using namespace std;

int year[sz];
int requirment[sz];
double save[4200000];

double factorialDigitInBase2(int n){
    if (save[n])return save[n];

    return save[n] = factorialDigitInBase2(n-1)+log2(n)  ;
}

int main(){

    freopen("out.txt","w",stdout);

    requirment[0]=4;
    for (int i=1;i<sz;++i){
        requirment[i]=2*requirment[i-1];
    }

    save[2]=1;

    for (int i=0;i<sz;++i){
        for (int j=2; floor( factorialDigitInBase2(j)  )+1<=requirment[i] ;++j )
            year[i]=j;
    }

    for (int i=0;i<sz;++i)
        printf("%d\n",year[i]);

}

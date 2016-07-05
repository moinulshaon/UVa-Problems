#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

const double EPS=1e-6;


int main(){

    freopen("in.txt","r",stdin);

    int kase;
    long long r;
    long long m;
    scanf("%d",&kase);

    while (kase--){

        scanf("%lld",&m);

        r=  ( -1+ ( long long )sqrt(1+8*m) )/2+EPS ;

        printf("%lld\n",r);
    }
    return 0;

}

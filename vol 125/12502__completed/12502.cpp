#include <cstdio>
using namespace std;

int main(){

    int kase;
    scanf("%d",&kase);
    double a,b,taka;
    while (kase--){
        scanf("%lf %lf %lf",&a,&b,&taka);
        double tmp=(a+b)/3;
        printf("%.0lf\n",(a-tmp)*taka/tmp );
    }
    return 0;

}

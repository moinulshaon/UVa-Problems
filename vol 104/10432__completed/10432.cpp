#include <cstdio>
#include <cmath>

using namespace std;

int main(){

    double radius,n;
    double PI=acos(-1);

    while (scanf("%lf %lf",&radius,&n)==2){
        printf("%.3lf\n",.5*radius*radius*n*sin(2*PI/n));
    }
    return 0;
}

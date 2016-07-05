#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int main(){
    double PI=acos(-1);

    double a, r1, r2, r3, r4;
    //double sin30=sin(PI/6);
    double cos30=cos(PI/6);

    //cout<<sin30<<endl;

    while (scanf("%lf",&a)==1) {
        r1 = a*cos30;
        r3 = r1 / 2.0;

        r2 = a*cos30/(1+cos30);
        r4 = r2 * 3.0 / 3.71266222325 ;
        printf("%.10lf %.10lf %.10lf %.10lf\n", r1, r2, r3, r4);
    }
    return 0;
}

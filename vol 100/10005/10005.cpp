#include <cstdio>
#include <cmath>
#include <complex>
#include <iostream>

using namespace std;

typedef complex <double> point;

point points[150];

int main(){

    freopen("in.txt","r",stdin);

    int n;
    double a,b;
    double r;
    while (scanf("%d",&n)==1 && n){
        point sum;

        for (int i=0;i<n;++i){
            scanf("%lf %lf",&a,&b);

            points[i]=point(a,b);
            sum+=points[i];

        }
        sum=point( sum.real()/n,   sum.imag()/n );


        scanf("%lf",&r);

        bool pos=true;
        for (int i=0;i<n;++i){

            if (  abs(   sum-points[i] ) >r ){
                cout<<i<<' '<<abs(   sum-points[i] )<<endl;
                pos=false;
                break;
            }
        }

        if (pos){
            printf("The polygon can be packed in the circle.\n");
        }else{
            printf("There is no way of packing that polygon.\n");
        }


    }
    return 0;

}

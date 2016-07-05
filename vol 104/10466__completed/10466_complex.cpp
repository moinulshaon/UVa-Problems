#include <cstdio>
#include <cmath>
#include <complex>

using namespace std;


int main(){

    freopen("in.txt","r",stdin);

    int total,time,t,r;

    double PI=acos(-1),theta,result;



    while (scanf("%d %d",&total,&time)==2){
        complex<double> point;

        for (int i=1;i<total;++i){
            scanf("%d %d",&r,&t);

            theta=2*PI*time/t;

            point+=complex<double> ( r*sin(theta),r*cos(theta) );

            printf("%.4lf ",abs(point));
        }
        scanf("%d %d",&r,&t);

        theta=2*PI*time/t;

        point+=complex<double> ( r*sin(theta),r*cos(theta) );

        printf("%.4lf\n",abs(point));

    }
    return 0;

}

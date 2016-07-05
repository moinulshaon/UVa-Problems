#include <cstdio>
#include <cmath>

using namespace std;




double powerOfTwo(double x){
    return x*x;
}

int main(){

    freopen("in.txt","r",stdin);

    int total,time,t,r;

    double PI=acos(-1),theta,vx,vy,result;

    while (scanf("%d %d",&total,&time)==2){
        vx=vy=0;

        for (int i=1;i<total;++i){
            scanf("%d %d",&r,&t);

            theta=2*PI*time/t;

            vy+=r*sin(theta);
            vx+=r*cos(theta);

            result=sqrt( powerOfTwo(vx)+powerOfTwo(vy) );

            printf("%.4lf ",result);
        }
        scanf("%d %d",&r,&t);

        theta=2*PI*time/t;

        vy+=r*sin(theta);
        vx+=r*cos(theta);

        result=sqrt( powerOfTwo(vx)+powerOfTwo(vy) );

        printf("%.4lf\n",result);

    }
    return 0;

}

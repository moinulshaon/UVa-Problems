#include <cstdio>
#include <cmath>

using namespace std;

const double EPS=1e-8;

int main(){

    int kase;


    scanf("%d",&kase);

    double d,u,v;

    for (int kk=1;kase--;++kk){
        scanf("%lf %lf %lf",&d,&v,&u);

        if ( ! ( v<u ) || u<EPS || v<EPS ){
            printf("Case %d: can't determine\n",kk);
        }else{
            printf("Case %d: %.3lf\n",kk,d*( 1/sqrt(u*u-v*v)- 1/u  ) );
        }
    }
    return 0;

}

#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const double PI=acos(-1);

const double lim=32+1e-6;

int main(){

    freopen("in.txt","r",stdin);

    int kase;
    double t,th;
    scanf("%d",&kase);

    while(kase--){
        scanf("%lf %lf",&t,&th);

        th*=PI/180;
        t*=100;


        double dis=cos(th)*( t*tan(th)-105*0 );
        bool pos=false;

        for (int i=1;dis> -lim-100 ;++i){

            printf("%lf\n",dis);
            if ( fabs(dis) < lim ){
                pos=true;
                break;
            }
            dis=cos(th)*( t*tan(th)-105*i );
        }
        if ( pos )
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}

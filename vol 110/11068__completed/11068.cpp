#include <cstdio>
#include <cmath>

using namespace std;

int main(){

    int a1,b1,c1,a2,b2,c2,determinant;

    while (true){

        scanf("%d %d %d %d %d %d",&a1,&b1,&c1,&a2,&b2,&c2);

        if (!a1 && !b1 && !c1 && !a2 && !b2 && !c2)return 0;


        if ( ( determinant= a1*b2-a2*b1)==0 ){
            printf("No fixed point exists.\n");
        }else{
            double  x= double( b1*(-c2)- b2*(-c1) )/determinant;
            double  y= double( a2*(-c1)-a1*(-c2) )/determinant;

            if (fabs(x)<1e-5)
                x=0;
            if (fabs(y)<1e-5)
                y=0;

            printf("The fixed point is at %.2lf %.2lf.\n",x,y );
        }

    }

}

#include <cstdio>
#include <cmath>
#include <iostream>

#define CIRCLE 1
#define RECTANGLE 2
#define TRIANGLE 3

#define EPS 1e-6

#define sz 15
using namespace std;

struct FIG{
    int state;
    double center_x,center_y,radius;
    double upperLeft_x,upperLeft_y,lowerRight_x,lowerRight_y;
    double points[3][2];

    bool check(double a,double b){
        if (state==CIRCLE){
            if (pow( center_x-a,2 )+pow( center_y-b,2 )-radius*radius<0)
                return true;
            else
                return false;
        }
        else if (state==RECTANGLE){
            if ( a>upperLeft_x && a <lowerRight_x && b<upperLeft_y && b>lowerRight_y)
                return true;
            else
                return false;
        }
        else if (state==TRIANGLE){
            double totalArea=.5*fabs( ( points[0][0]-points[1][0])*( points[1][1]-points[2][1] ) - ( points[0][1]-points[1][1])*( points[1][0]-points[2][0] ) );
            double xx=.5*fabs( ( points[0][0]-points[1][0])*( points[1][1]-b ) - ( points[0][1]-points[1][1])*( points[1][0]-a ) );
            double yy=.5*fabs( ( points[0][0]-a)*( b-points[2][1] ) - ( points[0][1]-b)*( a-points[2][0] ) );
            double zz=.5*fabs( ( a-points[1][0])*( points[1][1]-points[2][1] ) - ( b-points[1][1])*( points[1][0]-points[2][0] ) );
            if (xx >EPS && yy>EPS && zz>EPS && fabs( xx+yy+zz-totalArea) <EPS   )
                return true;
            else
             return false;


        }
        return false;
    }

}fig[sz];

int main(){
    freopen("in.txt","r",stdin);

    char st[2];
    int total;
    double pointX,pointY;

    while (scanf("%s",st)!=EOF){
        if (st[0]=='r'){
            fig[0].state=RECTANGLE;
            scanf("%lf %lf %lf %lf",&fig[0].upperLeft_x,&fig[0].upperLeft_y,&fig[0].lowerRight_x,&fig[0].lowerRight_y);
        }
        else if (st[0]=='c'){
            fig[0].state=CIRCLE;
            scanf("%lf %lf %lf",&fig[0].center_x,&fig[0].center_y,&fig[0].radius);
        }
        else if (st[0]=='t'){
            fig[0].state=TRIANGLE;
            scanf("%lf %lf %lf %lf %lf %lf",&fig[0].points[0][0],&fig[0].points[0][1],&fig[0].points[1][0],&fig[0].points[1][1],&fig[0].points[2][0],&fig[0].points[2][1]);
        }
        for (total=1;scanf("%s",st)!=EOF && st[0]!='*';++total){
            //cout<<"shaon  "<<st[0]<<total<<endl;
            if (st[0]=='r'){
                fig[total].state=RECTANGLE;
                scanf("%lf %lf %lf %lf",&fig[total].upperLeft_x,&fig[total].upperLeft_y,&fig[total].lowerRight_x,&fig[total].lowerRight_y);
            }
            else if (st[0]=='c'){
                fig[total].state=CIRCLE;
                scanf("%lf %lf %lf",&fig[total].center_x,&fig[total].center_y,&fig[total].radius);
            }
            else if (st[0]=='t'){
                fig[total].state=TRIANGLE;
                scanf("%lf %lf %lf %lf %lf %lf",&fig[total].points[0][0],&fig[total].points[0][1],&fig[total].points[1][0],&fig[total].points[1][1],
                      &fig[total].points[2][0],&fig[total].points[2][1]);
            }

        }
        //printf("%d\n",total);

        bool on=false;
        for (int pointNo=1;cin>>pointX>>pointY && fabs( pointX-9999.9 ) > 0.0001 && fabs( pointY-9999.9 ) > 0.0001 ;++pointNo,on=false){
            for (int i=0;i<total;++i){
                if ( fig[i].check(pointX ,pointY) ){
                    printf("Point %d is contained in figure %d\n",pointNo,i+1);
                    on=true;
                }
            }
            if (!on)
                printf("Point %d is not contained in any figure\n",pointNo);
        }

    }
    return 0;


}

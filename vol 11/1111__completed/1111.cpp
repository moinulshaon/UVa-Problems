#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>


using namespace std;

#define SIZE 105

const int INF=1000000000;
const double PI=acos(-1);

struct mathv{
    mathv(){x=0;y=0;}
    mathv(double a,double b){x=a;y=b;}
    double x,y;

    mathv operator + (mathv & p){
        mathv tmp( x+p.x,y+p.y );
        return tmp;
    }
    mathv operator - (mathv & p){
        mathv tmp( x-p.x,y-p.y );
        return tmp;
    }

};

double dot2D(mathv v1, mathv v2){
    return v1.x * v2.x + v1.y * v2.y;
}
double cross2D(mathv v1, mathv v2){
    return v1.x * v2.y - v1.y * v2.x;
}

double length2D(mathv& v){
    return sqrt(v.x * v.x + v.y * v.y);
}


bool cmp(const mathv& a, const mathv& b){
    if ( fabs(a.y-b.y) > 1e-6 ){
        return a.y<b.y;
    }else{
        return a.x<b.x;
    }
}

int convexHull(mathv points[],mathv convexPoints[],  int n){
    sort(points, points+n, cmp);
    int m = 0;
    for(int i = 0; i < n; i++){
        while(m >= 2 && cross2D(convexPoints[m-2]- convexPoints[m-1],convexPoints[m-2]- points[i]) <= 0)
            m--;
        convexPoints[m++] = points[i];
    }
    for(int i = n-2, t = m+1; i >= 0; i--){
        while(m >= t && cross2D(convexPoints[m-2]- convexPoints[m-1],convexPoints[m-2]- points[i]) <= 0)
            m--;
        convexPoints[m++] = points[i];
    }
    return m-1;
}

mathv pp[SIZE];
mathv hull[SIZE];
double ans;
int podal[2];

void check( mathv *point,int len ){

    double ymin=INF,ymax=-INF;

    for (int i=0;i<len;++i){
        if ( fabs(point[i].y-ymin)<1e-6 ){
            if ( point[i].x>point[ podal[0] ].x ){
                podal[0]=i;
            }
        }
        else if ( point[i].y <ymin ){
            ymin=point[i].y;
            podal[0]=i;
        }

        if ( fabs(point[i].y-ymax)<1e-6 ){
            if ( point[i].x<point[ podal[1] ].x ){
                podal[1]=i;
            }
        }
        else if ( point[i].y >ymax ){
            ymax=point[i].y;
            podal[1]=i;
        }
    }
    //printf("%lf %lf\n",ymax,ymin);
    ans=min(ans,ymax-ymin);
}

double angleinradian( mathv a ){
    return atan( fabs(a.y/a.x) );
}


void rotate( double angle,int len ){
    double ttx,tty;
    for (int i=0;i<len;++i){
        ttx=hull[i].x;
        tty=hull[i].y;

        hull[i].x=ttx*cos( angle )+tty*sin( angle );
        hull[i].y=tty*cos( angle )-ttx*sin( angle );
    }
}

int main(){
    freopen("in.txt","r",stdin);
    int node;

    for (int kk=1;scanf("%d",&node)==1  && node;++kk){
        for (int i=0;i<node;++i){
            scanf("%lf %lf",&pp[i].x,&pp[i].y);
        }

        int m=convexHull(pp,hull,node);

        ans=INF;
        for (int i=0;i<=4*m;++i){
            check( hull,m );
            rotate( min( angleinradian( hull[ podal[0] ]-hull[ (podal[0]+1)%m ] ),
                        angleinradian( hull[ podal[1] ]-hull[ (podal[1]+1)%m ] ) ) , m );
        }
        printf("Case %d: %.2lf\n",kk,ans);
    }
    return 0;

}

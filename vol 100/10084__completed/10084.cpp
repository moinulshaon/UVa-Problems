#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

const double EPS = 1e-6;

typedef pair<int,int> pint;
typedef map<int,int> mint;

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

bool cmp(const mathv& a, const mathv& b){
    if ( a.y!=b.y ){
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



double distance2DPointAndPoint(mathv& v1, mathv& v2){
    return sqrt((v2.x - v1.x) * (v2.x - v1.x)+ (v2.y - v1.y) * (v2.y - v1.y));
}

double sq(double x){
    return x*x;
}

struct mathLine{
    mathLine(){a=0;b=0;c=0;}
    mathLine(mathv p,mathv q){
        a = p.y-q.y;
        b = -( p.x-q.x );
        c= p.x*q.y - p.y*q.x;
    }
    mathv getIntersection(mathLine tmp){
        mathv ret;
        double den = a*tmp.b - b*tmp.a;
        ret.x = (b*tmp.c-c*tmp.b)/den;
        ret.y = (c*tmp.a-a*tmp.c)/den;
        return ret;
    }
    bool parallel(mathLine tmp){
        return fabs( a*tmp.b - b*tmp.a )<EPS;
    }

    double a,b,c;
};

mathLine getPerMidLine(mathv p,mathv q){
    mathLine tmp;
    tmp.a = p.x-q.x;
    tmp.b = p.y-q.y;
    tmp.c = -( sq(p.y)-sq(q.y) + sq(p.x)- sq(q.x) )/2;
    return tmp;
}

#define SIZE 10000
mathv final[SIZE];
int cnt = 0;



void calc( mathv start ,mathv dest,int hot ){

    //cout<<start.x<<" "<<start.y<<endl;
    //cout<<dest.x<<" "<<dest.y<<endl;

    mathv save[SIZE];
    int ccc= 0;

    for (int i=0;i<cnt;++i){
        if ( hot>0 ){
            if ( distance2DPointAndPoint( start,final[i] ) > distance2DPointAndPoint( dest,final[i] ) ){
                save[ccc++] = final[i];
            }
        }else{
            if ( distance2DPointAndPoint( start,final[i] ) < distance2DPointAndPoint( dest,final[i] ) ){
                save[ccc++] = final[i];
            }
        }
    }

    mathLine cut= getPerMidLine(start,dest);

    for (int i=0;i<cnt;++i){
        mathv x = final[i];
        mathv y = final[ (i+1)%cnt ];

        mathLine another(x,y);

        if ( cut.parallel(another) ){
            continue;
        }

        mathv inter = cut.getIntersection(another);


        if ( fabs(  fabs( x.x-inter.x ) + fabs( y.x-inter.x ) -fabs( x.x-y.x ) ) > EPS )continue;
        if ( fabs(  fabs( x.y-inter.y ) + fabs( y.y-inter.y ) -fabs( x.y-y.y ) ) > EPS )continue;

        save[ccc++] = inter;
    }


    cnt = convexHull( save,final,ccc );

}

double areaPolygon(mathv points[],int np) {

    double area = 0;
    for(int i = 0; i < np; i++) {
        area += points[i].x * points[ (i+1)%np ].y - points[i].y * points[(i+1)%np].x;
    }
    return fabs(area)/2;
}

int main(){

    FRO


    final[cnt++]=mathv(0,0);
    final[cnt++]=mathv(10,0);
    final[cnt++]=mathv(10,10);
    final[cnt++]=mathv(0,10);

    double area=areaPolygon( final,cnt );

    mathv given;
    mathv prv(0,0);
    char str[20];
    while ( scanf("%lf %lf %s",&given.x,&given.y,str)==3 ){

        if ( str[0] == 'C' ){
            if ( fabs(given.x-prv.x)>EPS || fabs(given.y-prv.y)>EPS  ){
                calc(prv,given,-1);
                area = areaPolygon( final,cnt );
            }
        }else if ( str[0] == 'H' ){
            if ( fabs(given.x-prv.x)>EPS || fabs(given.y-prv.y)>EPS  ){
                calc(prv,given,1);
                area = areaPolygon( final,cnt );
            }
        }else{
            if ( fabs(given.x-prv.x)>EPS || fabs(given.y-prv.y)>EPS  ){
                    area = 0;
            }
        }


        prv = given;

        printf("%.2lf\n",area);
        if(area<EPS) break;


    }

    while ( scanf("%lf %lf %s",&given.x,&given.y,str)==3 ){
        printf("%.2lf\n",0);
    }


    return 0;
}

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

double distance2DPointAndPoint(mathv v1, mathv v2){
    return sqrt( (v2.x - v1.x) * (v2.x - v1.x)+ (v2.y - v1.y) * (v2.y - v1.y) );
}

const double PI= acos(-1);

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        mathv x,p;
        p.x= p.y = 0;
        double r;
        scanf("%lf %lf %lf",&p.x,&p.y,&r);

        printf("%.2lf %.2lf\n",r-distance2DPointAndPoint( p,x ) ,r+distance2DPointAndPoint(p,x) );

    }


    return 0;
}

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

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

const double PI=acos(-1);
const double root3=sqrt(3);

int main(){

    double r;

    while( scanf("%lf",&r)==1 ){

        double v1=PI*r*r/4;
        double v2=r*r;
        double v3=r*r*( PI/3- root3/4);

        //cout<<v1<<' '<<v2<<' '<<v3<<endl;

        double x=  2*v1-v2-v3;
        double y= -3*v1+v2+2*v3;
        double z=  4*v1-v2-4*v3;

        printf("%.3lf %.3lf %.3lf\n",fabs(-z),fabs(-4*y),fabs(-4*x) );

    }


    return 0;
}

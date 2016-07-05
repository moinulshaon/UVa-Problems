#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define sz 100100

#define INF 10010

typedef long long LL;

struct ppp{
    double x,y;
}points[sz];
int stk[sz];


bool cmp(const ppp&a,const ppp&b){
    return a.x<b.x;
}

double dist(int a,int b){
    return sqrt( double( points[a].x-points[b].x )*( points[a].x-points[b].x )+
                double( points[a].y-points[b].y )*( points[a].y-points[b].y ) );
}


int top;
double closest(int a,int b){
    double tmp;
    if (a==b)return INF;
    else if ( b-a== 1 ){
        return dist(a,b);
    }
    int m=(a+b)/2;

    double left=closest(a,m);
    double right=closest(m+1,b);

    double d=min(left,right);
    top=0;
    for(int i=m;i>=a && fabs(points[i].x-points[m].x)<d;i--)
		stk[top++]=i;

    for(int i=m+1;i<b && fabs(points[i].x-points[m].x)<d;i++)
		stk[top++]=i;

    for (int i=0;i<top;++i){
        for (int j=i+1;j<top;++j){
            tmp=dist(stk[i],stk[j]);
            if ( tmp<d ){
                d=tmp;
            }
        }
    }
    return d;
}


int main(){
    freopen("in.txt","r",stdin);
    int total;
    while (scanf("%d",&total)==1 && total){
        for (int i=0;i<total;++i){
            scanf("%lf %lf",&points[i].x,&points[i].y);
        }
        sort(points,points+total,cmp);

        double rr=closest(0,total-1);
        if ( rr>10000 ){
            printf("INFINITY\n");
        }else{
            printf("%.4lf\n",rr);
        }
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

int n,person;
double volume[10100];
const double PI=acos(-1);

bool isPossible(double x){
    int p=0;
    for (int i=0;i<n;++i){
        p+=int(volume[i]/x);
    }
    if ( p>=person ){
        return true;
    }else{
        return false;
    }
}

double bsearch(){
    double low=0,high=volume[n-1];
    double mid=0;
    while ( fabs(high-low)>1e-6 ){
        mid=(low+high)/2;
        bool is=isPossible(mid);
        if (is) low=mid;
        else high=mid;
        //printf("%lf %lf %lf\n",low,high,mid);
    }
    return mid;
}


int main(){
    int kase;
    scanf("%d",&kase);

    while (kase--){
        scanf("%d %d",&n,&person);
        person++;
        for (int i=0;i<n;++i){
            scanf("%lf",&volume[i]);
            volume[i]=PI*volume[i]*volume[i];
        }
        sort(volume,volume+n);
        printf("%.4lf\n",bsearch());
    }
    return 0;
}


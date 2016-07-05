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

typedef pair<double,double> pint;

pint plane[10];
int order[10];


int total;
bool ispos( double dif ){

    double last=plane[ order[0] ].first;
    double nxt;
    for (int i=1;i<total;++i){
        nxt=last+dif;
        if ( nxt<=plane[ order[i] ].second ){
            last=max( nxt,double(plane[ order[i] ].first) );
        }else{
            return false;
        }
    }

    return last <= plane[ order[total-1] ].second ;
}

int main(){
    FRO
    int kase=1;

    while( scanf("%d",&total)==1 && total ){

        for (int i=0;i<total;++i){
            scanf("%lf %lf",&plane[i].first,&plane[i].second);

            plane[i].first*=60;
            plane[i].second*=60;

            order[i]=i;
        }

        double ans=0;

        do{
            double low=0,high=1030*60;
            while( low+1e-4 <high ){
                double mid=(low+high)/2;
                if ( ispos( mid ) ){
                    ans=max(ans,mid);
                    low=mid+1e-4;
                }else{
                    high=mid-1e-4;
                }
            }

        }while( next_permutation( order,order+total ) );

        double tmp=int(ans+.5);
        printf("Case %d: %d:%0.2d\n",kase++,int(tmp/60),int(tmp)%60 );
    }

    return 0;
}

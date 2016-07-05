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

const double EPS = 1e-5;

double run[25],cyc[25];
int n;
double len;
double func( double rr ){

    double ans = (1<<29);
    for (int i=0;i<n-1;++i){
        ans=min( ans, ( rr/run[i] + (len-rr)/cyc[i] )-
                ( rr/run[n-1] + (len-rr)/cyc[n-1] ) );
    }
    return ans ;
}

int main(){

    FRO

    while ( scanf("%lf",&len) == 1 ){

        len*=3600;


        scanf("%d",&n);
        for (int i=0;i<n;++i){
            scanf("%lf %lf",&run[i],&cyc[i]);
            //cout<<run[i]<<' '<<cyc[i]<<endl;
        }

        double le = EPS,ri = len;
        while ( ri>le+EPS ){

            double one= le + ( ri-le )/3;
            double two= ri - ( ri-le )/3;

            if(  func( one ) > func(two) ){
                ri=two;
            }else{
                le=one;
            }
        }
        //cout<<le<<' '<<func(le)*3600<<endl;

        if ( func(le)<0 ){
            printf("The cheater cannot win.\n");
        }else{
            printf("The cheater can win by %.0lf seconds with r = %.2lfkm and k = %.2lfkm.\n"
                   ,func(le),le/3600,(len-ri)/3600);
        }

    }


    return 0;
}

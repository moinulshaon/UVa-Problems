#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main(){

    double x;

    vector<double> v;

    for (int i=1;i<=101;++i){
        v.push_back( pow(i,3) );
    }

    while (true){
        scanf("%lf",&x);
        if ( x< 1e-6 )return 0;

        int index;
        for (index=0;!( v[index]>x )   ;++index){
            ;
        }


        printf("%.4lf\n",index+(x-v[index-1])/(3*index*index));


    }
    return 0;

}

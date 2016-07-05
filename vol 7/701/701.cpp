#include <cstdio>
#include <cmath>

using namespace std;


int main(){

    int n;
    int limit;
    while ( scanf("%d",&n)==1 ){

        int d=n;

        int digit=0;

        while ( d ){
            d/=10;
            digit++;
        }
        limit=1000000000;
        for (int i=0;i<limit;++i){

            double tmp=i*log10(2);
            if ( int( floor(tmp) )+1 <= digit )continue;

            int tt= pow( 10,tmp-floor(tmp) +digit-1 );

            //printf("%d %lf\n",i,tt);
            if ( tt==n ){
                printf("%d\n",i);
                break;
            }

        }

    }

}

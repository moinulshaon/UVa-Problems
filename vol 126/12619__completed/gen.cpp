#include <cstdio>
#include <cstdlib>
const int mod=1000000;

int main(){
    freopen("in.in","w",stdout);
    int kase=10;
    printf("%d\n",kase);
    for (int i=0;i<kase;++i){
        int n=1000000;
        printf("%d\n",n);
        while(n--){
            int tmp=( 99999 )%mod;
            if ( n%2 )
                printf("%d\n",tmp );
            else
                printf("%d\n",-tmp);
        }
    }
    return 0;
}

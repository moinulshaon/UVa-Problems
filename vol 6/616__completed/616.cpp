#include <cstdio>
#include <cmath>


using namespace std;

void func( int coco ){

    for (int i=sqrt(coco)+1;i>=2;--i){
        int tt=coco;
        bool success=true;
        for (int j=0;j<i;++j){

            if ( (tt-1)%i==0 )
                tt=( tt-(tt-1)/i -1);
            else{
                success=false;
                break;
            }
        }
        if ( success && tt%i==0 ){
            printf("%d coconuts, %d people and 1 monkey\n",coco,i);
            return ;
        }

    }
    printf("%d coconuts, no solution\n",coco);

}

int main(){

    int n;
    while (scanf("%d",&n)==1 && n>=0){
        func(n);
    }
    return 0;


}

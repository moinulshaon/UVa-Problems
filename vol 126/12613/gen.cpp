#include <cstdio>

int main(){

    freopen("in.txt","w",stdout);
    int n=100;


    printf("%d\n",n);
    for (int j=0;j<n;++j){
        for (int i=0;i<50000;++i){
            printf("a");
        }
        printf(" 1000000000\n");
    }


}

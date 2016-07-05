#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int a[2100000];
int b[2100000];
int c[110];
int n;

void countingsort(){
    memset( c,0,sizeof(c) );

    for (int i=0;i<n;++i){
        c[ a[i] ]++;
    }

    for (int i=1;i<101;++i){
        c[i] +=c[i-1];
    }

    for (int i=0;i<n;++i){
        b[ c[ a[i] ]-1 ]=a[i];
        c[ a[i] ]--;
    }

}



int main(){


    while (scanf("%d",&n)==1 && n){
        for (int i=0;i<n;++i)
            scanf("%d",&a[i]);
        countingsort();

        printf("%d",b[0]);
        for (int i=1;i<n;++i){
            printf(" %d",b[i]);
        }
        printf("\n");

    }
    return 0;
}

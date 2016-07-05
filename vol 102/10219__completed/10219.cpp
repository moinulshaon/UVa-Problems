#include <cstdio>
#include <cmath>

using namespace std;

double fact(int a,int b){
    double tt=0;
    for (int i=a;i<=b;++i){
        tt+=log10(i);
    }
    return tt;
}

int main(){

    int n,k;
    while (scanf("%d %d",&n,&k)==2){
        int result=floor(  fact(n-k+1,n)-fact(1,k)  )+1;
        printf("%d\n",result);
    }
    return 0;
}

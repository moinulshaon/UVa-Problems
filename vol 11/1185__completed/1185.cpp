#include <cstdio>
#include <cmath>

using namespace std;

#define sz 10000001

double result[sz];

int main(){
    for (int i=1;i<sz;++i){
        result[i]=result[i-1]+log10(i);
    }
    int n,kase;
    scanf("%d",&kase);
    while (kase--){
        scanf("%d",&n);
        printf("%d\n",(int)floor(result[n])+1 );
    }
    return 0;
}

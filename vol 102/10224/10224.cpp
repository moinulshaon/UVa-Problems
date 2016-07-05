#include <cstdio>
#include <cmath>

using namespace std;

int factorial(int n){
    if (n==0)return 1;
    return n*factorial(n-1);
}

double f[13];
double result[13];

int main(){
    for (int i=0;i<13;++i){
        f[i]=factorial(i);
    }
    result[0]=1;

    for (int i=1;i<13;++i){
        if (i%2==1){
            result[i]=result[i-1]- ( 1/f[i] );
        }else{
            result[i]=result[i-1]+ ( 1/f[i] ) ;
        }

    }
    for (int i=1;i<13;++i){
        result[i]*=f[i];
    }

    int kase,n;
    scanf("%d",&kase);

    while (kase--){
        scanf("%d",&n);
        printf("%d/%d\n",int(result[n]+.1),int(f[n]));
    }
    return 0;

}

#include <cstdio>

using namespace std;

double cc[3100];

int main(){
    freopen("in.txt","r",stdin);

    int kase,n;
    scanf("%d",&kase);
    double x,y;
    while (kase--){
        scanf("%d %lf %lf",&n,&x,&y);

        for (int i=0;i<n;++i){
            scanf("%lf",&cc[i]);
        }

        double sum=0;

        for (int i=n; i ;--i){
            sum+=i*cc[ n-i ];
        }

        printf("%.2lf\n",(n*x+y-2*sum)/(n+1) );

        if ( kase )printf("\n");

    }

}

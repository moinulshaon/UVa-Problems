#include <cstdio>
#include <cmath>

using namespace std;

int main(){

    int kase,n,a;
    double p;
    scanf("%d",&kase);

    while (kase--){

        scanf("%d %lf %d",&n,&p,&a);

        double result,tmp=1;

        result=p*pow(1-p,a-1);
        //printf("%lf %lf\n",tmp,result);
        for (int i=1;tmp>1e-9;++i){

            tmp=p*pow(1-p,n*i+a-1);
            result+=tmp;
            //printf("%lf %lf\n",tmp,result);
            //getchar();
        }

        printf("%.4lf\n",result);


    }
    return 0;

}

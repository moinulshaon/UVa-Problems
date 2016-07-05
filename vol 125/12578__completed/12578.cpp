#include <cstdio>
#include <cmath>

using namespace std;

const double PI=acos(-1);

int main(){

    int kase;
    scanf("%d",&kase);

    while(kase--){
        int len;
        scanf("%d",&len);
        double r=len/5.0;
        double wid=len*6.0/10.0;

        double red=PI*r*r;

        printf("%.2lf %.2lf\n",red,len*wid-red);
    }
    return 0;
}

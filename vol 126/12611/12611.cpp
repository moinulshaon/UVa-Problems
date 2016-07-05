#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        double r;
        scanf("%lf",&r);

        double len=r/.2;

        double right=len*.55;
        double left=len*.45;

        double width=len*.6;

        printf("Case %d:\n",kk);

        printf("%.0lf %.0lf\n",-left,width/2);
        printf("%.0lf %.0lf\n",right,width/2);
        printf("%.0lf %.0lf\n",right,-width/2);
        printf("%.0lf %.0lf\n",-left,-width/2);

    }
    return 0;
}

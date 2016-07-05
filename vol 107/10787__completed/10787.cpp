#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){

    int kase;
    scanf("%d",&kase);

    int amin,amax,bmin,bmax,mmin,mmax;

    for (int kk=1;kase--;++kk){
        int result=0;

        scanf("%d %d %d %d %d %d",&amin,&amax,&bmin,&bmax,&mmin,&mmax);

        for (int i=mmin;i<=mmax;++i){
            for (int j=bmin;j<=bmax;++j){
                result+=( abs(2*j)%i==0)?1:0;
            }
        }
        //printf("%d\n",result);
        result*=amax-amin+1;

        printf("Case %d: %d\n",kk,result);
    }
    return 0;

}

#include <cstdio>
#include <cmath>

using namespace std;

int absolute(int a){
    return (a<0)?-a:a;
}

int main(){
    int a,b;

    while (scanf("%d %d",&a,&b)==2){

        printf("%d %d ",a,b);

        int diff=absolute(a-b);
        if (diff==0){
            printf("12:00\n");
            continue;
        }


        double result=(43200 % diff ) * 24;
        result=result/diff;

        double fraction=result-floor(result);
        fraction*=60;

        if ( result < 1 )
            result=12;

        printf("%02d:%02.0lf\n",int(result),fraction);

    }
    return 0;

}

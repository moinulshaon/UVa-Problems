#include <cstdio>
#include <cmath>

using namespace std;

double round( int a,int b,int left ){
    if ( !left )return 0;

    if ( !a )return 0;
    else if  ( !b )return 0;

    if ( a>=b ){
        return  1+.5*round(a-b,b+b,left-1);
    }else{
        return 1+.5*round(a+a,b-a,left-1);
    }
}
double probablity( int a,int b,int left ){
    if ( !left )return 0;

    if ( !a )return 0;
    else if  ( !b )return 1;

    if ( a>=b ){
        return .5+.5*probablity(a-b,b+b,left-1);
    }else{
        return .5*probablity(a+a,b-a,left-1);
    }


}

int main(){

    int kase;
    scanf("%d",&kase);
    int a,b;
    for (int kk=1;kase--;++kk){
        scanf("%d %d",&a,&b);


        printf("Case %d: %lf %lf\n",kk,round(a,b,30),probablity(a,b,30));
    }
    return 0;

}

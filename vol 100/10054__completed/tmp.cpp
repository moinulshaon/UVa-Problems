#include <cmath>
#include <cstdio>

using namespace std;

double dis( int a,int b,int c,int d ){
    return sqrt( (a-c)*(a-c)+(b-d)*(b-d) );
}

int main(){

    for (int i=2;i<=100;++i){
        printf("%d %lf\n",i,dis(i,i,4,3));
    }

}

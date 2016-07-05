#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

int fact( int n,int p ){
    int cnt=0;
    while( n ){
        cnt+=n/p;
        n=n/p;
    }
    return cnt;
}

int primesending( int n,int x ){
    int cnt=0;
    while( n ){
        n+= n/2 +fa
    }

}

int main(){

    int n,m;

    while( scanf("%d %d",&n,&m)==2 ){

        int f2=fact(n,2)-fact(n-m,2);
        int f3=fact(n,3)-fact(n-m,3);
        int f5=fact(n,5)-fact(n-m,5);
        int f7=fact(n,7)-fact(n-m,7);
        int f9=fact(n,9)-fact(n-m,9);

        //printf("%d %d %d %d\n",f2,f3,f5,f7);

        int ans=1;
        if ( f5>f2 ){
            printf("5\n");
        }else{
            f2-=f5;


            f2=f2%4+2;
            f3=f3%4+2;

            f7=f7%4+2;
            f9=f9%4+2;

            //printf("%d %d %d %d\n",f2,f3,f5,f7);


            for (int i=0;i<f2;++i){
                ans=( ans*2 )%10;
            }
            for (int i=0;i<f3;++i){
                ans=( ans*3)%10;
            }

            for (int i=0;i<f7;++i){
                ans=( ans*7)%10;
            }
            for (int i=0;i<f9;++i){
                ans=( ans*9 )%10;
            }
        }
        printf("%d\n",ans%10);
    }


    return 0;
}


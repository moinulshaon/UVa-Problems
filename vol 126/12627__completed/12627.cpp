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

LL func( int k,int r ){
    if ( r<=0 ){
        return 0;
    }
    if ( k==0 ){
        return 1;
    }

    if ( r<= (1<<(k-1) ) ){
        return 2*func( k-1,r );
    }else{
        return 2*LL( pow(3,k-1)+1e-6 )+func( k-1, r-(1<<(k-1) ) );
    }
}

int main(){

    int kase;

    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        int k,a,b;
        scanf("%d %d %d",&k,&a,&b);
        //scanf("%d %d",&k,&a);
        //printf("%d\n",func(k,a));

        printf("Case %d: %lld\n",kk,func(k,b)-func(k,a-1));
    }


    return 0;
}

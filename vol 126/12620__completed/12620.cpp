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

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

int cycle;
LL sum[500],tmp[500];

void pre(){

    int f1=1,f2=1;



    cycle=0;

    tmp[++cycle] = 1;
    tmp[++cycle] = 1;

    do{

        int f3=(f1+f2)%100;

        tmp[++cycle]= f3 ;
        f1=f2;
        f2=f3;


    }while ( f1!=1 || f2 !=1 );

    tmp[--cycle]-= 1 ;
    --cycle;

    sum[0]=tmp[0]=0;
    for (int i=1;i<=cycle;++i){
        sum[i]+= sum[i-1]+tmp[i];
        //printf("ss %lld\n",sum[i]);
    }

}


LL func(LL x){
    return x/(cycle) * sum[cycle] + sum[x%cycle];
}



int main(){
    FRO

    pre();
    //cout<<cycle<<' '<<sum[cycle]<<endl;
    int kase;
    scanf("%d",&kase);

    while (kase--){
        LL n,m;
        scanf("%lld %lld",&n,&m);

        printf("%lld\n",func(m)-func(n-1));
    }


    return 0;
}

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
#include <bitset>
#include <ctime>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

LL overflowmod(LL a,LL b,LL c){
    LL x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

LL BigMod ( LL a, LL p, LL m ){
    LL res = 1;
    LL x = a;

    while ( p ){
        if ( p & 1 ){
            res = overflowmod( res , x , m );
        }
        x = overflowmod( x , x , m );
        p = p >> 1;
    }

    return res % m;
}


bool ispro(LL p,int iteration){
    if(p<2){
        return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    LL s=p-1;
    while(s%2==0){
        s/=2;
    }
    for(int i=0;i<iteration;i++){
        LL a=rand()%(p-1)+1;
        LL tmp=s;
        LL mod=BigMod(a,tmp,p);
        while( tmp!=p-1 && mod!=1 && mod!=p-1){
            mod=overflowmod(mod,mod,p);
            tmp *= 2;
        }
        if(mod!=p-1 && tmp%2==0){
            return false;
        }
    }
    return true;
}



#define LIM 2


LL rho(LL n, int c){
    LL x, y, d, i=1, k=2;
    srand(time(0));
    x = rand()%(n-1) + 1;
    y = x;
    while(true){
        i++;
        x = (overflowmod(x,x,n) + c) % n;
        d = __gcd(y-x, n);
        if(1<d && d<n) return d;
        if(y ==  x) return n;
        if(i == k){
            y = x;
            k <<= 1;
        }
    }
}


map<LL,int> mp;

void findfactor( LL n ,int k ){

    if ( n==1 )return ;

    if ( ispro( n,LIM ) ){
        mp[ n ]++;
        return ;
    }

    LL p = n;
    while(p >= n)
        p = rho(p,k--);
    findfactor(p, k);
    findfactor(n/p, k);
}

int main(){
    //FRO

    int kase;
    scanf("%d",&kase);
    LL n;
    while(kase-- && scanf("%lld",&n)==1 ){
        printf("%lld =",n);


        if ( ispro( n,LIM ) ){
            printf(" %lld\n",n);
            continue;
        }else{
            mp.clear();

            findfactor( n,500 );

            bool on=false;
            for (map<LL,int>::iterator it= mp.begin();it!= mp.end();++it){
                if (on)printf(" *");
                printf(" %lld",it->first);
                if ( it->second > 1 ){
                    printf("^%d",it->second);
                }
                on=true;
            }
            printf("\n");
        }
    }

    return 0;
}

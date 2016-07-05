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
#include <climits>

using namespace std;

typedef unsigned long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

LL dp[45];

LL calc(LL x){

    if ( x == 0 )return 0;

    LL sum = 0;
    int base = 0;
    for (int i=43;i>=0;--i){
        if ( (1LL<<i)&x ){
            sum+= dp[i+1]<<base;
            base++;
        }
    }
    return sum;
}

int main(){

    FRO

    for (int i=1;i<45;++i){
        for (int j=i-1,k=0;j>=0;--j,++k){
            dp[i] += dp[j]<<k;
        }
        dp[i] += 2;
    }

    LL low , high ;
    while ( scanf("%llu %llu",&low,&high)==2 ){
        if ( low == 0 && high == 0 )break;

        if ( low == 0 ){
            printf("%llu\n",calc(high)+1 );
        }else{
            printf("%llu\n",calc(high)-calc(low-1) );
        }
    }


    return 0;
}

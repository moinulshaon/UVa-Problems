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

int arr[15];
int n;
int dp[1<<15+3];

int Set(int N,int pos){
    return N=N | (1<<pos);
}
int Reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool Check(int N,int pos){
    return (bool)(N & (1<<pos));
}


int func( int state ){

    if ( dp[state] != -1 )return dp[state];

    int x=0;
    for (int i=0;i<n;++i){
        for (int j=i+1;j<n;++j){
            for (int k=j+1;k<n;++k){
                if ( Check( state,i )==0 &&  Check( state,j )==0  && Check( state,k )==0 ){
                    x=max( x, ( ( arr[i]+arr[j]+arr[k] >=20 )?1:0 ) + func( Set( Set( Set( state,i ),j),k) ) );
                }
            }
        }
    }
    return dp[state]=x;
}

int main(){
    FRO
    int kase=1;
    while( scanf("%d",&n)==1 && n ){
        for (int i=0;i<n;++i){
            scanf("%d",&arr[i]);
        }

        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",kase++,func(0));

    }


    return 0;
}

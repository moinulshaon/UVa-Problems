#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int set(int N,int pos){
    return N=N | (1<<pos);
}
int reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool check(int N,int pos){
    return (bool)(N & (1<<pos));
}

int dp[1<<14][300][3];
int n;
int cost[3][14];


int func( int state,int sum,int prv ){

    if ( sum>280 )return -1;
    else if ( state==(1<<n)-1 ) return 0;
    else if ( prv!=-1 && dp[state][sum][prv]!=-1 )return dp[state][sum][prv];

    int rr=0;
    for (int i=0;i<3;++i){
        if ( i!= prv ){

            for (int j=0;j<n;++j){
                if ( check(state,j)==0 ){
                    rr=max( rr, 1+func( set( state,j) , sum+cost[i][j] , i ) );
                    //printf("working %d\n",1+func( set( state,j) , sum+cost[i][j] , i ));
                }
            }
        }
    }
    return dp[state][sum][prv]=rr;
}


int main(){
    freopen("in.txt","r",stdin);
    int kase;
    scanf("%d",&kase);

    while ( kase-- ){
        scanf("%d",&n);
        for (int i=0;i<3;++i){
            for (int j=0;j<n;++j){
                scanf("%d",&cost[i][j]);
            }
        }
        for (int i=0;i<= (1<<n);++i){
            for (int j=0;j<300;++j){
                for (int k=0;k<3;++k){
                    dp[i][j][k]= -1;
                }
            }
        }
        printf("%d\n",func(0,0,-1));
    }
    return 0;
}

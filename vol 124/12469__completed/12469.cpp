#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char dp[1001][1001][2];

char func(int x,int prv,int p){
    //printf("%d %d %d\n",x,prv,p);
    if ( x<1 )return 0;

    if ( dp[x][prv][p] != -1 )return dp[x][prv][p];
    char rr=0;
    if ( prv==0 ){
        for (int i=x-1;i>1 && !rr ;--i){
            rr=rr | ( !func( i,x-i ,!p) );
        }
    }else{
        for (int i=1;x-i>=0 && i<=2*prv && !rr ;++i){
            rr=rr | ( !func( x-i,i ,!p) );
        }
    }
    return dp[x][prv][p]=rr;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    while( scanf("%d",&n)==1 && n ){
        if ( func(n,0,0) ){
            printf("Alicia\n");
        }else{
            printf("Roberto\n");
        }
    }
    return 0;
}

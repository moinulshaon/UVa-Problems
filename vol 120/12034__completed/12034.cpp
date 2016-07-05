#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int mod=10056;
#define SIZE 1001

int ncr[SIZE][SIZE];

int func( int n,int r ){
    if ( ncr[n][r]!=-1 )return ncr[n][r];

    if ( r==0 || r== n){
        return ncr[n][r]=ncr[n][n-r]=1;
    }
    return ncr[n][r]=ncr[n][n-r]=( func( n-1,r-1 )+func( n-1,r ) )%mod;
}

int result[SIZE];

int main(){
    memset(ncr,-1,sizeof(ncr));
    for (int i=0;i<SIZE;++i){
        for (int j=0;j<=i;++j){
            func(i,j);
        }
    }
    result[0]=1;
    for (int i=1;i<SIZE;++i){
        for (int j=1;j<=i;++j){
            result[i]= ( result[i]+ ncr[i][j]*result[i-j] ) %mod;
        }
    }
    //freopen("in.txt","r",stdin);
    int n,kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;kk++){
        scanf("%d",&n);
        printf("Case %d: %d\n",kk,result[n]);
    }
    return 0;
}

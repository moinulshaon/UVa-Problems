#include <cstring>
#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

int dp[33][33*21][33*21];
int n;
int arr[33];
int sum;

int func(int to,int a,int b){

    if ( to==n ){
        return max(max(a,b),sum-a-b) - min(min(a,b),sum-a-b);
    }

    if ( dp[to][a][b]!=-1 )return dp[to][a][b];

    int mx=INT_MAX;

    mx=min( mx,func( to+1,a+arr[to],b ) );
    mx=min( mx,func( to+1,a,b+arr[to] ) );
    mx=min( mx,func( to+1,a,b ) );

    return dp[to][a][b]=mx;
}

int main(){
    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d",&n);
        sum=0;
        for (int i=0;i<n;++i){
            scanf("%d",&arr[i]);
            sum+=arr[i];
        }


        for (int i=0;i<=n;++i){
            for (int j=0;j<=sum;++j){
                for (int k=0;k<=sum;++k){
                    dp[i][j][k]= -1;
                }
            }
        }

        printf("Case %d: %d\n",kk,func(0,0,0));

    }
    return 0;
}

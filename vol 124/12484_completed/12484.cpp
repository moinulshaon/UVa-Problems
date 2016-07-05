#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long dp[10101][10101];
long long sum[10101];
long long arr[10101];

int main(){
    //freopen("in.txt","r",stdin);
    int n;
    while ( scanf("%d",&n)==1 ){

        sum[0]=0;
        for (int i=1;i<=n;++i){
            scanf("%lld",&arr[i]);
            sum[i]=sum[i-1]+arr[i];
        }
        //memset(dp,0,sizeof(dp));
        for (int i=n;i>0;--i){
            for (int j=i;j<=n;++j){
                //printf("%d %d\n",i,j);
                if ( i+1 >n ){
                    //printf("failed %d %d\n",i,j);
                    dp[i+1][j]=0;
                }
                if ( j-1<i ){
                    dp[i][j-1]=0;
                }

                dp[i][j]=max( arr[i]-dp[i+1][j]+sum[j]-sum[i] ,
                                    arr[j]-dp[i][j-1]+sum[j-1]-sum[i-1]  );

            }
        }
        //memset(dp,-1,sizeof(dp));
        //printf("%lld\n",func(1,n));
        printf("%lld\n",dp[1][n]);
    }
    return 0;
}

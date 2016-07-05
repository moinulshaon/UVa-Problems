#include<iostream>
#include <cstdio>

using namespace std;



int dp[10305],w[305],v[305];

int main(){

    int V,n,i,j,k;

    while(scanf("%d%d",&V,&n)!=EOF){
        for(i=1;i<=n;i++){
            scanf("%d%d",&w[i],&v[i]);
        }

        for(i=0;i<=10250;i++) dp[i]=-0x3ffff;

        dp[0]=0;

        for(i=1;i<=n;i++){
            for(j=10250;j>=w[i];j--){
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
            }
        }

        int ans=0;

        for(i=0;i<10201;i++){
            if((i>2000&&i<=V+200)||i<=V) {
                ans=max(ans,dp[i]);
            }
        }

        printf("%d\n",ans);
     }
    return 0;
}

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

LL dp[450*103];
int arr[103];
int total;


int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    while(kase--){
        scanf("%d",&total);

        int sum=0;
        for (int i=0;i<total;++i){
            scanf("%d",&arr[i]);
            sum+=arr[i];
        }
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for (int i=0;i<total;++i){
            for (int j=sum;j>=0;--j){
                if ( j-arr[i]>=0 )
                    dp[ j ] |= dp[ j-arr[i] ]<<1;
                else
                    break;
            }
        }

        LL check=1LL << (total/2);

        int ans=0;
        int mid=sum/2;
        for (int i=0;i<=sum;++i){
            if ( mid-i>=0 && (dp[mid-i] & check) ){
                ans=mid-i;
                break;
            }
            if (mid+i<=sum && (dp[mid+i] & check) ){
                ans=mid+i;
                break;
            }
        }

        printf("%d %d\n",min(ans,sum-ans),max( ans,sum-ans ));

        if ( kase ){
            printf("\n");
        }
    }
    return 0;
}

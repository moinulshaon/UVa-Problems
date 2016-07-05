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

typedef long long LL;

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

#define SIZE 1010

int give[SIZE];
int arr[SIZE];
int inter[SIZE];

int save[SIZE];

int n;

void LIS(int seq[],int save[]){

    for (int i=0;i<=n;++i){
        inter[i]=INT_MIN;
    }
    int lis=0,low,high,mid;
    for (int i=1;i<=n;++i){
        low=0;
        high=lis;

        while (low<=high){
            mid=(low+high)>>1;
            if (seq[i] <= inter[mid] )high=mid-1;
            else low=mid+1;
        }

        inter[low]=seq[i];

        save[i]=low;
        if ( low>lis )lis=low;
    }
}

LL dp[SIZE][SIZE];
int mid[SIZE][SIZE];

LL sum[SIZE];

int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%d",&n);

        for (int i=1;i<=n;++i){
            scanf("%d",&give[i]);
        }

        LIS( give,arr );
        reverse( give+1,give+n+1 );
        LIS( give,save );

        sum[0] = 0;
        for (int i=1;i<=n;++i){
            arr[i] += save[n-i+1]-1;
            sum[i] = sum[i-1] + arr[i];
        }

        for (int len=1;len<=n;++len){
            for (int i=1;i+len-1<=n;++i){
                int j=i+len-1;
                if ( len == 1 ){
                    dp[i][j] = 0;
                    mid[i][j] = i;
                    continue;
                }

                dp[i][j] = (1LL<<55);
                for (int cut = mid[i][j-1]; cut<= mid[i+1][j] && cut<j ; ++cut ){
                    LL cost = dp[i][cut] + dp[cut+1][j] + sum[j]-sum[i-1];
                    if ( cost<dp[i][j] ){
                        dp[i][j] = cost;
                        mid[i][j] = cut;
                    }
                }
            }
        }

        printf("Case %d: %lld\n",kk,dp[1][n]);
    }


    return 0;
}

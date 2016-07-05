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

#define SIZE 255

int dp[SIZE][SIZE];
int mod = 10000007;
int arr[SIZE];

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;++i){
            scanf("%d",&arr[i]);
        }

        CLR(dp);

        int ans = 0;
        for (int i=0;i<n;++i){
            for (int j=0;j<i;++j){
                dp[i][j] = 1;
                for (int k=0;k<j;++k){
                    if ( arr[i]-arr[j] == arr[j]-arr[k] )
                        dp[i][j] = ( dp[i][j]+ dp[j][k] )%mod;
                }
            }
        }

        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                ans = ( ans+dp[i][j] )%mod;
            }
        }
        ans+= n;
        ans%=mod;
        if ( ans<0 )ans+=mod;
        printf("Case %d: %d\n",kk,ans);
    }


    return 0;
}

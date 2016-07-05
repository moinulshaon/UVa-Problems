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


int arr[SIZE][SIZE];
int dp[SIZE][SIZE];

int pre[SIZE];

int main(){

    FRO

    int n;
    while ( scanf("%d",&n) == 1 && n ){
        for (int i=0;i<n;++i){
            for (int j=0;j<=i;++j){
                scanf("%d",&arr[i-j][j]);
            }
        }
/*
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                printf("%3d",arr[i][j]);
            }printf("\n");
        }printf("\n");
*/
        int tmp = 0 ;
        for (int i=0;i<n;++i){
            tmp += arr[0][i];
            dp[0][i] = tmp;
        }

        for (int i=1;i<n;++i){
            pre[n-i] = dp[i-1][n-i];
            for (int j=n-i-1;j>=0;--j){
                pre[j] = max( pre[j+1] , dp[i-1][j] );
            }
            int sum = 0;
            for (int j=0;j<n-i;++j){
                sum+= arr[i][j];
                dp[i][j] = pre[j] + sum;
            }
        }

        int ans = 0;
        for (int i=0;i<n;++i){
            for (int j=0;j<n-i;++j){
                ans = max( ans ,dp[i][j] );
            }
        }
        printf("%d\n",ans);
/*
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                printf("%3d",dp[i][j]);
            }printf("\n");
        }
*/
    }


    return 0;
}

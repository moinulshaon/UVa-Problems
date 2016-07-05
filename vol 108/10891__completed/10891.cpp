#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

#define SIZE 105

int dp[SIZE][SIZE];
bool vis[SIZE][SIZE];
int arr[SIZE];
int sum[SIZE];

int func(int left,int right){
    if ( vis[left][right] )return dp[left][right];
    if ( left==right ){

        vis[left][right]=true;
        return dp[left][right]=arr[left];
    }

    //printf("%d %d\n",left,right);
    //getchar();

    int rr= INT_MIN;
    for (int i=left+1;i<=right;++i){
        rr=max(  rr,sum[right]-sum[left-1]-func(i,right) );
    }

    for (int i=right-1;i>=left;--i){
        rr=max(  rr,sum[right]-sum[left-1]-func(left,i) );
    }
    rr=max(rr,sum[right]-sum[left-1]);
    vis[left][right]=true;
    return dp[left][right]=rr;
}


int main(){
    int n;
    while (scanf("%d",&n)==1 && n){
        sum[0]=0;
        for (int i=1;i<=n;++i){
            scanf("%d",&arr[i]);
            sum[i]=sum[i-1]+arr[i];
        }
        memset(vis,false,sizeof(vis));
        printf("%d\n",func(1,n)-sum[n]+func(1,n) );
    }
    return 0;
}

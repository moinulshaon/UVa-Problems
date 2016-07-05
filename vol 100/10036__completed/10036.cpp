#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
int n,k;
int arr[10010];
char dp[10010][110];

int myabs(int x){
    return (x<0)?-x:x;
}

bool func(int totake,int sum)
{
    sum=myabs(sum)%k;
    if (totake==n){
        if (sum==0)
            return true;
        else
            return false;
    }

    if (dp[totake][sum]!=-1)return dp[totake][sum];

    return dp[totake][sum]=func( totake+1, (sum+arr[totake])%k ) || func( totake+1, (sum-arr[totake])%k );

}

int main()
{
    freopen("in.txt","r",stdin);

    int kase;
    scanf("%d",&kase);


    while (kase--)
    {
        scanf("%d %d",&n,&k);
        for (int i=0;i<n;++i)
            scanf("%d",&arr[i]);

        for (int i=0;i<=n;++i)
            for (int j=0;j<=k;++j)
                dp[i][j]=-1;

        if (func(1,arr[0]))
            printf("Divisible\n");
        else
            printf("Not divisible\n");

    }
    return 0;
}

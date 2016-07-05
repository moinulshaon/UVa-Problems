#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int cars[7000];
int base=3000;
int low,high;

int dp[7000];


int DFS(int n){

    if (dp[n]!=-1)return dp[n];

    int sum=1;

    for (int i=n+1;i<=high;++i){
        if (cars[i]<cars[n]){
            sum=max(sum,1+DFS(i));
        }
    }
    return dp[n]=sum;

}

int main(){

    freopen("in.txt","r",stdin);

    int kase,total,tt;
    scanf("%d",&kase);

    while (kase--){

        memset(dp,-1,sizeof(dp));

        scanf("%d",&total);

        low=high=base;
        for (int i=0;i<total;++i){
            scanf("%d",&tt);
            cars[base+i]=cars[base-i]=tt;
            low=base-i;
            high=base+i;
        }

        int result=0;
        for (int i=low;i<=high;++i){
            result=max(result,DFS(i));
        }

        printf("%d\n",result);
    }
    return 0;

}

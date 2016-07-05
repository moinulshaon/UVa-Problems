#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define sz 1000000

int arr[sz];
int dp[sz];
int total;

int DFS(int n){

    if (dp[n]!=-1)return dp[n];

    int mx=1;
    for (int i=n+1;i<total;++i){
        if (arr[i]<=arr[n] )
            mx=max( mx,1+DFS(i) );
    }

    return dp[n]=mx;

}


int main(){

    freopen("in.txt","r",stdin);

    int height;

    for (int kk=1;true;++kk){

        memset(dp,-1,sizeof(dp));

        total=0;
        while (scanf("%d",&height)==1 && height!=-1){

            arr[total++]=height;

        }
        if (!total)
            return 0;
        if (kk!=1)
            printf("\n");

        //printf("%d\n",total);
        printf("Test #%d:\n",kk);

        int mx=0;
        for (int i=0;i<total;++i)
            mx=max(mx,DFS(i));

        printf("  maximum possible interceptions: %d\n",mx);


    }

}

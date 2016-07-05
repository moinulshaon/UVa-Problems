#include <cstdio>
#include <algorithm>

using namespace std;

#define INF 100000000

int place;
int arr[60];
int dp[1100][1100];

int cutting( int l,int r ){

    if (dp[l][r]!=-1)return dp[l][r];

    int mn=INF;

    for (int i=0;i<place;++i){
        if (arr[i]>l && arr[i]<r)
            mn=min( mn, (r-l)+cutting( l,arr[i] )+cutting( arr[i],r )  );
    }
    if (mn==INF)
        mn=0;
    return dp[l][r]=mn;

}


int main(){
    freopen("in.txt","r",stdin);

    int length;

    while (scanf("%d",&length)==1 && length){

        for (int i=0;i<=length;++i)
            for (int j=0;j<=length;++j)
                dp[i][j]=-1;

        scanf("%d",&place);

        for (int i=0;i<place;++i)
            scanf("%d",&arr[i]);

        printf("The minimum cutting is %d.\n",cutting(0,length));

    }
    return 0;

}

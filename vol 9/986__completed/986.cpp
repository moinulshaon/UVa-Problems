#include <cstdio>
#include <cstring>
#include <algorithm>

#define sz 100

using namespace std;
int n,r,k;

bool vis[sz][sz][sz][2];
int dp[sz][sz][sz][2];

int DFS(int a,int b,int peak,int up_down){
    if (b<0 || a>n)return 0;
    if (a==n && b==0){
        if (peak==r)
            return 1;
        else
            return 0;
    }
    if (vis[a][b][peak][up_down])return dp[a][b][peak][up_down];

    vis[a][b][peak][up_down]=true;
    if (b ==k && up_down==1)
        return dp[a][b][peak][up_down] = DFS(a+1,b-1,peak+1,0) +DFS( a+1,b+1,peak,1 ) ;
    else
        return dp[a][b][peak][up_down] = DFS(a+1,b-1,peak,0) +DFS( a+1,b+1,peak,1 ) ;

}

int main(){

    while (scanf("%d %d %d",&n,&r,&k)==3){
        n=2*n;

        memset(vis,false,sizeof(vis));

        printf("%d\n",DFS(0,0,0,0) );


    }
    return 0;

}

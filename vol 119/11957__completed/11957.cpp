#include <cstdio>
#include <cstring>
#include <algorithm>

#define sz 110

using namespace std;

int n;
bool vis[sz][sz];
long long dp[sz][sz];
char mat[sz][sz];

long long DFS(int a,int b){
    //printf("%d %d\n",x,y);

    if (a<0 || a>=n || b<0 || b>=n)return 0;

    if (mat[a][b]=='B')return 0;

    if (vis[a][b])return dp[a][b];
    if (a==0 )return 1;

    long long r=0;
    if (mat[a-1][b+1]=='.')
        r+=DFS(a-1,b+1);
    else
        r+=DFS(a-2,b+2);


    if (b-1>=0 && mat[a-1][b-1]=='.')
        r+=DFS(a-1,b-1);
    else
        r+=DFS(a-2,b-2);
    vis[a][b]=true;
    return dp[a][b]=r%1000007;

}



int main(){
    freopen("in.txt","r",stdin);

    int kase;
    scanf("%d",&kase);
    getchar();

    for (int kk=1;scanf("%d",&n)==1;++kk){
        getchar();

        memset(vis,false,sizeof(vis));

        for (int i=0;i<n;++i){
            gets(mat[i]);
        }
        long long result;
        for (int i=n-1;i>=0;--i)
            for (int j=0;j<n;++j)
                if (mat[i][j]=='W'){
                    result=DFS(i,j);
                    j=n;
                    i=-1;
                }
        printf("Case %d: %lld\n",kk,result%1000007);
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>

#define INF 100000000

using namespace std;

int row,col;
int mat[15][110];
int nxt[15][110];
bool vis[15][110];
int dp[15][110];


int path(int r,int c){

    if (vis[r][c])return dp[r][c];

    if (c==col)return 0;

    int x=r-1,y=r,z=r+1;

    if (x<0)x=row-1;
    if (z>=row)z=0;

    int pathA=path( x,c+1 );
    int pathB=path( y,c+1 );
    int pathC=path( z,c+1 );



    nxt[r][c]=x;
    int mn=pathA;

    if (pathB<mn || (pathB==mn && y<nxt[r][c]) ){
        mn=pathB;
        nxt[r][c]=y;
    }

    if (pathC<mn  || (pathC==mn && z<nxt[r][c]) ){
        mn=pathC;
        nxt[r][c]=z;
    }


    vis[r][c]=true;
    return dp[r][c]=mat[r][c]+mn;

}

int main(){

    freopen("in.txt","r",stdin);

    while (scanf("%d %d",&row,&col)==2){

        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                scanf("%d",&mat[i][j]);
            }
        }

        memset(vis,false,sizeof(vis));

        int sum=INF;
        int ind=0;
        for (int i=0;i<row;++i){
            if (path(i,0)<sum ){
                sum=path(i,0);
                ind=i;
            }
        }


        printf("%d",ind+1);
        for (int i=0;i<col-1;++i){
            ind=nxt[ind][i];

            printf(" %d",ind+1);

        }
        printf("\n");
        printf("%d\n",sum);

    }
    return 0;

}

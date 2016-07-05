#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#define sz 110

using namespace std;

bool vis[sz][sz];
int result[sz][sz];

int mat[sz][sz];
int row,col;

int DFS(int a,int b){
    if (vis[a][b])return result[a][b];


    int mx=0;

    if (a-1>=0 && mat[a][b]>mat[a-1][b])
        mx=max( mx,DFS(a-1,b) );
    if (a+1<row && mat[a][b]>mat[a+1][b])
        mx=max( mx,DFS(a+1,b) );
    if (b-1>=0 && mat[a][b]>mat[a][b-1])
        mx=max( mx,DFS(a,b-1) );
    if (b+1<col && mat[a][b]>mat[a][b+1])
        mx=max( mx,DFS(a,b+1) );

    vis[a][b]=true;
    return result[a][b]=1+mx;
}

int main(){
    freopen("in.txt","r",stdin);

    int kase;
    string name;
    scanf("%d",&kase);

    while (kase--){

        memset(vis,false,sizeof(vis));

        cin>>name;

        scanf("%d %d",&row,&col);

        for (int i=0;i<row;++i)
            for (int j=0;j<col;++j)
                scanf("%d",&mat[i][j]);


        int mx=0;
        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                mx=max(mx,DFS(i,j));
            }
        }


        cout<<name;
        printf(": %d\n",mx);

    }
    return 0;
}

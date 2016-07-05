#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>

#define sz 110

using namespace std;

int row,col;
int d[sz][sz];
bool vis[sz][sz];
int result[sz][sz];


int DFS(int a,int b){
    if (vis[a][b])return result[a][b];

    if (a>row || b>col || !d[a][b])return 0;

    if (a==row && b==col){
        return result[a][b]=1;
    }
    vis[a][b]=true;
    return result[a][b]=DFS( a+1,b )+DFS( a,b+1 );

}


int main(){
    freopen("in.txt","r",stdin);

    int a,b,n;

    while (scanf("%d %d",&row,&col)==2 && row && col){

        memset(d,true,sizeof(d));
        memset(vis,false,sizeof(vis));

        scanf("%d",&n);
        while (n--){
            scanf("%d %d",&a,&b);
            d[a][b]=false;
        }

        int cnt=DFS(0,0);
        if (cnt==0)
            printf("There is no path.\n");
        else if (cnt==1)
            printf("There is one path from Little Red Riding Hood's house to her grandmother's house.\n");
        else
            printf("There are %d paths from Little Red Riding Hood's house to her grandmother's house.\n",cnt);

    }
    return 0;
}

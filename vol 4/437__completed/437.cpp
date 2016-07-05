#include <cstdio>
#include <algorithm>
#include <cstring>

#define sz 200

using namespace std;

bool vis[sz];
struct sss{
    int x,y,z;

    int longest;
} result[sz];

int totalBox;

bool cmp(const sss & first,const sss & second ){
    if ( first.x > second.x && first.y > second.y )
        return true;
    else
        return false;
}


int DFS(int n){
    //printf("%d\n",n);
    if (vis[n])return result[n].longest;

    int mx=0;
    for (int i=0;i<totalBox;++i){
        if ( result[i].x <result[n].x && result[i].y <result[n].y   ){
            mx=max( mx  ,DFS(i) );
        }
    }
    vis[n]=true;
    return result[n].longest=result[n].z+mx;

}


int main(){
    freopen("in.txt","r",stdin);

    int n,arr[3];
    for (int kase=1;scanf("%d",&n)==1 && n;++kase){
        totalBox=0;
        memset(vis,false,sizeof(vis));

        for (int i=0;i<n;++i){
            scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);


            result[totalBox].x=arr[0];
            result[totalBox].y=arr[1];
            result[totalBox++].z=arr[2];

            result[totalBox].x=arr[0];
            result[totalBox].y=arr[2];
            result[totalBox++].z=arr[1];

            result[totalBox].x=arr[1];
            result[totalBox].y=arr[0];
            result[totalBox++].z=arr[2];

            result[totalBox].x=arr[1];
            result[totalBox].y=arr[2];
            result[totalBox++].z=arr[0];

            result[totalBox].x=arr[2];
            result[totalBox].y=arr[0];
            result[totalBox++].z=arr[1];

            result[totalBox].x=arr[2];
            result[totalBox].y=arr[1];
            result[totalBox++].z=arr[0];
        }
        //printf("%d\n",totalBox);

        sort( result,result+totalBox, cmp );

        int mx=0;
        for (int i=0;i<totalBox;++i){
            mx=max( mx ,DFS(i) );
        }

        printf("Case %d: maximum height = %d\n",kase,mx);

    }
    return 0;

}

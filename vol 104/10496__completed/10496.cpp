#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct tt{
    int x,y;
}start,point[15];
int total;
int dis[15][15];
int d[15];

int func( tt &a, tt&b ){
    return abs( a.x-b.x )+abs( a.y-b.y );
}
int set(int N,int pos){
    return N=N | (1<<pos);
}
int reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool check(int N,int pos){
    return (bool)(N & (1<<pos));
}

int dp[13][1<<13];

int ff( int now,int state ){
    if ( state== ( 1<<total )-1  ){
        return d[now];
    }
    if ( dp[now][state]!= -1 )return dp[now][state];


    int mn=(1<<29);
    for (int i=0;i<total;++i){
        if ( check(state,i)==0 )
            mn=min( mn,dis[now][i]+ff( i,set(state,i) ) );
    }
    return dp[now][state]=mn;
}

int main(){
    int kase;
    scanf("%d",&kase);
    int row,col;
    while(kase--){
        scanf("%d %d",&row,&col);
        scanf("%d %d",&start.x,&start.y);

        scanf("%d",&total);

        for (int i=0;i<total;++i){
            scanf("%d %d",&point[i].x,&point[i].y);
        }

        for (int i=0;i<total;++i){
            d[i]=func( start,point[i] );
        }
        memset(dis,0,sizeof(dis));
        for (int i=0;i<total;++i){
            for (int j=i+1;j<total;++j){
                dis[i][j]=dis[j][i]=func( point[i],point[j] );
            }
        }

        int ans=(1<<29);
        memset(dp,-1,sizeof(dp));
        for (int i=0;i<total;++i){
            ans=min( ans,d[i]+ff( i,set(0,i) ) );
        }
        printf("The shortest path has length %d\n",ans);
    }
    return 0;
}

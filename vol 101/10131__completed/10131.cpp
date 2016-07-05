#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct sss{
    int weight,intel;

    int nxt,length,index;
}elephent[1100];
int total;
bool vis[1100];
int dp[1100];

bool cmp( const sss & a ,const sss & b){
    if (a.weight<b.weight && a.intel>b.intel)
        return true;
    else
        return false;
}

int DFS(  int n ){

    if (vis[n])return dp[n];

    int mx=1;
    for (int i=0;i<total;++i){
        if ( cmp ( elephent[n] ,elephent[i] ) ){
            if (mx < 1+DFS( i ) ){
                mx=1+DFS( i );
                elephent[n].nxt=i;
            }
        }

    }
    vis[n]=true;
    elephent[ n ].length=mx;
    return dp[n]=mx;

}


int main(){
    freopen("in.txt","r",stdin);

    memset( vis, false,sizeof(vis));

    for ( total=0 ; scanf("%d %d",&elephent[total].weight,&elephent[total].intel)==2 ;++total){
        elephent[total].index=total;
        elephent[total].nxt=1099;
    }


    //sort ( elephent,elephent+total ,cmp);

    int maxIndex=0,maxLength=0;

    for (int i=0;i<total;++i){
        if ( maxLength < DFS( i ) ){
            maxLength=DFS( i );
            maxIndex=i;
        }
    }
    printf("%d\n",maxLength);

    while (  maxIndex<total ){
        printf("%d\n",elephent[ maxIndex ].index+1);
        //printf("%d %d\n",elephent[ maxIndex ].weight,elephent[ maxIndex ].intel);

        maxIndex=elephent[ maxIndex ].nxt;

    }
    return 0;

}

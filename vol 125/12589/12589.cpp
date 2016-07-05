#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[51*51][51][51];


struct ttt{
    int x,y;
}points[55];

int n;

int knapsack( int height,int totake,int left ){

    if ( !left )return 0;
    if ( totake == n ){
        if ( left== 0 )return 0;
        else return -(1<<29);
    }

    if ( dp[height][totake][left]!= -1  )return dp[height][totake][left];

    int aa=knapsack( height+points[totake].y, totake+1,left-1 )+ 2*height*points[totake].x + points[totake].x * points[totake].y;
    int bb= knapsack( height , totake+1,left );

    return dp[height][totake][left]=max(aa,bb);
}

bool cmp( const ttt&a,const ttt &b ){
    return a.y*b.x>a.x*b.y;
}




int main(){
    freopen("in.txt","r",stdin);

    int kase,k;

    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){



        scanf("%d %d",&n,&k);

        memset(dp,-1,sizeof(dp));



        for (int i=0;i<n;++i){
            scanf("%d %d",&points[i].x,&points[i].y);
        }

        sort( points,points+n,cmp );

        printf("Case %d: %d\n",kk,knapsack( 0, 0, k )  );

    }
    return 0;
}

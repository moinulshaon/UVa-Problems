#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

int dp[35][110];

int p[35];

const int INF=(1<<29);

int men;

int func( int totake,int left,int lim ){

    if ( lim <= 0 )return 0;

    if ( left<=0 )return 0;

    if ( totake == men ){
        return INF;
    }

    if ( dp[totake][left] != -1 )return dp[totake][left] ;

    return dp[totake][left] =min( func( totake +1 ,left,lim ) ,
                                  p[totake]+func( totake+1 ,left - p[totake] / lim ,lim ) );

}

int main(){
    FRO

    int box;

    while ( scanf("%d %d",&box,&men)== 2 && (box+men) ){

        for (int i=0;i<men;++i){
            scanf("%d",&p[i]);
        }

        int low=0,high=INF;
        int cost,ans= -1 ;
        while ( low<=high ){
            int mid=(low+high)/2;
            NEG(dp);
            //cout<<mid<<' '<<func( 0,box,mid )<<endl;
            if ( func( 0,box,mid )<INF ){
                cost= func( 0,box,mid );
                ans = mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }

        printf("%d %d\n",ans,cost);

    }


    return 0;
}

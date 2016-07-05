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
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 2010

struct mathv{
    mathv(){x=0;y=0;}
    mathv(double a,double b){x=a;y=b;}
    double x,y;

    mathv operator + (mathv & p){
        mathv tmp( x+p.x,y+p.y );
        return tmp;
    }
    mathv operator - (mathv & p){
        mathv tmp( x-p.x,y-p.y );
        return tmp;
    }
}leftArray[SIZE],rightArray[SIZE],arr[SIZE];

double distance2D(mathv& v1, mathv& v2){
    return sqrt((v2.x - v1.x) * (v2.x - v1.x)+ (v2.y - v1.y) * (v2.y - v1.y));
}

double dp[SIZE][SIZE];
bool vis[SIZE][SIZE];


int n;

double func( int totake,int toPlaceRight ){

    if ( totake == n ){
        if ( toPlaceRight == n/2 ) return 0;
        else return 1e16;
    }

    double &ret = dp[totake][toPlaceRight];
    if ( vis[totake][toPlaceRight] )return ret;
    vis[totake][toPlaceRight]=true;

    ret= 1e16;
    if ( toPlaceRight < n/2 )
        ret = min( ret ,distance2D( arr[totake],rightArray[toPlaceRight] ) + func(totake+1,toPlaceRight+1) );
    if ( totake-toPlaceRight>= 0 && totake-toPlaceRight<n/2 )
        ret = min( ret ,distance2D( arr[totake],leftArray[totake-toPlaceRight] ) + func(totake+1,toPlaceRight) );
    return ret;
}

bool cmp( const mathv&a,const mathv&b ){
    return a.y<b.y;
}


int main(){



    double H,W;

    while ( ~scanf("%d %lf %lf",&n,&H,&W) ){

    for (int i=0;i<n;++i){
        scanf("%lf",&arr[i].y);
        arr[i].x = 0;
    }

    sort( arr,arr+n ,cmp );

    for (int i=0;i+i<n;i++){
        leftArray[i].x= 0;
        leftArray[i].y= double(i)*H/(n/2-1);
        //cout<<leftArray[i].x<<" "<<leftArray[i].y<<endl;
    }
    for (int i=0;i+i<n;i++){
        rightArray[i].x= W;
        rightArray[i].y= double(i)*H/(n/2-1);

        //cout<<rightArray[i].x<<" "<<rightArray[i].y<<endl;
    }

    CLR(vis);

    printf("%.8lf\n",func( 0,0 ));
    }
    return 0;
}

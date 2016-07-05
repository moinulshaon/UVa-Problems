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

#define MP make_pair
#define X first
#define Y second
typedef pair<int,int> pint;
typedef map<int,int> mint;


double team1[6],team2[6];

double dp[6][6][6][6];
bool vis[6][6][6][6];

pint dest;

const int save = 5;

double func( int t1,int t2,int rem1,int rem2 ){

    if ( t1<t2 && t1+rem1<t2 ){
        return MP(t1,t2) == dest;
    }
    if ( t1>t2 && t2+rem2<t1 ){
        return MP(t1,t2) == dest;
    }

    if ( rem1==0 && rem2 == 0 ){
        return MP(t1,t2) == dest;
    }

    double &ret = dp[t1][t2][rem1][rem2];
    if ( vis[t1][t2][rem1][rem2] )return ret;
    vis[t1][t2][rem1][rem2] = true;

    ret = 0;

    if ( rem1==rem2 ){
        ret += team1[save-rem1] * func( t1+1,t2,rem1-1,rem2 );
        ret += ( 1-team1[save-rem1] ) * func( t1,t2,rem1-1,rem2 );
    }else{
        ret += team2[save-rem2] * func( t1,t2+1,rem1,rem2-1 );
        ret += ( 1-team2[save-rem2] ) * func( t1,t2,rem1,rem2-1 );
    }


    return ret;
}



int main(){

    FRO

    int kk=1;
    while ( scanf("%lf",&team1[0])==1 ){

        for (int i=1;i<save;++i){
            scanf("%lf",&team1[i]);
        }
        for (int i=0;i<save;++i){
            scanf("%lf",&team2[i]);
        }
        //cout<<"shoan\n";
        scanf("%d-%d",&dest.X,&dest.Y);
        CLR(vis);
        printf("Case %d: %.2lf%%\n",kk++,func(0,0,save,save)*100);
    }


    return 0;
}

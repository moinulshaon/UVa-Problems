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

#define SIZE 5010

vector<int> out[SIZE];

pint dp[SIZE];

int n;
int mod =  100000;

pint func( int x ){
    if ( x == n ){
        return MP( 1,1 );
    }
    pint &ret = dp[x];
    if ( ret.X != -1 )return ret;
    ret = MP( 0,0 );
    for (int i=0;i<out[x].size();++i){
        ret . X = ( ret.X+ func( out[x][i] ).Y +func( out[x][i] ).X )%mod;
        ret . Y = ( ret.Y +func( out[x][i] ).Y )%mod;
    }
    return ret;
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int u,v,e;
        scanf("%d %d",&n,&e);
        for (int i=0;i<=n;++i){
            out[i].clear();
        }
        while ( e-- ){
            scanf("%d %d",&u,&v);
            out[u].PB( v );
        }

        NEG(dp);
        int tmp = 0;
        for (int i=0;i<out[1].size();++i){
            tmp= ( tmp+ func( out[1][i] ).X )%mod;
        }
        printf("Case %d: %d %d\n",kk,tmp%mod,func(1).Y%mod);
    }


    return 0;
}

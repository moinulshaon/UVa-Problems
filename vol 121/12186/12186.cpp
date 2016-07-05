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

bool cmp( const pint&a, const pint& b){
    return a.X<b.X;
}

#define SIZE 100100

vector<pint> out[SIZE];
int n;
int t;

int dfs( int x ){

    int child = out[x].size() ;

    if ( child == 0 )return  1;

    for (int i=0;i<out[x].size();++i){
        out[x][i].X = dfs( out[x][i].Y );
    }

    sort( out[x].begin(),out[x].end() , cmp );

    int need = ceil( child*t/100.0 )+1e-6;
    int ans = 0;
    for (int i=0; need-- ;++i ){
        ans += out[x][i].X;
    }
    return ans;
}

int main(){

    FRO

    while ( scanf("%d %d",&n,&t) == 2 && (n+t) ){
        int sup;
        for (int i=0;i<=n;++i){
            out[i].clear();
        }

        for (int i=1;i<=n;++i){
            scanf("%d",&sup);
            out[sup].PB( MP(0,i) );
        }


        printf("%d\n",dfs( 0 ) );
    }


    return 0;
}

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


typedef pair<LL,LL> pint;
typedef map<int,int> mint;

#define SIZE 100010

LL val[SIZE],cost[SIZE];

int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n,m;
        scanf("%d %d",&n,&m);
        for (int i=0;i<n;++i){
            scanf("%lld",&val[i]);
        }

        sort( val,val+n );
        reverse( val,val+n );

        for (int i=0;i<m;++i){
            scanf("%lld",&cost[i]);
        }

        set< pair<LL,int> > ss;
        for (int i=0;i<m;++i){
            ss.insert( MP(0,i) );
        }

        LL ans = 0;
        for (int i=0;i<n;++i){
            pair<LL,int> tmp = *ss.begin();

            ans = max( ans , val[i]+ tmp.X );
            ss.erase( ss.begin() );
            ss.insert( MP( tmp.X+ cost[ tmp.Y ] , tmp.Y ) );
        }

        printf("Case %d: %lld\n",kk,ans);
    }


    return 0;
}

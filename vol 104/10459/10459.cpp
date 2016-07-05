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

#define SIZE 5050

vector<int> out[SIZE];
bool vis[SIZE];

int dfs( int x ){

    vis[x]=true;

    int y,h=1;
    for (int i=0;i<out[x].size();++i){
        y= out[x][i];
        if ( vis[y] )continue;

        h=max( h,1+dfs(y) );
    }
    return h;
}

int main(){

    int n;
    while ( scanf("%d",&n)==1 ){
        for (int i=1;i<=n;++i){
            out[i].clear();
        }

        for (int i=1;i<=n;++i){
            int x,tmp;
            scanf("%d",&tmp);

            while (tmp--){
                scanf("%d",&x);
                out[i].PB( x );
                out[x].PB( i );
            }
        }

        vector<int> best,worst;
        int bestval= INT_MAX,worstval=INT_MIN;

        for (int i=1;i<=n;++i){

            for (int j=1;j<=n;++j){
                vis[j]=false;
            }

            int v= dfs( i );
            if(  v<bestval ){
                bestval=v;
                best.clear();
                best.PB( i );
            }else if ( v== bestval ){
                best.PB( i );
            }

            if(  v>worstval ){
                worstval=v;
                worst.clear();
                worst.PB( i );
            }else if ( v== worstval ){
                worst.PB( i );
            }

        }

        printf("Best Roots  :");
        for (int i=0;i<best.size();++i){
            printf(" %d",best[i]);
        }printf("\n");

        printf("Worst Roots :");
        for (int i=0;i<worst.size();++i){
            printf(" %d",worst[i]);
        }printf("\n");

    }


    return 0;
}

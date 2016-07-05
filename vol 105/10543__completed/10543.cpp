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

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 52

vector<int> out[SIZE];

bool vis[SIZE][SIZE][22];

int n,m,k;

#define MP make_pair

struct tt{
    int city,prv,move;
};

void bfs(){

    CLR(vis);

    tt tmp;
    tmp.city= 1 ;
    tmp.prv = 0 ;
    tmp.move = 1;

    deque<tt> q;

    q.push_back( tmp );
    vis[ tmp.city ][ tmp.prv ][ tmp.move ] = true;

    while ( !q.empty() ){
        tt ff=q.front();q.pop_front();

        if( ff.move>20  )break;

        if ( ff.city == n && ff.move>=k ){
            printf("%d\n",ff.move);
            return ;
        }

        for (int i=0;i<out[ff.city].size();++i){
            tmp.city= out[ff.city][i];
            tmp.prv= ff.city;
            tmp.move= ff.move+1;

            if ( !vis[ tmp.city ][ tmp.prv ][ tmp.move ] ){
                vis[ tmp.city ][ tmp.prv ][ tmp.move ]=true;
                q.push_back( tmp );
            }

        }
    }

    printf("LOSER\n");
}

int main(){

    FRO

    while ( scanf("%d %d %d",&n,&m,&k) == 3 && ( n+m+k ) ){

        for (int i=0;i<=n;++i){
            out[i].clear();
        }

        int u,v;

        while ( m-- ){
            scanf("%d %d",&u,&v);
            u++;
            v++;
            out[u].PB( v );
        }

        bfs();

    }


    return 0;
}

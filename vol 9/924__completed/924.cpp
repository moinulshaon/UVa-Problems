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

#define SIZE 2510

bool vis[SIZE];

vector<int> out[SIZE];
int boom,day;
int cnt[SIZE];
int n;

void bfs( int x ){

    queue<int> q;
    queue<int> move;

    CLR(vis);
    CLR(cnt);

    vis[x]=true;
    q.push(x);
    move.push(0);
    cnt[0]++;

    while ( !q.empty() ){
        int tmp=q.front();q.pop();
        int m=move.front();move.pop();

        for (int i=0;i<out[tmp].size();++i){
            if ( !vis[ out[tmp][i] ] ){
                vis[ out[tmp][i] ]=true;
                move.push( m+1 );
                q.push( out[tmp][i] );
                cnt[ m+1 ]++;
            }
        }
    }

    boom= 0 ;
    day = 0 ;
    for (int i=1;i<=n;++i){
        if ( cnt[i]>boom ){
            boom= cnt[i];
            day = i;
        }
    }

}


int main(){

    FRO

    scanf("%d",&n);

    int tt,v;
    for (int i=0;i<n;++i){
        scanf("%d",&tt);
        while ( tt-- ){
            scanf("%d",&v);
            out[i].PB( v );
            //out[v].PB( i );
        }
    }


    int qq;
    scanf("%d",&qq);

    while ( qq-- ){
        int x;
        scanf("%d",&x);

        bfs(x);


        if( day  ){
            printf("%d %d\n",boom,day);
        }else{
            printf("0\n");
        }
    }


    return 0;
}

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

#define SIZE 100100

bool vis[SIZE];

vector<int> out[SIZE];
int n;

int bfs( int x,int f ) {

    queue<int> q;
    queue<int> move;

    CLR(vis);

    vis[x]=true;
    q.push(x);
    move.push(0);

    while ( !q.empty() ) {
        int tmp=q.front();
        q.pop();
        int m=move.front();
        move.pop();

        for (int i=0; i<out[tmp].size(); ++i) {
            if ( !vis[ out[tmp][i] ] ) {

                if ( out[tmp][i] == f )return m+1;

                vis[ out[tmp][i] ]=true;
                move.push( m+1 );
                q.push( out[tmp][i] );
            }
        }
    }
    return -1;
}


int main() {

    FRO

    int kase;
    scanf("%d",&kase);

    while ( kase-- ) {

        scanf("%d",&n);

        for (int i=0;i<n;++i){
            out[i].clear();
        }

        int tt,v,num;
        for (int i=0; i<n; ++i) {
            scanf("%d %d",&num,&tt);
            while ( tt-- ) {
                scanf("%d",&v);
                out[num].PB( v );
                out[v].PB( num );
            }
        }

        int s,f;
        scanf("%d %d",&s,&f);
        printf("%d %d %d\n",s,f,bfs( s,f )-1);


        if ( kase )printf("\n");
    }




    return 0;
}

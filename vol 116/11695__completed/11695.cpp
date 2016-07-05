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

#define SIZE 2550

vector<int> out[SIZE];
int mark[SIZE];
bool on[SIZE][SIZE];

pint dfs( int x,int p ){

    pint ans = make_pair( x,0 );
    for (int i=0;i<out[x].size();++i){
        if ( out[x][i] != p  && on[x][ out[x][i] ]){
            pint tmp = dfs( out[x][i],x );
            tmp.second++;
            if ( tmp.second > ans.second ){
                ans = tmp;
            }
        }
    }
    return ans ;
}

int diam,le1,le2;

void calcdiameter( int x ){
    pint leaf= dfs( x,0 );
    le1 = leaf.first;
    leaf = dfs( leaf.first,0 );
    le2 = leaf.first;
    diam = leaf.second;
}

bool markme( int x,int to,int p ){
    if ( x==to )return true;
    for (int i=0;i<out[x].size();++i){
        if ( out[x][i] != p && on[x][ out[x][i] ] && markme( out[x][i] , to , x ) ){
            mark[x] = out[x][i];
            return true;
        }
    }
    return false;
}

int calccenter( int x,int dep ){
    if ( dep==0 )return x;
    return calccenter( mark[x], dep-1 );
}

int ans;
pint rem,add;
void del( int x,int des ){
    int ddl,ddr;
    if ( mark[x] == des ){

        on[ x ][ mark[x] ] = on[ mark[x] ][ x ] = false;
        calcdiameter( x );
        ddl = diam;
        calcdiameter( mark[x] );
        ddr = diam;
        //cout<<x<<" "<<des<<" "<<max( max( ddl,ddr ) ,ddl/2+ddl%2+ddr/2+ddr%2+1)<<endl;
        if ( ans > max( max( ddl,ddr ) ,ddl/2+ddl%2+ddr/2+ddr%2+1) ){
            ans =  max( max( ddl,ddr ) ,ddl/2+ddl%2+ddr/2+ddr%2+1);
            rem.first = x,rem.second = mark[x];
        }
        on[ x ][ mark[x] ] = on[ mark[x] ][ x ] = true;

        return ;
    }

    on[ x ][ mark[x] ] = on[ mark[x] ][ x ] = false;
    calcdiameter( x );
    ddl = diam;
    calcdiameter( mark[x] );
    ddr = diam;

    if ( ans > max( max( ddl,ddr ) ,ddl/2+ddl%2+ddr/2+ddr%2+1) ){
        ans =  max( max( ddl,ddr ) ,ddl/2+ddl%2+ddr/2+ddr%2+1);
        rem.first = x,rem.second = mark[x];
    }
    on[ x ][ mark[x] ] = on[ mark[x] ][ x ] = true;


    del( mark[x] , des );
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){
        int n;
        scanf("%d",&n);
        for (int i=0;i<=n;++i){
            out[i].clear();
        }
        int u,v;
        for (int i=1;i<n;++i){
            scanf("%d %d",&u,&v);
            out[u].PB( v );
            out[v].PB( u );
            on[u][v] = on[v][u] = true;

        }

        calcdiameter( 1 );

        int now = diam;
        //cout<<now<<endl;
        CLR(mark);
        markme( le1,le2,0 );
        //cout<<le1<<" "<<le2<<endl;
        ans = (1<<29);
        del( le1,le2 );
        //cout<<"shaon "<<ans<<endl;

        on[ rem.first ][ rem.second ] = on[ rem.second ][ rem.first ] = false;

        calcdiameter( rem.first );
        CLR(mark);
        markme( le1,le2,0 );
        add.first = calccenter( le1,diam/2 );

        calcdiameter( rem.second );
        CLR(mark);
        markme( le1,le2,0 );
        add.second = calccenter( le1,diam/2 );


        printf("%d\n",ans);
        printf("%d %d\n",rem.first,rem.second);
        printf("%d %d\n",add.first,add.second);

        for (int i=0;i<=n;++i){
            for (int j=0;j<out[i].size();++j){
                on[i][ out[i][j] ] = false;
            }
        }

    }


    return 0;
}

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

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define SIZE 100100

vector<int> out[SIZE];
vector<int> outcost[SIZE];

int parent[SIZE][17];
LL cost[SIZE][17];
int depth[SIZE];

void dfs(int x,int p,int w){

    parent[x][0]=p;
    cost[x][0]=w;
    depth[x]=depth[p]+1;


    for (int i=1;i<17;++i){
        parent[x][i]=parent[ parent[x][i-1] ][i-1];
        cost[x][i]=cost[x][i-1]+cost[ parent[x][i-1] ][i-1];
    }


    for (int i=0;i<out[x].size();++i){
        int y=out[x][i];
        if ( y!=p ){
            dfs(y,x,outcost[x][i]);
        }
    }


}

LL modifiedlca(int x,int y){
    if ( depth[x]>depth[y] ){
        swap(x,y);
    }
    LL rr=0;
    for (int i=0;i<17;++i){
        if( ( ( depth[y]-depth[x] )>>i )&1){
            rr+= cost[y][i];
            y=parent[y][i];
        }
    }
    if ( x==y ){
        return rr;
    }
    for(int i=16;i>=0;--i)
        if(parent[x][i]!=parent[y][i] ){
            rr+=cost[x][i];
            rr+=cost[y][i];
            x=parent[x][i],y=parent[y][i];

        }

    return rr+cost[x][0]+cost[y][0];
}

int main(){
    FRO

    int node;
    while(scanf("%d",&node)==1 && node){

        int a,w;

        for (int i=0;i<=node;++i){
            out[i].clear();
            outcost[i].clear();
        }

        for (int i=2;i<=node;++i){
            scanf("%d %d",&a,&w);
            a++;
            //printf("%d %d %d\n",a-1,i-1,w);
            out[a].PB( i );
            outcost[a].PB( w );
        }


        dfs(1,0,0);

        int query;
        scanf("%d",&query);
        //printf("q %d\n",query);
        for (int i=0;i<query;++i){
            scanf("%d %d",&a,&w);
            if ( i )printf(" ");
            printf("%lld",modifiedlca(a+1,w+1));
        }
        printf("\n");
    }

    return 0;
}


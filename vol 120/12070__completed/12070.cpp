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

int n,f,t;
pint cord[10];
int cost[30][30];


struct node{
    int val,x,y,day;
    bool operator < (const node & p)const{return val>p.val;}
};
int dist[30][30][30];

int dr[]={-1,0,1,0};
int dc[]={0,-1,0,1};


int dijkstra( int x,int y ){

    node ss;
    ss.x=x;
    ss.y=y;
    ss.val=0;
    ss.day=0;

    priority_queue<node> q;
    q.push( ss );

    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            for (int k=0;k<=t;++k){
                dist[i][j][k] = (1<<28);
            }
        }
    }

    while ( !q.empty() ){
        node tmp = q.top();q.pop();

        if ( dist[tmp.x][tmp.y][tmp.day] <= tmp.val || tmp.day>t )continue;
        dist[tmp.x][tmp.y][tmp.day]=tmp.val;

        for (int i=0;i<4;++i){
            ss.x=tmp.x+dr[i];
            ss.y=tmp.y+dc[i];
            ss.val=tmp.val+cost[ss.x][ss.y];
            ss.day=tmp.day+1;
            if ( ss.x>=0 && ss.x<n && ss.y>=0 && ss.y<n && ss.day<=t &&dist[ss.x][ss.y][ss.day] > ss.val ){
                q.push( ss );
            }
        }
    }

    int sum = 0;
    //cout<<"start "<<x<<" "<<y<<endl;
    for (int i=0;i<f;++i){
        //cout<<cord[i].first<<" "<<cord[i].second<<" "<<dist[ cord[i].first ][ cord[i].second ]<<endl;
        int mn = dist[ cord[i].first ][ cord[i].second ][ 0 ];
        for (int j=1;j<=t;++j){
            mn=min( mn,dist[ cord[i].first ][ cord[i].second ][ j ] );
        }
        sum+= mn;
    }
    //cout<<endl;
    return sum;
}

bool ispos(int x,int y){

    for (int i=0;i<f;++i){
        if ( abs( x-cord[i].first )+abs( y-cord[i].second )>t )return false;
    }
    return true;
}

int main(){

    FRO

    for (int kk=1; scanf("%d %d %d",&n,&f,&t)==3 && (n+f+t) ; ++kk ){
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                scanf("%d",&cost[i][j]);
            }
        }
        for (int i=0;i<f;++i){
            scanf("%d %d",&cord[i].first,&cord[i].second);
        }

        int ans = (1<<28),xx,yy,sum;
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){

                if ( !ispos(i,j) )continue;

                sum = dijkstra(i,j);
                if ( sum<ans ){
                    ans = sum;
                    xx=i;
                    yy=j;
                }
            }
        }

        if ( ans >= (1<<28) ){
            printf("Case #%d: Impossible.\n",kk);
        }else{
            printf("Case #%d: Selected city (%d,%d) with minimum cost %d.\n",kk,xx,yy,ans);
        }
    }
    return 0;
}

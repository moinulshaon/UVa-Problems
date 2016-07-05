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

#define X first
#define Y second

mint mx,my;

struct SEG{
    pint lower,upper;
}seg[55],query[25];

vector<int> tt,rr;

#define SIZE 310

bool board[SIZE][SIZE];

struct node{
    int x,y,dir,turn;
};

bool vis[SIZE][SIZE][4];
int dr[]={-1,0,1,0};
int dc[]={0,-1,0,1};

int xlim,ylim;

int bfs( int x,int y,int fx,int fy ){

    if ( !board[x][y] || !board[fx][fy] )return -1;

    if ( x==fx && y == fy )return 0;

    for (int i=0;i<xlim;++i){
        for (int j=0;j<ylim;++j){
            for (int k=0;k<4;++k){
                vis[ i ][ j ][ k ] = false;
            }
        }
    }

    node ss;
    ss.x=x;
    ss.y=y;
    ss.turn=0;

    deque<node> q;

    for (int i=0;i<4;++i){
        ss.dir= i;
        q.push_back( ss );
    }


    while ( !q.empty() ){
        node tmp= q.front();q.pop_front();

        if ( tmp.x==fx && tmp.y== fy )return tmp.turn;

        if ( vis[tmp.x][tmp.y][tmp.dir] )continue;

        vis[tmp.x][tmp.y][tmp.dir]=true;

        for (int i=0;i<4;++i){
            if ( i == tmp.dir ){
                ss.dir=i;
                ss.turn=tmp.turn;
                ss.x= tmp.x+dr[i];
                ss.y= tmp.y+dc[i];

                if ( ss.x>=0 && ss.x<xlim && ss.y>=0 && ss.y<ylim && board[ ss.x ][ ss.y ] &&
                    !vis[ss.x][ss.y][ss.dir] ){

                    q.push_front( ss );
                }
            }else{
                ss.dir=i;
                ss.turn=tmp.turn+1;
                ss.x= tmp.x+dr[i];
                ss.y= tmp.y+dc[i];

                if ( ss.x>=0 && ss.x<xlim && ss.y>=0 && ss.y<ylim && board[ ss.x ][ ss.y ] &&
                    !vis[ss.x][ss.y][ss.dir] ){

                    q.push_back( ss );
                }
            }
        }

    }
    return -1;
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        printf("Labyrinth #%d\n",kk);

        int s,q;
        scanf("%d",&s);

        tt.clear();rr.clear();
        for (int i=0;i<s;++i){
            scanf("%d %d %d %d",&seg[i].lower.X,&seg[i].lower.Y,&seg[i].upper.X,&seg[i].upper.Y);
            tt.PB( seg[i].lower.X );
            rr.PB( seg[i].lower.Y );

            tt.PB( seg[i].upper.X );
            rr.PB( seg[i].upper.Y );
        }

        scanf("%d",&q);
        for (int i=0;i<q;++i){
            scanf("%d %d %d %d",&query[i].lower.X,&query[i].lower.Y,&query[i].upper.X,&query[i].upper.Y);
            tt.PB( query[i].lower.X );
            rr.PB( query[i].lower.Y );

            tt.PB( query[i].upper.X );
            rr.PB( query[i].upper.Y );
        }

        mx.clear();my.clear();

        sort( tt.begin(),tt.end() );
        sort( rr.begin(),rr.end() );

        int cnt = 2;
        for (int i=0;i<tt.size();++i){
            if ( mx.find( tt[i] )==mx.end() ){
                mx[ tt[i] ]= cnt;
                cnt+= 2;
            }
        }
        xlim=cnt+2;
        cnt = 2;
        for (int i=0;i<rr.size();++i){
            if ( my.find( rr[i] )==my.end() ){
                my[ rr[i] ]= cnt;
                cnt+= 2;
            }
        }
        ylim=cnt+2;

        for (int i=0;i<SIZE;++i){
            for (int j=0;j<SIZE;++j){
                board[i][j] = true;
            }
        }

        for (int i=0;i<s;++i){
            int a=mx[ seg[i].lower.first ],b=mx[ seg[i].upper.first ];
            int c=my[ seg[i].lower.second ],d=my[ seg[i].upper.second ];
            for (int j=a;j<=b;++j){
                for (int k=c;k<=d;++k){
                    board[j][k] =false;
                }
            }
        }
        /*
        for (int i=0;i<xlim;++i){
            for (int j=0;j<ylim;++j){
                printf("%d",board[i][j]);
            }printf("\n");
        }
        */
        for (int i=0;i<q;++i){
            //cout<<"from "<<mx[ query[i].lower.first ]<<" "<<my[ query[i].lower.second ]<<endl;
            //cout<<"to "<<mx[ query[i].upper.first ]<<" "<<my[ query[i].upper.second ]<<endl;
            int ans = bfs( mx[ query[i].lower.first ],my[ query[i].lower.second ],
                                 mx[ query[i].upper.first ],my[ query[i].upper.second ] );
            if ( ans == -1 ){
                printf("Impossible.\n");
            }else{
                printf("%d\n",ans);
            }
        }
    }


    return 0;
}

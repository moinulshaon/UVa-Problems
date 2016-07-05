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

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 55
#define MP make_pair
#define X first
#define Y second

char board[SIZE][SIZE];
int hum[SIZE][SIZE];
int ghost[SIZE][SIZE];
int row,col;

int dis[55][55];

int dr[]={-1,0,1,0};
int dc[]={0,-1,0,1};

int cntleft,cntright;

void bfs(int r,int c,int node){

    pint start=MP(r,c),tmp;
    queue<pint> q;
    queue<int> move;

    bool vis[SIZE][SIZE]={false};

    q.push(start);
    vis[start.X][start.Y]=true;
    move.push(0);

    while( !q.empty() ){
        tmp=q.front();q.pop();
        int xx=move.front();move.pop();

        for (int i=0;i<4;++i){
            int rr=tmp.X+dr[i];
            int cc=tmp.Y+dc[i];

            if ( rr>=0 && rr<row && cc>=0 && cc<col && board[rr][cc] != '#' && !vis[rr][cc] ){
                if ( board[rr][cc]=='X' ){
                    dis[node][ hum[rr][cc] ]=(xx+1);
                    //printf("%d %d\n",rr,cc);
                }
                vis[rr][cc]=true;
                q.push( MP(rr,cc) );
                move.push(xx+1);
            }

        }

    }

}
int Set(int N,int pos){
    return N=N | (1<<pos);
}
int Reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool Check(int N,int pos){
    return (bool)(N & (1<<pos));
}

int dp[16][(1<<16)+2];
int func( int totake,int state ){

    if (totake== cntleft || state==( 1<<cntright )-1 )return 0;

    if ( dp[totake][state] != -1 )return dp[totake][state];

    int ans=(1<<29);
    for (int i=0;i<cntright;++i){
        if ( Check( state,i )==0 ){
            ans=min( ans,dis[totake][i]+func(totake+1,Set(state,i) ) );
        }
    }
    return dp[totake][state]=ans;
}


int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%d %d",&row,&col);

        for (int i=0;i<row;++i){
            scanf("%s",board[i]);
        }
        int tmp=0;
        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( board[i][j] == 'X' ){
                    hum[i][j]=tmp++;
                }
            }
        }
        cntright=tmp;
        tmp=0;
        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( board[i][j] == 'B' ){
                    ghost[i][j]=tmp++;
                }
            }
        }
        cntleft=tmp;
        tmp=0;

        memset(dis,63,sizeof(dis));

        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( board[i][j] == 'B' ){
                    bfs(i,j,tmp);
                    tmp++;
                }
            }
        }
        /*
        for (int i=0;i<cntleft;++i){
            for (int j=0;j<cntright;++j){
                printf("%d\n",dis[i][j]);
            }
        }
        */

        NEG(dp);
        printf("%d\n",func(0,0));


    }


    return 0;
}

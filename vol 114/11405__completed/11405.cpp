#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <map>
#include <iostream>

using namespace std;
char board[12][12];

const int INF=100000000;

typedef pair<int,int> ppi;
map<ppi,int> mp;
ppi start;
ppi node[12];
int cnt;

int dis[12][12];
int d[12];
int move;

bool vis[12][12];

int dr[]={-1,-2,-2,-1,+1,+2,+2,+1 };
int dc[]={+2,+1,-1,-2,-2,-1,+1,+2 };

void BFS( ppi start ,int *change){

    memset(vis,false,sizeof(vis));

    queue<ppi> q;
    queue<int> m;

    q.push( start );
    vis[ start.first ][ start.second ]=true;
    m.push(0);

    while( !q.empty() ){
        ppi tmp=q.front();q.pop();
        int f=m.front();m.pop();

        if ( f >move )return ;
        //printf("%d %d %d\n",tmp.first,tmp.second,f);

        for (int i=0;i<8;++i){
            int r=tmp.first+dr[i];
            int c=tmp.second+dc[i];

            if ( c>=0 && c<8 && r>=0 && r<8 && board[r][c]!='p' && board[r][c]!='K'  && !vis[r][c]  ){

                ppi me=make_pair(r,c);
                if ( board[r][c] =='P' ){
                    change[ mp[me] ]=f+1;
                }
                vis[ r ][ c ]=true;
                q.push( me );
                m.push( f+1 );

            }

        }
    }
}

int set(int N,int pos){
    return N=N | (1<<pos);
}
int reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool check(int N,int pos){
    return (bool)(N & (1<<pos));
}


int dp[1<<12][12];

int func( int state,int now ){
    if ( state == (1<<cnt)-1 )return 0;

    if ( dp[ state ][ now ] != -1 )return dp[ state ][ now ];

    int cost=INF;
    for (int i=0;i<cnt ;++i){
        if ( check(state,i)==0 ){
            cost= min( cost, dis[now][i]+func( set( state,i ),i ) );
        }
    }
    return dp[state][now]=cost;
}

int main(){
    freopen("in.txt","r",stdin);
    int kase;
    scanf("%d",&kase);

    while (kase--){

        scanf("%d",&move);

        for (int i=0;i<8;++i){
            scanf("%s",board[i]);
        }

        mp.clear();
        cnt=0;

        for (int i=0;i<8;++i){
            for (int j=0;j<8;++j){
                if ( board[i][j]=='k' ){
                    start=make_pair( i,j );
                }else if( board[i][j]=='P' ) {
                    node[cnt]=make_pair( i,j );
                    mp[ node[cnt] ]=cnt;
                    //printf("%d %d\n", node[cnt] .first ,node[cnt] .second);
                    cnt++;
                }
            }
        }

        if ( cnt==0 ){
            printf("Yes\n");
            continue;
        }

        for (int i=0;i<cnt;++i){
            d[i]=INF;
        }
        for (int i=0;i<cnt;++i){
            for (int j=0;j<cnt;++j){
                dis[i][j]=INF;
            }
        }

        BFS( start,d );
        for (int i=0;i<cnt;++i){
            BFS( node[i],dis[i] );
        }


        bool pos=false;
        memset(dp,-1,sizeof(dp));
        for (int i=0;i<cnt && !pos ;++i){
            if (d[i] + func( set(0,i),i )<=move ){
                pos=true;
            }
        }

        if ( pos ){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}

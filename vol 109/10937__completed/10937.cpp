#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <map>
#include <iostream>

using namespace std;
char board[52][52];

const int INF=100000000;

typedef pair<int,int> ppi;
map<ppi,int> mp;
ppi start;
ppi node[12];
int cnt;

int dis[12][12];
int d[12];
int row,col;

bool vis[52][52];

int dr[]={+0,-1,+0,+1 };
int dc[]={+1,+0,-1,+0 };

int dr2[]={+1,+0,-1,-1,+1,+1,+0,-1,};
int dc2[]={+1,+1,+1,+0,+0,-1,-1,-1};

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


        //printf("%d %d %d\n",tmp.first,tmp.second,f);

        for (int i=0;i<4;++i){
            int r=tmp.first+dr[i];
            int c=tmp.second+dc[i];

            if ( c>=0 && c<col && r>=0 && r<row && board[r][c]!='#'   && !vis[r][c]  ){

                ppi me=make_pair(r,c);
                if ( board[r][c] =='!' ){
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
    if ( state == (1<<cnt)-1 )return d[now];

    if ( dp[ state ][ now ] != -1 )return dp[ state ][ now ];

    int cost=INF;
    for (int i=0;i<cnt ;++i){
        if ( check(state,i)==0 ){
            cost= min( cost, dis[now][i]+func( set( state,i ),i ) );
        }
    }
    return dp[state][now]=cost;
}

void flood( int x,int y ){

    for (int k=0;k<8;++k){
        int r=x+dr2[k];
        int c=y+dc2[k];

        if ( r>=0 && r<row && c>=0 && c<col ){
            if ( board[r][c]== '*' ){
                board[r][c]='#';
                flood(r,c);
            }else{
                board[r][c]='#';
            }
        }
    }
}

int main(){
    freopen("in.txt","r",stdin);


    while (scanf("%d %d",&row,&col)==2 && (row+col) ){

        for (int i=0;i<row;++i){
            scanf("%s",board[i]);
        }

        int ini=0;
        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( board[i][j] == '!' ){
                    ini++;
                }
            }
        }

        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( board[i][j]=='*' ){
                    board[i][j]='#';
                    flood(i,j);
                }else if ( board[i][j]=='~'  ){
                    board[i][j]='#';
                }
            }
        }


        bool pos=false;
        mp.clear();
        cnt=0;

        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( board[i][j]=='@' ){
                    start=make_pair( i,j );
                    pos=true;
                }else if( board[i][j]=='!' ) {
                    node[cnt]=make_pair( i,j );
                    mp[ node[cnt] ]=cnt;
                    //printf("%d %d\n", node[cnt] .first ,node[cnt] .second);
                    cnt++;
                }
            }
        }
        if ( cnt!=ini || !pos  ){
            printf("-1\n");
            continue;
        }else if ( cnt==0 ){
            printf("0\n");
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


        memset(dp,-1,sizeof(dp));
        int rr=INF;

        for (int i=0;i<cnt ;++i){
            rr=min( rr,d[i]+func( set(0,i),i ) );
        }

        if ( rr==INF ){
            printf("-1\n");
        }else{
            printf("%d\n",rr);
        }
    }
    return 0;
}

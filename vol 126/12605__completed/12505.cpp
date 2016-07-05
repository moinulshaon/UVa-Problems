#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int row,col;
int board[20][20];

typedef pair<int,int> pp;

vector< pp > out[20][20];
bool vis[20][20];
bool found[15];
int cnt;

void dfs(int r,int c){
    vis[r][c]=true;
    found[ board[r][c]  ]=true;
    ++cnt;

    for (int i=0;i<out[r][c].size();++i){
        int x=out[r][c][i].first;
        int y=out[r][c][i].second;

        if ( !vis[x][y] ){
            dfs( x,y );
        }
    }
}

int func(){
    for (int i=1;i<15;++i){
        if ( !found[i] )return i-1;
    }
}

int main(){

    freopen("in.txt","r",stdin);

    int kase;
    scanf("%d",&kase);

    char line[20];

    while (kase--){

        scanf("%d %d",&row,&col);

        for (int i=0;i<row;++i){
            scanf("%s",line);
            for (int j=0;j<col;++j){
                board[i][j]=line[j]-'0';
                out[i][j].clear();
            }
        }
        int tmp;
        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                scanf("%d",&tmp);

                if ( tmp>=8 ){
                    out[i][j].push_back( make_pair( i,j-1 ) );
                    tmp=tmp%8;
                }
                if ( tmp>=4 ){
                    out[i][j].push_back( make_pair( i+1,j ) );
                    tmp=tmp%4;
                }
                if ( tmp>=2 ){
                    out[i][j].push_back( make_pair( i,j+1 ) );
                    tmp=tmp%2;
                }
                if ( tmp>=1 ){
                    out[i][j].push_back( make_pair( i-1,j ) );
                }
            }
        }

        memset(vis,false,sizeof(vis));

        bool yes=true;

        for (int i=0;i<row && yes;++i){
            for (int j=0;j<col;++j){
                if ( vis[i][j] )continue;

                cnt=0;
                memset(found,false,sizeof(found));
                dfs(i,j);
                if ( cnt> func() ){
                    yes=false;
                    break;
                }
            }
        }

        for (int i=0;i<row && yes;++i){
            for (int j=0;j<col && yes;++j){
                for (int k=j+1;k<col && yes;++k){
                    if ( board[i][j]==board[i][k] ){

                        if ( k-j-1< board[i][j] ){
                            yes=false;
                        }

                    }
                }
            }
        }


        for (int i=0;i<col && yes;++i){
            for (int j=0;j<row && yes;++j){
                for (int k=j+1;k<row && yes;++k){
                    if ( board[j][i]==board[k][i] ){

                        if ( k-j-1< board[j][i] ){
                            yes=false;
                        }

                    }
                }
            }
        }
        if ( yes )printf("valid\n");
        else printf("invalid\n");
    }
    return 0;
}

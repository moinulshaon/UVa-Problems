#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int SIZE=101;

vector<int> outarrow[SIZE];
bool result[SIZE][SIZE];
bool vis[SIZE];
bool ini[SIZE];
bool disabled[SIZE];

void inidfs(int x){
    if ( ini[x] )return ;
    ini[x]=true;
    for (int i=0;i<outarrow[x].size();++i){
        inidfs( outarrow[x][i] );
    }
}

void dfs(int x){
    if ( vis[x] || disabled[x] )return ;
    vis[x]=true;
    for (int i=0;i<outarrow[x].size();++i){
        dfs( outarrow[x][i] );
    }
}

void out(int x){
    printf("+");
    for (int i=0;i<x;++i){
        printf("-");
    }
    printf("+\n");

}





int main(){
    freopen("in.txt","r",stdin);

    int kase,v,tmp;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%d",&v);

        for (int i=0;i<v;++i){
            outarrow[i].clear();
        }

        for (int i=0;i<v;++i){
            for (int j=0;j<v;++j){
                scanf("%d",&tmp);
                if ( tmp ){
                    outarrow[i].push_back(j);
                }
            }
        }
        memset(result,false,sizeof(result));
        memset(ini,false,sizeof(ini));
        memset(disabled,false,sizeof(disabled));

        inidfs(0);


        for (int i=0;i<v;++i){
            memset(vis,false,sizeof(vis) );
            if ( !ini[i] )continue;

            disabled[i]=true;
            dfs(0);
            disabled[i]=false;
            for (int j=0;j<v;++j){
                if ( ini[j] && !vis[j] ){
                    result[i][j]=true;
                }
            }
        }
        printf("Case %d:\n",kk);
        for (int i=0;i<v;++i){
            out(2*v-1);
            for (int j=0;j<v;++j){
                printf("|%c",(result[i][j])?('Y'):('N') );
            }
            printf("|\n");
        }
        out(2*v-1);

    }
    return 0;

}

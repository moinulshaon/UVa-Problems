#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;


const int MAX=10100;

vector<int> outarrow[MAX];
vector<int> cost[MAX];

int mx,mxv;
bool vis[MAX];
void dfs(int x,int d){

    if ( vis[x] )return ;

    vis[x]=true;
    if ( d>mx ){
        mx=d;
        mxv=x;
    }
    for (int i=0;i<outarrow[x].size();++i){
        dfs( outarrow[x][i] ,d+cost[x][i] );
    }
}

int main(){
    freopen("in.txt","r",stdin);
    char line[30];
    int a,b,w;
    while (gets(line)){

        for (int i=0;i<MAX;++i){
            outarrow[i].clear();
            cost[i].clear();
        }
        if ( !strlen(line) ){
            printf("0\n");
            gets(line);
            continue;
        }

        int city=0;
        do{
            sscanf(line,"%d %d %d",&a,&b,&w);

            if ( a>city ){
                city=a;
            }
            if ( b>city ){
                city=b;
            }

            outarrow[a].push_back(b);
            cost[a].push_back(w);

            outarrow[b].push_back(a);
            cost[b].push_back(w);


        }while (gets(line) && strlen(line));



        mx= -(1<<29);
        memset(vis,false,sizeof(vis));
        dfs(1,0);

        mx= -(1<<29);
        memset(vis,false,sizeof(vis));
        dfs(mxv,0);

        printf("%d\n",mx);

    }
    return 0;

}

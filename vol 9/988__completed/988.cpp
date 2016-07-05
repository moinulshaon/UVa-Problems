#include <cstdio>
#include <cstring>
#include <vector>

#define sz 110

using namespace std;

vector<int> outarrow[sz];
int result[sz];
bool vis[sz];

int DFS(int n){
    if (vis[n])return result[n];

    if (outarrow[n].size()==0){
        return result[n]=1;
    }
    int sum=0;
    for (int i=0;i<outarrow[n].size();++i){
        sum+=DFS(outarrow[n][i]);
    }
    vis[n]=true;
    return result[n]=sum;
}

int main(){

    int node,a,b;


    for (bool on=false;scanf("%d",&node)==1;on=true){

        if (on)printf("\n");

        memset(vis,false,sizeof(vis));

        for (int i=0;i<node;++i){
            outarrow[i].clear();
        }

        for (int i=0;i<node;++i){
            scanf("%d",&a);
            while (a--){
                scanf("%d",&b);
                outarrow[i].push_back(b);
            }
        }

        printf("%d\n",DFS(0));

    }
    return 0;

}

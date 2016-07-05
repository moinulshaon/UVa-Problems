#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define sz 110

using namespace std;

int nodes;
int kase;
vector <int> outarrow[sz];

struct tttt{
    int nodeNumber;
    int step;
}tmp,tmp2;

void BFS(int start){

    queue<tttt> q;
    tmp.nodeNumber=start;
    tmp.step=0;

    q.push(tmp);

    int maxStep=0,maxNode=1000;


    while ( !q.empty() ){
        tmp=q.front();
        q.pop();
        //printf("%d\n",tmp.nodeNumber);

        if (tmp.step>maxStep || (tmp.step==maxStep && tmp.nodeNumber<maxNode)){
            maxStep=tmp.step;
            maxNode=tmp.nodeNumber;
        }

        for (int i=0;i<outarrow[tmp.nodeNumber].size();++i){
            tmp2.nodeNumber=outarrow[tmp.nodeNumber][i];
            tmp2.step=tmp.step+1;
            q.push( tmp2 );
        }
    }

    printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",kase,start,maxStep,maxNode);

}

int main(){
    freopen("in.txt","r",stdin);

    int start,a,b;

    while (true){
        scanf("%d",&nodes);
        if (!nodes)return 0;

        ++kase;

        for (int i=0;i<=nodes;++i){
            outarrow[i].clear();
        }

        scanf("%d",&start);

        while (scanf("%d %d",&a,&b) && a && b){
            outarrow[a].push_back(b);
        }

        BFS(start);

    }
}

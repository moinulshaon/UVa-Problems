#include <cstdio>
#include <vector>

using namespace std;

struct EDGES{
    int startPoint,endPoint;
}edges[100];

vector<int> outarrow[100];

int n,m;

int main(){

    while (true){
        scanf("%d %d",&n,&m);

        for (int i=0;i<n;++i)
            outarrow[i].clear();

        for (int i=0;i<m;++i){
            scanf("%d %d",&edges[i].startPoint,edges[i].endPoint);

            outarrow[edges[i].startPoint].push_back(edges[i].endPoint);

        }



    }
}

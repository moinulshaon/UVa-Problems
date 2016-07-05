#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>

#define sz 110

using namespace std;

int d[sz][sz];
bool vis[sz];
int prvnode[sz];
int nodes1,nodes2;

struct place{
    double x,y;
    vector<int> outarrow;
}G1[sz],G2[sz];

int pair_G1[sz],pair_G2[sz];

bool BFS(){

}

int main(){

    int s,v;

    while ( scanf ("%d %d %d %d", &nodes1,&nodes2,&s,&v)==4 ){
        s*=v;
        int source=105,destination=106;

        memset(d,0,sizeof(d));

        memset(pair_G1,-1,sizeof(pair_G1));
        memset(pair_G2,-1,sizeof(pair_G2));

        for (int i = 0; i <nodes1; i++ ){
            scanf("%lf %lf",&G1[i].x,&G1[i].y);
            G1[i].outarrow.clear();
        }
        for (int i =200; i <nodes2+200; i++ ){
            scanf("%lf %lf",&G2[i].x,&G2[i].y);
            G2[i].outarrow.clear();
        }
        for (int i=0;i<nodes1;++i){
            for (int j=0;j<nodes2;++j){
                if ( !(  ( G1[i].x-G2[j].x)*( G1[i].x-G2[j].x)+( G1[i].y-G2[j].y)*( G1[i].y-G2[j].y)  > s*s ) ){
                    G1[i].outarrow.push_back(j);

                    d[i][j]=1;
                }

            }
        }

        G1[source].outarrow.clear();

        for (int i=0;i<nodes1;++i){
            G1[source].outarrow.push_back(i);
            d[source][i]=1;
        }

        G2[destination].outarrow.clear();
        for (int j=200;j<nodes2+200;++j){
            G2[j].outarrow.push_back(destination);
            d[j][destination]=1;
        }

        int matching = 0;

        while (BFS()){

        }
    }
}

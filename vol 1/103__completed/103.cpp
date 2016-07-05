#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#define max(a,b) ((a)>(b))?(a):(b)

using namespace std;
int dimension;
struct BOX{
    int length[12];
}box[35];

int d[35][35];
int nxt[35][35];

bool compare(int a,int b){

    for (int i=0;i<dimension;++i){
        if (box[a].length[i] <= box[b].length[i] )
            return false;
    }
    return true;
}

vector<int> result;

void getPath(int a,int b){
    if (nxt[a][b]== -1)
        return ;
    getPath(a,nxt[a][b]);
    result.push_back(nxt[a][b]);
    getPath(nxt[a][b],b);

}

int main(){
    freopen("in.txt","r",stdin);

    int total;
    while (scanf("%d %d",&total,&dimension)==2){

        for (int i=1;i<=total;++i){
            for (int j=0;j<dimension;++j){
                scanf("%d",&box[i].length[j]);
            }
            sort(box[i].length, box[i].length+dimension  );
        }
        memset(d,0,sizeof(d));
        memset(nxt,-1,sizeof(nxt));

        for (int i=1;i<=total;++i){
            for (int j=1;j<=total;++j){
                if ( compare( i,j ) )
                    d[i][j]=1;
            }
        }


        for (int k=1;k<=total;++k){
            for (int i=1;i<=total;++i){
                for (int j=1;j<=total;++j){
                    if (d[i][k] && d[k][j] && d[i][k]+d[k][j] >d[i][j]){

                        d[i][j]=d[i][k]+d[k][j];

                        nxt[i][j]=k;

                    }
                }
            }
        }


        int mx=-1,start=-1,finish=-1;
        for (int i=1;i<=total;++i)
            for (int j=1;j<=total;++j)
                if (d[i][j]>mx){
                    mx=d[i][j];
                    start=i;
                    finish=j;
                }

        result.clear();

        result.push_back(start);
        getPath(start,finish);

        if (start!=finish)
            result.push_back(finish);

        printf("%d\n",result.size());
        printf("%d",result[result.size()-1]);
        for (int i=result.size()-2;i>=0;--i){
            printf(" %d",result[i]);
        }
        printf("\n");

    }

}

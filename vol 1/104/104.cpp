#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

double d[30][30];
int intermidiate[30][30];
int length[30][30];

vector<int> series[30];
int cnt;
void getPath(int a,int b){
    if (intermidiate[a][b]== -1)
        return ;
    getPath(a,intermidiate[a][b]);
    series[cnt].push_back(intermidiate[a][b]);
    getPath(intermidiate[a][b],b);
}

int main(){
    freopen("in.txt","r",stdin);

    int n;

    while (scanf("%d",&n)==1){

        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j){
                if (i==j)
                    d[i][j]=1;
                else
                    scanf("%lf",&d[i][j]);
            }
        }
        for (int i=1;i<=n;++i)
            series[i].clear();

        for (int i=1;i<=n;++i)
                for (int j=1;j<=n;++j){
                    intermidiate[i][j]=-1;
                    length[i][j]=1;
                }

        for (int k=1;k<=n;++k)
            for (int i=1;i<=n;++i)
                for (int j=1;j<=n;++j){
                    if ( d[i][k]*d[k][j] > d[i][j] /*&&  length[i][j] > length[i][k]+length[k][j]*/  ){
                        d[i][j]=d[i][k]*d[k][j];
                        length[i][j] = length[i][k]+length[k][j];
                        intermidiate[i][j]=k;
                    }
                }
        cnt=0;
        for (int i=1;i<=n;++i){

            printf("%lf\n",d[i][i]);
            if (d[i][i]>1.01){
                //printf("%d\n",length[i][i]);
                //getPath( i, i);
                cnt++;
            }
        }


    }
}

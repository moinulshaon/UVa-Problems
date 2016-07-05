#include <cstdio>
#include <cstring>

#define sz 110
#define max(a,b) ((a)>(b))?(a):(b)

int d[sz][sz];

int main(){
    //freopen("in.txt","r",stdin);

    int nodes,start,a,b;

    for (int kase=1;scanf("%d",&nodes) && nodes;++kase){
        memset(d,0,sizeof(d));

        scanf("%d",&start);

        while (scanf("%d %d",&a,&b) && a && b){
            d[a][b]=1;
        }

        for (int k=1;k<=nodes;++k){
            for (int i=1;i<=nodes;++i){
                for (int j=1;j<=nodes;++j){
                    if ( d[i][k] && d[k][j] )
                    d[i][j]=max( d[i][j] ,d[i][k]+d[k][j]);
                }
            }
        }
        int maxNode=start,maxStep=0;

        for (int i=1;i<=nodes;++i){
            if (d[start][i]>maxStep){
                maxNode=i;
                maxStep=d[start][i];
            }
        }

        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",kase,start,maxStep,maxNode);

    }
    return 0;

}

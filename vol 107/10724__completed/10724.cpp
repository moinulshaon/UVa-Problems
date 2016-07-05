#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

#define INF 100000000

using namespace std;

struct pp{
    int x,y;
}point[60];
double d[60][60];

double computeDistance( int a,int b ){
    return sqrt(  ( point[a].x-point[b].x)*( point[a].x-point[b].x) + ( point[a].y-point[b].y)*( point[a].y-point[b].y) );
}

int main(){
    freopen("in.txt","r",stdin);

    int n,e,a,b;

    while (true){
        scanf("%d %d",&n,&e);

        if  (!n && !e)return 0;

        for(int i=0;i<=n;++i)
            for(int j=0;j<=n;++j)
                d[i][j]=INF;
        for(int i=0;i<=n;++i)
            d[i][i]=0;

        for (int i=1;i<=n;++i)
            scanf("%d %d",&point[i].x,&point[i].y);
        while ( e-- ){
            scanf("%d %d",&a,&b);

            d[a][b]=d[b][a]=computeDistance( a,b );
        }

        for (int k=1;k<=n;++k)
            for (int i=1;i<=n;++i)
                for (int j=1;j<=n;++j)
                    d[i][j]=min( d[i][j],d[i][k]+d[k][j] );

        int start,destination;
        double maxSave=-INF;

        for (int i=1;i<=n;++i){
            for (int j=i+1;j<=n;++j){

                if (  (d[i][j]-INF)< 1e-5 ){
                    double save=0;

                    for (int p=1;p<=n;++p){
                        for (int q=p+1;q<=n;++q){
                            double tmp=computeDistance(i,j);
                            save+=  d[p][q]-min( min(  d[p][i]+tmp+d[j][q] , d[p][j]+tmp+d[i][q] ) ,d[p][q] );
                        }
                    }
                    //printf("%d %d %lf\n",i,j,save);
                    if (save>maxSave){
                        maxSave=save;
                        start=i;
                        destination=j;
                    }

                }
            }
        }

        if (maxSave && maxSave!=-INF){
            printf("%d %d\n",start,destination);
        }
        else
            printf("No road required\n");

    }

}

#include <cstdio>
#include <cmath>
#include <algorithm>

#define sz 110
#define INF 100000000

using namespace std;

double d[sz][sz];

struct ppp{
    int x,y;
}point[sz];

double computeDistance(int a,int b){
    double tmp=sqrt( pow( point[a].x-point[b].x,2 )+pow( point[a].y-point[b].y,2 ) );
    return (tmp>10)?INF:tmp;
}

int main(){
    freopen("in.txt","r",stdin);

    int kase,total;
    scanf("%d",&kase);

    for (int in=1;kase--;++in){
        scanf("%d",&total);

        for (int i=0;i<total;++i){
            scanf("%d %d",&point[i].x,&point[i].y);
        }

        for (int i=0;i<total;++i)
            for (int j=i+1;j<total;++j)
                d[i][j]=0;

        for (int i=0;i<total;++i){
            for (int j=i+1;j<total;++j){
                d[i][j]=d[j][i]=computeDistance( i,j );
                //printf("%d %d %.3lf\n",i,j,d[i][j]);
            }
        }

        for (int k=0;k<total;++k){
            for (int i=0;i<total;++i){
                for (int j=0;j<total;++j){
                    d[i][j]=min( d[i][j], d[i][k] + d[k][j]);
                }
            }
        }

        bool pos=true;
        double maxDistance=0;
        for (int i=0;i<total;++i)
                for (int j=0;j<total;++j){
                    if (fabs( d[i][j]-INF)<1e-5 )
                        pos=false;
                    maxDistance=max( maxDistance,d[i][j] );
                }
        printf("Case #%d:\n",in);
        if (pos)
            printf("%.4lf\n\n",maxDistance);
        else
            printf("Send Kurdy\n\n");
    }
    return 0;
}

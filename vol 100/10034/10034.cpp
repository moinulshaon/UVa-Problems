#include <cmath>
#include <cfloat>
#include <cstdio>
#include <iostream>
#define MAX_N 101

using namespace std;





double w[MAX_N][MAX_N];
double dist[MAX_N];
double parent[MAX_N];
bool visit[MAX_N];
double p[MAX_N][2];
double distance(double x1,double y1,double x2, double y2)
{
        return sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}
int main()
{
        int tc,n;
        int i,j;
        scanf("%d",&tc);
        while(tc--)
        {
                scanf("%d",&n);
                for (i=0;i<n;i++)
                        scanf("%lf %lf",&p[i][0],&p[i][1]);
                for(i=0;i<n;i++) {
                   for(j=i;j<n;j++) {
                        w[i][j] = distance(p[i][0],p[i][1],p[j][0],p[j][1]);
                        w[j][i] = w[i][j];
                        }
                }
                for (i=0;i<n;i++) {
                        visit[i]=false;
                        dist[i] = DBL_MAX;
                }
                dist[0] = 0.0;
                double out=0;
                parent[0] = 0;
                for ( i = 0; i<n; i++ ) {
                        int nc=-1;
                        double min=DBL_MAX;
                        for (j=0;j<n;j++)
                        if (!visit[j] && dist[j]<min ) {
                                nc=j;
                                min=dist[j];
                        }

                        if (  nc == -1 ) break;
                        visit[nc] = true;
                        out+=min;
                        for ( int t=0;t<n;t++)
                                if ( !visit[t] && w[nc][t] && w[nc][t] < dist[t] )
                                {
                                        dist[t] = w[nc][t];
                                        parent[t] = nc;
                                }
                }
                printf("%.2lf\n",out);
                if ( tc != 0 ) printf("\n");
        }
        return 0;
}

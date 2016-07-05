#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <cmath>
#define radian(a) (3.141592653589793*a/180)
#define INF 10000000
#define min(a,b) ((a)<(b))?(a):(b)

using namespace std;

struct place
{
    double x,y;
}a[100+10];
int mat[110][110];



int dis(double lt1,double ln1,double lt2,double ln2)
{
      double lat1=radian(lt1);
      double lat2=radian(lt2);
      double lon1=radian(ln1);
      double lon2=radian(ln2);
      double dis=acos(sin(lat1)*sin(lat2)+cos(lat1)*cos(lat2)*cos(lon2-lon1));
      return int((dis*6378)+0.5);
}


int main()
{

    freopen("in.txt","r",stdin);

    int N,M,Q;

    for (int m=1;;++m)
    {
        scanf("%d %d %d",&N,&M,&Q);

        if (!N && !M && !Q)return 0;

        map <string,int> ind;

        string str,str2;
        double p,q;
        for (int i=0; i<N ;++i)
        {
            cin>>str>>p>>q;

            ind[str]=i;
            a[i].x=p;
            a[i].y=q;
        }

        for (int i=0;i<N;++i)
            for (int j=0;j<N;++j)
                mat[i][j]=INF;

        for (int i=0;i<M;++i)
        {
            cin>>str>>str2;

            mat[ind[str]][ind[str2]]=dis(a[ind[str]].x,a[ind[str]].y,a[ind[str2]].x,a[ind[str2]].y);
        }

        for (int  k = 0; k < N; k++ )
            for (int  i = 0; i < N; i++ )
                for (int  j = 0; j < N; j++ )
                    mat [i] [j] = min (mat [i] [j],  mat [i] [k]+ mat [k] [j]);

        if (m!=1)
            printf("\n");

        printf("Case #%d\n",m);

        while (Q--)
        {
            cin>>str>>str2;

            if (mat[ind[str]][ind[str2]]!=INF)
                printf("%d km\n",mat[ind[str]][ind[str2]]);
            else
                printf("no route exists\n");
        }
    }
    return 0;

}

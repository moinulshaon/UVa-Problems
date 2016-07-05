#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define INF 100000000

using namespace std;

int d[110][110];
int sum[110];

int main(){
    freopen("in.txt","r",stdin);

    int kase,n,e,a,b,c;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&n,&e);

        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
                d[i][j]=INF;

        for (int i=1;i<=n;++i)
            d[i][i]=0;

        while (e--){
            scanf("%d %d %d",&a,&b,&c);
            d[a][b]=d[b][a]=min( d[a][b],c  );
        }

        for (int k=1;k<=n;++k)
            for (int i=1;i<=n;++i)
                for (int j=1;j<=n;++j)
                    d[i][j]=min( d[i][j],d[i][k]+d[k][j] );

        memset(sum,-1,sizeof(sum));

        for (int i=1;i<=5;++i){
            for (int j=1;j<=n;++j){
                if (sum[j]==-1)
                    sum[j]=d[i][j];
                else if (  sum[j]!=d[i][j])
                    sum[j]=INF;
            }
        }

        vector<int> possiblePlace;
        for (int i=1;i<=n;++i)
            if (sum[i]!=INF)
                possiblePlace.push_back( i );



        int result=INF;
        for (int i=0;i<possiblePlace.size();++i){
            int longest=0;
            for (int j=1;j<=n;++j){
                if (longest< d[ possiblePlace[i] ][j] )
                    longest= d[ possiblePlace[i] ][j];
            }

            if (longest<INF)
                result=min( result, longest );
        }
        if (result==INF)result=-1;
        printf("Map %d: %d\n",kk,result);
    }
    return 0;
}

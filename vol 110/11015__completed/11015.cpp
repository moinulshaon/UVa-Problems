#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>

#define INF 100000000

using namespace std;

int main(){
    freopen("in.txt","r",stdin);

    int n,m,a,b,c;
    register int i , j ,k ;
    string str;
    int d[30][30];

    for (int kk=1;scanf("%d %d",&n,&m)==2;++kk){
        map<string,int> myp;
        map<int,string> rmyp;

        if (!n && !m)break;

        for (i=1;i<=n;++i){
            cin>>str;
            myp[str]=i;
            rmyp[i]=str;
        }

        for (i=1;i<=n;++i)
            for (j=1;j<=n;++j)
                d[i][j]=INF;
        for (i=1;i<=n;++i)
            d[i][i]=0;
        while (m--){
            scanf("%d %d %d",&a,&b,&c);
            d[a][b]=d[b][a]=min( c ,d[b][a] );
        }

        for (k=1;k<=n;++k)
            for ( i=1;i<=n;++i)
                for ( j=1;j<=n;++j)
                    d[i][j]=min( d[i][j] ,d[i][k]+d[k][j] );
        int sum=INF,ind=1;

        for (i=1;i<=n;++i){
            int tmp=0;
            for ( j=1;j<=n;++j)
                tmp+=d[j][i];
            if (tmp<sum){
                sum=tmp;
                ind=i;
            }
        }

        printf("Case #%d : ",kk);
        cout<<rmyp[ind]<<endl;

    }
    return 0;

}

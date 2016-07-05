#include <cstdio>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 55

int d[SIZE][SIZE];
double ans[SIZE][SIZE];
int step[SIZE][SIZE];
const int INF=(1<<30);

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int v,e,p,q,w;
        scanf("%d %d",&v,&e);

        for (int i=0;i<=v;++i){
            for (int j=0;j<=v;++j){
                d[i][j] = INF;
                step[i][j]= 0;
                ans[i][j]= INF;
            }
        }

        while( e-- ){
            scanf("%d %d %d",&p,&q,&w);
            d[p][q]= min( d[p][q],w );
            step[p][q] = 1;
            ans[p][q]= d[p][q] ;
        }
        double ff=INF;
        for (int k = 1; k <=v; k++ ) {
            for (int  i = 1; i <=v; i++ ) {
                for (int  j = 1; j <= v; j++ ){
                    if ( step[i][k]!= 0 && step[k][j]!=0 ){
                        double tmp=ans[i][j];
                        ans[i][j]= min( ans[i][j], ( ans[i][k]*step[i][k]+ans[k][j]*step[k][j] )/( step[i][k]+step[k][j] ) );

                        if ( ans[i][j] < tmp ){
                            step[i][j]=step[i][k]+step[k][j];
                        }
                    }
                }
            }
        }

        for (int  i = 1; i <=v; i++ ) {
            for (int  j = 1; j <= v; j++ ){
                ff=min( ff,( ans[i][j]*step[i][j]+ans[j][i]*step[j][i] )/( step[i][j]+step[j][i] )  );
            }
        }


        if ( ff>= INF-1 ){
            printf("Case #%d: No cycle found.\n",kk);
        }else{
            printf("Case #%d: %.2lf\n",kk,ff);
        }


    }


    return 0;
}

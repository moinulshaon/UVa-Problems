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
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 103

double tbl[SIZE][SIZE];

bool ok;

void gauss( int eqn ){

    //doing forward elimination

    int mx;
    for (int i=0;i<eqn;++i){
        mx=i;
        for (int j=i+1;j<eqn;++j){
            if ( fabs( tbl[j][i] ) > fabs( tbl[mx][i] ) ){
                mx=j;
            }
        }

        if ( mx!=i ){
            for ( int j=0;j<=eqn;++j ){
                swap( tbl[i][j],tbl[mx][j] );
            }
        }

        if ( fabs( tbl[i][i] )<1e-6 ){
            ok=false;
            return ;
        }

        for (int j = eqn ; j >= i; --j){
            for (int k = i + 1; k < eqn; ++k){
                tbl[k][j] -= tbl[k][i]/tbl[i][i] * tbl[i][j];
            }
        }
    }

    //doing backword elimination
    for (int i = eqn - 1; i >= 0; --i) {
        if ( fabs( tbl[i][i] )<1e-6 ){
            ok=false;
            return ;
        }
        tbl[i][eqn] = tbl[i][eqn] / tbl[i][i];
        tbl[i][i] = 1;
        for (int j = i - 1; j >= 0; --j) {
            tbl[j][eqn] -= tbl[j][i] * tbl[i][eqn];
            tbl[j][i] = 0;
        }
    }
}

vector<int> edge[SIZE];

int main(){
    FRO

    int n;

    while ( scanf("%d",&n) == 1 && n ){
        int u,v;

        for (int i=0;i<n;++i){
            edge[i].clear();
        }

        while ( scanf("%d %d",&u,&v) && (u+v) ){
            u--;
            v--;
            edge[ u ].PB( v );
        }

        CLR(tbl);

        for (int i=0;i<n;++i){
            tbl[i][i] += 1;
            int sz= edge[i].size();

            for (int j=0;j<sz;++j){
                tbl[ edge[i][j] ][ i ] += -1.0/sz;
            }
        }

        tbl[ 0 ][ n ] = 1;

        ok=true;
        //gauss(n);

        int qq;
        scanf("%d",&qq);

        int x;
        while ( qq-- ){
            scanf("%d",&x);
            printf("%lf\n",tbl[x][n]);
        }
    }



    return 0;
}

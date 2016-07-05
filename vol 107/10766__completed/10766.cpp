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
#include <iomanip>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 52

long double tbl[SIZE][SIZE];

const long double EPS= 1e-8;


long double gauss( int n ){

    //prnt();

    //doing forward elimination

    int mx;

    long double ans=1;

    for (int i=0;i<n;++i){
        mx=i;
        for (int j=i+1;j<n;++j){
            if ( fabs(tbl[j][i])  > fabs(tbl[mx][i]) ){
                mx=j;
            }
        }

        if ( mx!=i ){
            for ( int j=0;j<n;++j ){
                swap( tbl[i][j],tbl[mx][j] );
            }
            ans= -ans;
        }

        if ( fabs( tbl[i][i] )<EPS){
            return 0;
        }
        //cout<<"ss "<<tbl[i][i]<<endl;

        //prnt();

        for (int j = n-1 ; j >= i; --j){
            for (int k = i + 1; k < n; ++k){
                tbl[k][j] =tbl[k][j]- tbl[k][i] * tbl[i][j]/tbl[i][i];
            }
        }
        //prnt();

    }
    /*
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            printf("  %lf",tbl[i][j]);
        }printf("\n");
    }
    */
    //doing backword elimination
    for (int i=0;i<n;++i){
        ans*= tbl[i][i];
    }

    return ans;
}
int deg[52];

set<int> shaon[52];

int main(){

    FRO

    int n,m,k;
    while ( scanf("%d %d %d",&n,&m,&k)==3 ){

        for (int i=0;i<n;++i){
            deg[i] = n-1;
            shaon[i].clear();
        }

        int u,v;

        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                tbl[i][j] = -1;
            }
        }

        while ( m-- ){
            scanf("%d %d",&u,&v);
            u--,v--;

            if ( shaon[u].find( v ) != shaon[u].end() )continue;
            if ( shaon[v].find( u ) != shaon[v].end() )continue;

            deg[u]--;
            deg[v]--;

            tbl[u][v]= 0;
            tbl[v][u]= 0;

            shaon[u].insert(v);
            shaon[v].insert(u);
        }

        for (int i=0;i<n;++i){
            tbl[i][i] = deg[i];

            //cout<<deg[i]<<endl;
        }

        //prnt();


        cout<<fixed<<setprecision(0)<<fabs( gauss(n-1) )+EPS<<endl ;

    }


    return 0;
}

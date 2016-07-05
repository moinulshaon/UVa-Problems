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


#define SIZE 33

double tbl[SIZE][SIZE];


double gauss( int n ){

    //doing forward elimination

    int mx;

    double ans=1;

    for (int i=0;i<n;++i){
        mx=i;
        for (int j=i+1;j<n;++j){
            if ( fabs( tbl[j][i] ) > fabs( tbl[mx][i] ) ){
                mx=j;
            }
        }

        if ( mx!=i ){
            for ( int j=0;j<n;++j ){
                swap( tbl[i][j],tbl[mx][j] );
            }
            ans*= -1;
        }

        if ( fabs( tbl[i][i] )<1e-6 ){
            return 0;
        }

        for (int j = n-1 ; j >= i; --j){
            for (int k = i + 1; k < n; ++k){
                tbl[k][j] -= tbl[k][i]/tbl[i][i] * tbl[i][j];
            }
        }

    }

    //doing backword elimination
    for (int i=0;i<n;++i){
        //cout<<tbl[i][i]<<endl;
        ans*= tbl[i][i];
    }

    return ans;
}


int main(){

    int n;
    while ( scanf("%d",&n) == 1 && n ){

        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                scanf("%lf",&tbl[i][j]);
            }
        }

        printf("%.0lf\n",gauss( n )+1e-6 );
    }

    printf("*\n");


    return 0;
}

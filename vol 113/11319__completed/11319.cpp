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


#define SIZE 10

long double tbl[SIZE][SIZE];


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
            exit(5);
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
            exit(5);
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

unsigned long long arr[1510];
unsigned long long sol[10];
int main(){
    FRO

    int kase;
    scanf("%d",&kase);
    while ( kase-- ){
        for (int i=0;i<1500;++i){
            scanf("%llu",&arr[i]);
        }

        for (int i=0;i<7;++i){
            for (int j=0;j<7;++j){
                tbl[i][j] = pow( i+1,j );
            }
        }

        for (int i=0;i<7;++i){
            tbl[i][7]=arr[i];
        }

        gauss(7);

        bool ok=true;

        for (int i=0;i<7;++i){
            if ( tbl[i][7]< -1e-7 || tbl[i][7]>1000+1e-7 ||fabs( tbl[i][7]-floor( tbl[i][7]+1e-7 ) ) >1e-7 ){
                ok=false;
                //cout<<tbl[i][7]<<' '<<fabs( tbl[i][7]-floor( tbl[i][7]+1e-7 ) )<<endl;
                break;
            }
            sol[i]= tbl[i][7] + 1e-6;
        }


        for (int i=0;i<1500 && ok;++i){
            for (int j=1;j<7 && ok ;++j){
                if ( arr[i]>=sol[j-1] ){
                    arr[i]=arr[i]-sol[j-1];
                }else{
                    ok=false;
                }

                if ( arr[i]%(i+1)!=0 ){
                    ok=false;
                }else{
                    arr[i]=arr[i]/(i+1);
                }
            }
            if ( arr[i]!=0 )ok=false;
        }

        if ( !ok )printf("This is a smart sequence!\n");
        else{
            for (int i=0;i<7;++i){
                if ( i )printf(" ");
                printf("%llu",sol[i]);
            }
            printf("\n");
        }
    }


    return 0;
}

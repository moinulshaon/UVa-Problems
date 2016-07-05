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

#define SIZE 40

double tbl[SIZE][SIZE];

const double EPS= 1e-6;


double gauss( int n ){

    //prnt();

    //doing forward elimination

    int mx;

    double ans=1;

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


int num[SIZE][SIZE];

int dr[]={-1,-1,-1 , 0,0  , 1,1,1};
int dc[]={0,1,-1   , -1,1 , 0,-1,1 };

int main(){

    //FRO

    int n,m,k;
    int kase;
    scanf("%d",&kase);
    while ( kase-- ){

        CLR( deg );
        CLR( tbl );

        //cout<<tbl[0][0]<<endl;

        int dd;
        scanf("%d",&dd);

        int cnt = 0;
        for (int i=0;i<dd;++i){
            for (int j=0;j<dd;++j){
                num[i][j] = cnt++;
            }
        }

        //cout<<cnt<<endl;

        for (int i=0;i<dd;++i){
            for (int j=0;j<dd;++j){
                for (int k=0;k<8;++k){

                    int rr= i+dr[k];
                    int cc= j+dc[k];

                    if ( rr>=0 && rr<dd && cc>=0 && cc<dd ){
                        deg[ num[i][j] ]++;
                        deg[ num[rr][cc] ]++;

                        tbl[ num[i][j] ][ num[rr][cc] ] = -1;
                        tbl[ num[rr][cc] ][ num[i][j] ] = -1;
                    }

                }
            }
        }

        for (int i=0;i<cnt;++i){
            tbl[i][i] = deg[i]/2;
            //cout<<deg[i]<<endl;
        }
        /*
        for (int i=0;i<cnt;++i){
            for (int j=0;j<cnt;++j){
                cout<<tbl[i][j]<<"   ";
            }cout<<endl;
        }
        */
        //prnt();


        cout<<fixed<<setprecision(0)<<fabs( gauss(cnt-1) )+EPS<<endl ;

    }


    return 0;
}

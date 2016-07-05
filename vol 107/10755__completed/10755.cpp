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

#define SIZE 22

LL sum[SIZE][SIZE][SIZE];

LL func( int x1,int y1,int z1,int x2,int y2,int z2 ){

    return sum[x2][y2][z2]
    - sum[x1-1][y2][z2] - sum[x2][y1-1][z2] - sum[x2][y2][z1-1]
    + sum[ x1-1 ][ y1-1 ][z2] +  sum[x1-1][y2][z1-1] + sum[x2][y1-1][z1-1]
    - sum[x1-1][y1-1][z1-1];

}


int main(){

    int kase;
    scanf("%d",&kase);


    for (int kk=1;kase--;++kk){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);

        CLR(sum);

        for (int i=1;i<=x;++i){
            for (int j=1;j<=y;++j){
                for (int k=1;k<=z;++k){
                    scanf("%lld",&sum[i][j][k]);
                    sum[i][j][k]+= sum[i-1][j][k] + sum[i][j-1][k] + sum[i][j][k-1]
                                    - sum[i-1][j-1][k] - sum[i-1][j][k-1] - sum[i][j-1][k-1]
                                    + sum[ i-1 ][j-1][k-1];
                }
            }
        }

        LL ans = -(1LL<<50);

        for (int a=1;a<=x;++a){
            for (int b=1;b<=y;++b){
                for (int c= 1;c<=z;++c){


                    for (int p=a;p<=x;++p){
                        for (int q=b;q<=y;++q){
                            for (int r=c;r<=z;++r){
                                ans = max( ans, func( a,b,c,p,q,r ) );
                            }
                        }
                    }

                }
            }
        }

        printf("%lld\n",ans);

        if ( kase )printf("\n");

    }

    return 0;
}

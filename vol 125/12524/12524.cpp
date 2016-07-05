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

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 1010

LL weight[SIZE],dist[SIZE];
LL cumw[SIZE];


LL dp[SIZE][SIZE];

LL cost[SIZE][SIZE];


void compute( int k,int low,int high,int cutlow,int cuthigh ){
    if ( low>high )return ;

    int mid = (low+high)/2;

    dp[k][mid] = (1LL<<55);

    //cout<<low<<" "<<high<<" "<<cutlow<<" "<<cuthigh<<endl;

    int cut = -1;
    for (int i=cutlow;i<=cuthigh && i+1<=high ;++i){

        LL cc = dp[k-1][i]+cost[i+1][mid];
        if ( cc<dp[k][mid] ){
            dp[k][mid] = cc;
            cut = i;
        }
    }

    compute( k,low,mid-1,cutlow,cut );
    compute( k,mid+1,high,cut,cuthigh );
}

int main(){

    FRO

    int n,k;
    while ( scanf("%d %d",&n,&k)==2 ){


        cumw[0] = 0;
        for (int i=1;i<=n;++i){
            scanf("%lld %lld",&dist[i],&weight[i]);
            cumw[i]= cumw[i-1]+weight[i];
        }

        for (int r=1;r<=n;++r){
            cost[r][r] = 0;
            for (int l=r-1;l>0;--l){
                cost[l][r] = cost[l+1][r] + ( dist[r]-dist[l] )*weight[l];
            }
        }

        for(int i=1;i<=n ;i++ ){
            dp[1][i] = cost[1][i];
        }
        for (int i=2;i<=k;++i){
            compute( i,1,n,0,n-1 );
        }

        printf("%lld\n",dp[k][n]);
    }


    return 0;
}

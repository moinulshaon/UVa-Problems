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


#define SIZE 203

double pre[SIZE][SIZE];
double arr[SIZE];
int n;

bool vis[SIZE][SIZE];
double dp[SIZE][SIZE];

double func(int totake,int left){

    if ( left==1 ){
        return pre[totake][n-1];
    }
    if ( totake >= n-1 ){
        return 0;
    }

    double &ret=dp[totake][left];
    if ( vis[totake][left] )return ret;

    vis[totake][left]=true;

    ret=(1<<29);
    for (int i=totake+1;i<n;++i){
        ret=min( ret , pre[totake][i]+func( i,left-1 ) );
    }
    return ret;
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int q;
        scanf("%d %d",&n,&q);
        for (int i=0;i<n;++i){
            scanf("%lf",&arr[i]);
        }

        for (int i=0;i<n;++i){
            for (int j=i+1;j<n;++j){
                pre[i][j] = 0;
                for (int k=i+1;k<j;++k){
                    pre[i][j] += fabs( arr[k] - ( arr[i]+ (  arr[j]-arr[i] )*( k-i )/( j-i ) ) );
                }
            }
        }
        //cout<<"shaon\n";
        CLR(vis);

        printf("%.4lf\n",func( 0,q-1 )/n);
    }

    return 0;
}

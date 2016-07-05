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

int Set(int N,int pos){
    return N=N | (1<<pos);
}
int Reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool Check(int N,int pos){
    return (bool)(N & (1<<pos));
}


double tab[15][15];

int n;

pint range[15];
int arr[15];

double dp[1<<13][13];
bool vis[1<<13][13];

double func( int state,int totake ){

    if ( totake == n )return 1;

    double &ret = dp[state][totake];

    if ( vis[state][totake] )return ret;
    vis[state][totake] = true;

    ret = 0;
    for (int i=0;i<5;++i){
        for (int j=range[i].X;j<=range[i].Y;++j){
            if ( Check( state,j )==0 ){
                ret += tab[totake][i] * func( Set(state,j), totake+1 );
            }
        }
    }
    return ret;
}

int main(){

    //FRO

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){
        scanf("%d",&n);
        int cnt = 0;
        for (int i=0;i<5;++i){
            scanf("%d",&arr[i]);
            range[i].X = cnt;
            range[i].Y = cnt+arr[i]-1;
            cnt += arr[i];
        }

        for (int i=0;i<n;++i){
            for (int j=0;j<5;++j){
                scanf("%lf",&tab[i][j]);
            }
        }

        CLR(vis);
        double sum[5] = {0};
        double shaon = 0;
        for (int i=0;i<5;++i){
            for (int j=range[i].X;j<=range[i].Y;++j){
                sum[i] += tab[0][i] * func( Set( 0,j ) , 1 );
            }
            //cout<<i<<" "<<sum[i]<<endl;
            shaon += sum[i];
        }

        double max_r = 0;
        int ind = 0;

        for (int i=0;i<5;++i){
            if ( sum[i] / ( arr[i] * shaon ) > max_r ){
                max_r = sum[i]/ ( arr[i] * shaon );
                ind = i;
            }
        }


        printf("%d %.3lf\n",ind+1,max_r);

    }


    return 0;
}

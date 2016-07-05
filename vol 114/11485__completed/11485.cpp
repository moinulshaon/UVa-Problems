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

#define SIZE 102
#define LIM 8

LL dp[LIM][9*SIZE+10];
int n;
int arr[SIZE];

LL func( int totake,int sum ){
    if ( totake == LIM ){
        return int(sum/10)*10;
    }
    LL &ret=dp[totake][sum];

    if (ret != -1)return ret;

    ret = 0;
    for (int i=0;i<n;++i){
        ret += func( totake+1,sum+(arr[i]%10) );
    }
    return ret;
}

int main(){

    //FRO

    while ( scanf("%d",&n) ==1 && n ){
        double tmp;
        for (int i=0;i<n;++i){
            scanf("%lf",&tmp);
            arr[i] = tmp*10+1e-6;
        }
        NEG(dp);

        printf("%lld\n",func( 0,0 )/10);
    }


    return 0;
}

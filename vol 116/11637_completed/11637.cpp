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

#define SIZE 200100

double dp[SIZE];



int main(){



    int n,k;
    for (int kk=1; scanf("%d %d",&n,&k)==2 && (n+k) ;++kk ){
        dp[0] = 1;
        for (int i=1;i<=2*k && i<= n-1-2*k ;++i){
            dp[i] = dp[i-1] * (n-1-2*k-i+1) / ( n-1-i+1 );
        }

        double ans = n;
        for (int i=1;i<=n;++i){
            int le = min(k,i-1);
            int ri = min(k,n-i);
            int x= le+ri;
            if ( n-1-2*k >= x ){
                ans -= dp[x];
            }
        }
        if ( n == 1 )ans = 0;

        printf("Case %d: %.4lf\n",kk,ans);
    }


    return 0;
}

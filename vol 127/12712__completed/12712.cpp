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

LL mod= 10000000000007LL;

int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        LL n,m,k;
        scanf("%lld %lld %lld",&k,&m,&n);
        k=k*k;

        LL ans = 1;

        for (LL tt=k;tt>(k-m);--tt ){
            ans= (ans*tt)%mod;
        }
        LL tmp = ans ;

        for (  LL tt = m+1;tt<=n;++tt ){
            tmp=( tmp * ( k-tt+1 ) )%mod;
            ans=( ans+tmp )%mod;
        }

        printf("Case %d: %lld\n",kk,ans);

    }


    return 0;
}

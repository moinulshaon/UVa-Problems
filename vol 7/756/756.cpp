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

LL r[5],p[5];

int main(){

        int n;
        scanf("%d",&n);

        LL mul = 1;
        for (int i=0;i<n;++i){
            scanf("%lld %lld",&p[i],&r[i]);
            mul *= p[i];
        }
        LL ans = 0;
        for (int i=0;i<n;++i){
            ans=( ans+ r[i] * overflowmod ( ( mul/p[i] ) , BigMod( (mul/p[i])%p[i] ,p[i]-2,p[i] ) , mul ) )%mul;
        }
        printf("Case %d: %lld\n",kk,ans);


    return 0;
}

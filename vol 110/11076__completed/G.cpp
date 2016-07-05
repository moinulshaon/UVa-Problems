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

typedef unsigned long long LLU;

LLU fact[15];
LLU pp[15];
LLU cnt[ 10 ];

int main(){

    fact[0]=1;
    pp[0]=1;

    for (int i=1;i<15;++i){
        fact[i] = fact[i-1] * i;
        pp[i]= pp[i-1]*10;
    }

    int n;
    while ( scanf("%d",&n) ==1 && n ){
        CLR(cnt);
        int tmp;
        for (int i=0;i<n;++i){
            scanf("%d",&tmp);
            cnt[ tmp ]++;
        }

        LLU ss = 1;
        for (int i=0;i<10;++i){
            ss*= fact[ cnt[i] ];
        }


        LLU ans = 0;
        for (int i=0;i<10;++i){
            if ( !cnt[i] )continue;
            for (int j=0;j<n;++j){
                ans+= pp[j]*i*( fact[ n ] /ss )*(cnt[i])/n;
            }
            //cout<<i<<' '<<ans<<endl;
        }
        printf("%llu\n",ans);
    }

    return 0;
}

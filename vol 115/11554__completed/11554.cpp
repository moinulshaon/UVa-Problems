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

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define SIZE 1000001


LL ans[SIZE];

int main(){
    ans[1]=1;
    for (int i=2;i<SIZE;++i){
        if ( i%2==0 ){
            ans[i]=ans[i-1]+ (i/2);
        }else{
            ans[i]=ans[i-1]+ (i+1)/2;
        }
    }

    for (int i=2;i<SIZE;++i){
        ans[i]+=ans[i-1];
    }

    int n,kase;
    scanf("%d",&kase);

    while (kase--){
        scanf("%d",&n);
        printf("%lld\n",ans[n-3]);
    }

    return 0;
}

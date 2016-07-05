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

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

LL tmp;
set<LL> ss;
int func(){
    int cnt=0;
    while( tmp ){
        //printf("%lld %lld\n",tmp,*(ss.upper_bound(tmp)));
        //getchar();
        set<LL>::iterator it=ss.upper_bound(tmp);
        it--;
        tmp-= *(it);
        ++cnt;
    }
    return cnt;
}

int main(){
    //FRO


    LL fib[100];
    fib[0]=1;
    fib[1]=1;

    ss.insert(1);
    for (int i=2;fib[i-1]<=2000000000;++i){
        fib[i]=fib[i-1]+fib[i-2];
        ss.insert(fib[i]);
        //printf("%d %lld\n",i,fib[i]);
    }

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int dim;
        scanf("%d",&dim);
        int ans=0;
        for (int i=0;i<dim;++i){
            scanf("%lld",&tmp);
            ans=max(ans,func());
        }
        printf("Case %d: %d\n",kk,ans);
    }
    return 0;
}

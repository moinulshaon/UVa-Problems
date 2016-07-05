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

#define SIZE 1005

int cnt[SIZE];

int ans[SIZE];

int main(){

    FRO

    for (int i=1;i<SIZE;++i){
        for (int j=i;j<SIZE;j+=i){
            cnt[ j ] += i;
        }
    }

    NEG(ans);
    for (int i=SIZE-1;i>=0;--i){
        if ( cnt[i]<SIZE && ans[ cnt[i] ] == -1 ){
            ans[ cnt[i] ] = i;
        }
    }

    int n;
    for (int kk=1; scanf("%d",&n) == 1 && n ; ++kk ){
        printf("Case %d: %d\n",kk,ans[n]);
    }


    return 0;
}

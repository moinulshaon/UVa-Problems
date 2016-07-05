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

mint mp;

int main(){

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){

        mp.clear();

        int tmp,n,m;
        scanf("%d %d",&n,&m);

        while ( n-- ){
            scanf("%d",&tmp);
            mp[ tmp ]++;
        }


        while ( m-- ){
            scanf("%d",&tmp);
            mp[ tmp ]--;
        }

        int ans = 0;

        for ( mint::iterator it = mp.begin();it != mp.end(); ++it ){
            ans += abs( it->second );
        }
        printf("%d\n",ans);
    }


    return 0;
}

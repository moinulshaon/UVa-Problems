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



int main(){



    int n,b,h,w;
    while ( ~scanf("%d %d %d %d",&n,&b,&h,&w) ){

    int ans = INT_MAX;

    while ( h-- ){
        int tmp;
        int per;
        scanf("%d",&per);

        for (int i=0;i<w;++i){
            scanf("%d",&tmp);
            if ( per*n <=b && tmp>= n ){
                ans = min( ans, per*n );
            }
        }
    }
    if ( ans  != INT_MAX )
        printf("%d\n",ans);
    else
        printf("stay home\n");
    }
    return 0;
}

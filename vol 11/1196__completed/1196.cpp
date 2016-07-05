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

int tree[105];
int MaxVal=104;

int read(int idx){
	int sum = 0;
	while (idx > 0){
		sum = max(sum,tree[idx]);
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx ,int val){
	while (idx <= MaxVal){
		tree[idx] = max( tree[idx],val);
		idx += (idx & -idx);
    }
}

int main(){

    FRO

    int n;
    while ( scanf("%d",&n) == 1 && n ){

        vector<pint> vec;
        int a,b;
        for (int i=0;i<n;++i){
            scanf("%d %d",&a,&b);
            vec.PB( MP(a,b) );
        }
        sort( vec.begin(),vec.end() );

        CLR(tree);

        int ans = 0;
        for (int i=0;i<n;++i){
            int tmp = 1+read( vec[i].Y );
            ans = max( ans , tmp );
            update( vec[i].Y , tmp );
        }
        printf("%d\n",ans);
    }
    printf("*\n");

    return 0;
}

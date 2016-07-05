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

    freopen("in.txt","w",stdout);

    int kase=1;
    printf("%d\n",kase);

    while ( kase-- ){
        int n=200;
        int q= n-10;

        printf("%d %d\n",n,q);
        for (int i=0;i<n;++i){
            printf("%d ",i+100);
        }
        printf("\n");

    }

    return 0;
}

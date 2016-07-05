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

int main() {


    int n;

    for (n=1; n<50; ++n) {


        int cnt = 0;
        for (int i=1; i<=n; ++i) {
            for (int j=i; j<=n; ++j) {
                if (  __gcd(i,j) == (i^j) ) {
                    //printf("%d %d\n",i,j);
                    cnt++;
                }
            }
        }

        cout<<n<<' '<<cnt<<endl;
    }



    return 0;
}

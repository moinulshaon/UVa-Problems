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

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n;
        LL num = 0,den = 1;

        scanf("%d",&n);

        int x,y;
        while ( n-- ){
            scanf("%d %d",&y,&x);
            den = den*y;
            num = num*y + den/y * x ;
            LL d= __gcd(num,den);
            num/= d;
            den/= d;
        }
        printf("Case %d: %lld/%lld\n",kk,num,den);
    }


    return 0;
}

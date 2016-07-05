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



LL mod=1000000000;


#define SIZE 300000

bool prime[SIZE];
vector<int> p;

LL fib[SIZE];

int main(){


    for (int i=2;i<SIZE;++i){
        prime[i]=true;
    }
    for (int i=2;i*i<=SIZE;++i){
        if ( prime[i] ){
            for (int j=i+i;j<SIZE;j+=i){
                prime[j]=false;
            }
        }
    }

    for (int i=2;i<SIZE;++i){
        if ( i == 4  || prime[i] ){
            p.PB( i );
        }
    }
    fib[0]=fib[1]=1;
    for (int i=2;i<SIZE;++i){
        fib[i] =( fib[i-1]+fib[i-2] )%mod;
    }

    int n;
    while ( scanf("%d",&n) == 1 ){
        n--;
        printf("%lld\n",fib[ p[n] ]);
    }


    return 0;
}

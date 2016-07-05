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

int main(){

    LL x;

    while ( scanf("%lld",&x)==1 && x!=0 ){

        vector<LL> d;

        for (int i=1;i*i<=x;++i){
            if ( x%i==0 ){
                if ( i == x/i ){
                    d.PB( i );
                }else{
                    d.PB( i );
                    d.PB( x/i );
                }
            }
        }
        int ans = 0;
        sort( d.begin(),d.end() );
        for (int i=0;i<d.size();++i){
            for (int j=i;j<d.size();++j){
                if ( d[i]*d[j]/__gcd( d[i],d[j]  ) == x ){
                    ++ans;
                }
            }
        }
        printf("%lld %d\n",x,ans);

    }


    return 0;
}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef long long LL;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;
//find_by_order
//order_of_key

#define FO(i,a,b) for (int i = (a); i < (b); i++)

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );
#define ALL(v) v.begin(),v.end()

#define X first
#define Y second
#define MP make_pair

typedef pair<int,int> pint;
typedef map<int,int> mint;

void show() {cout<<'\n';}
template<typename T,typename... Args>
void show(T a, Args... args) { cout<<a<<" "; show(args...); }
template<typename T>
void show_c(T& a) { for ( auto &x:a ){ cout<<x<<" ";}cout<<endl;  }


long long BigMod ( long long a, long long p, long long m ){
    long long res = 1;
    long long x = a;

    while ( p ){
        if ( p & 1 ){
            res = ( res * x ) % m;
        }
        x = ( x * x ) % m;
        p = p >> 1;
    }

    return res % m;
}


int main(){

    LL n;
    LL mod = 1000000007;

    LL inv = BigMod(6,mod-2,mod);

    int kase;
    scanf("%d",&kase);
    for (int kk=1;kase--;++kk){
        scanf("%lld",&n);
        n++;

        LL ans = ( n*(n+1) )%mod;
        ans = ( ans * (2*n+1) )%mod;

        LL tmp = ( 3* ( ( n* (n+1) )%mod ) )%mod;
        ans = ( ans - tmp )%mod;

        ans =( ans * inv )%mod;

        if ( ans <0 )ans += mod;

        printf("Case %d: %lld\n",kk,ans);

    }

    return 0;
}

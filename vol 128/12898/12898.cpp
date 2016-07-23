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


LL getCnt( LL x ,int d ){

    x++;

    LL per = 1LL<<(d+1);
    LL half = per/2;

    LL ret = 0;
    ret = (x/per) * half;

    x = x - ( x/per ) * per;

    ret += max( 0LL, x -half );

    return ret;
}

pair<LL,LL> get(LL a,LL b){

    pair<LL,LL> ret = MP(0,0);
    for (int i=0;i<62;++i){
        LL cnt = getCnt(b,i)-getCnt(a-1,i);
        if ( cnt >0  ){
            ret.X |= 1LL<<i;
        }
        if ( cnt == b-a+1  ){
            ret.Y |= 1LL<<i;
        }
    }
    return ret;
}


int main(){

    int kase;
    scanf("%d",&kase);

    LL a,b;
    for (int kk=1; kase-- ;++kk ){

        scanf("%lld %lld",&a,&b);
        pair<LL,LL> ans = get( a,b );

        printf("Case %d: %lld %lld\n",kk,ans.X,ans.Y);
    }


    return 0;
}

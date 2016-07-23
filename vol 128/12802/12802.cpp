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


bool palin(int n){

    int save = n ;

    vector<int> stk;
    while ( n>0 ){
        stk.PB( n%10 );
        n /= 10;
    }
    int ret = 0;
    for ( int &x:stk ){
        ret = ret *10 + x;
    }

    return ( save == ret );
}

bool prime(int n){

    if ( n == 1 )return true;

    for (int i=2;i*i<=n;++i)if ( n%i == 0 )return false;
    return true;

}


int main(){

    while ( true ){

        int n;
        scanf("%d",&n);

        printf("%d\n",2*n);

        if ( palin(n) && prime(n) )break;

    }


    return 0;
}

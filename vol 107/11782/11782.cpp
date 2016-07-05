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

#define SIZE 1010000


int arr[SIZE];
int h,k;

int dp[SIZE][21];
bool vis[SIZE][21];

int func(int x,int v,int have){

    if ( have == 0 )return 0;

    if ( vis[x][have] )return dp[x][have];
    vis[x][have] = true;
    int &ret = dp[x][have];

    ret = arr[x];
    for (int i=1;i<have && v != h ;++i){
        ret = max( ret , func( 2*x,v+1,i )+func( 2*x+1,v+1,have-i ) );
    }
    return ret;
}

void get_in(int x,int v){
    scanf("%d",&arr[x]);
    FO(i,0,k+1)vis[x][i] = false;
    if ( v == h )return ;
    else {
        get_in( 2*x,v+1 );
        get_in( 2*x+1,v+1 );
    }
}

int main(){

    FRO
    while ( scanf("%d",&h) == 1 ){
        if ( h == -1 )break;

        scanf("%d",&k);

        get_in(1,0);
        printf("%d\n",func(1,0,k));
    }

    return 0;
}

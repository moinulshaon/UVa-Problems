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


#define SIZE 305

LL nc2(LL x){
    return x*(x-1)/2;
}


LL dp[SIZE][SIZE];
LL sum[SIZE][SIZE];

int main(){



    FO( i,2,SIZE ){
        FO(j,2,SIZE){
            dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+ __gcd(i-1,j-1)-1-(i);
        }
    }


    FO(i,1,SIZE)FO(j,1,SIZE)sum[i][j] = dp[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];

    int n,m;
    while ( scanf("%d %d",&n,&m)==2 && (n+m) ){

        LL ans = nc2(n*m);
        ans -= nc2(n)*m;
        ans -= nc2(m)*n;
        ans -= sum[n][m]*2;

        printf("%lld\n",ans);
    }


    return 0;
}

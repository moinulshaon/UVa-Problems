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

int pre[SIZE];

int main(){



    int n,m;
    while ( scanf("%d %d",&n,&m)==2 && (n+m) ){

        for (int i=1;i<=n;++i){
            for (int j=0)
        }

        LL ans = 0;
        for (int i=2;i<=n;++i){
            for (int j=2;j<=m;++j){
                for (int k=1;k<i;++k){
                    ans += pre[i-k][j];
                }
                for (int k=1;k<i;++k){
                    ans += pre[i-k][m-j];
                }
            }
        }
        printf("%lld\n",ans);
    }


    return 0;
}

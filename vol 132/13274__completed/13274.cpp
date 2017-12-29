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


#define SIZE 1010

vector<int> out[SIZE];
int n,k;

int dfs(int x,int p) {

    int ret = 1;
    vector<int> candidate;
    for (int &y:out[x]) {
        if (y == p)continue;
        candidate.PB( dfs(y, x) );
    }
    if ( candidate.size() < k ) {
        return ret;
    } else {
        sort(ALL(candidate));
        reverse(ALL(candidate));

        FO(i,0,k)ret += candidate[i];
        return ret;
    }
}

int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk) {
        scanf("%d %d",&n,&k);
        FO(i,1,n+1)out[i].clear();

        int u,v;
        FO(i,1,n) {
            scanf("%d %d",&u,&v);
            out[u].PB(v);
            out[v].PB(u);
        }

        printf("Case %d: %d\n", kk, dfs(1, 0));

    }

    return 0;
}

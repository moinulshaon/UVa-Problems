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
#define R first
#define Y second
#define C second
#define MP make_pair

typedef pair<int,int> pint;
typedef map<int,int> mint;

void show() {cout<<'\n';}
template<typename T,typename... Args>
void show(T a, Args... args) { cout<<a<<" "; show(args...); }
template<typename T>
void show_c(T& a) { for ( auto &x:a ){ cout<<x<<" ";}cout<<endl;  }


bool isDown(pint cell) {
    return cell.R%2 == cell.C%2;
}

int main(){

    FRO
    freopen("out.txt","w",stdout);

    pint src,des;
    while (scanf("%d %d %d %d",&src.R,&src.C,&des.R,&des.C) != EOF) {
        if (src.X == 0 && src.Y == 0 && des.X == 0 && des.Y == 0 ) break;

        if (src.R>des.R)swap(src,des);

        LL dr = abs(src.R-des.R);
        LL dc = abs(src.C-des.C);

        LL ans = -1;
        if (dc >= dr) {
            ans = dr + dc;
        } else {
            ans = dc * 2;

            src.C = des.C;
            src.R += dc;

            dr -= dc;

            if (dr%2 == 0) {
                ans += dr/2 * 1 + dr/2 * 3;
            } else {
                if (isDown(src)) {
                    ans += (dr/2) * 3 + (dr/2 + 1) *1;
                } else {
                    ans += (dr/2) * 1 + (dr/2 + 1) *3;
                }
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}

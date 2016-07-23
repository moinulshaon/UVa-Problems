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


int main(){

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){

        pint low,high,cen;
        scanf("%d %d",&low.X,&low.Y);
        scanf("%d %d",&high.X,&high.Y);
        scanf("%d %d",&cen.X,&cen.Y);

        int r;
        scanf("%d",&r);

        high.X -= low.X;
        high.Y -= low.Y;

        cen.X -= low.X;
        cen.Y -= low.Y;

        if ( high.X<=0 || high.Y<=0 || cen.X<=0 || cen.Y<=0 || r<=0 ){
            printf("NO\n");
            continue;
        }

        if (  high.X * 6 == high.Y*10 &&  high.X == r*5 && cen.Y *2 == high.Y  && cen.X * 20 == high.X*9 ){
            printf("YES\n");
        }else{
            printf("NO\n");

        }


    }


    return 0;
}

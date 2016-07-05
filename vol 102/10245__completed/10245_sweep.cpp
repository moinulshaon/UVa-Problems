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

typedef pair<double,double> pdd;

#define SIZE 101000

pdd arr[SIZE];

const double eps = 1e-8;
const double inf = 1e15;

double dist( pdd a,pdd b ){
    return sqrt( pow( a.X-b.X,2 ) + pow( a.Y-b.Y,2 ) );
}

int main(){

    FRO

    int n;

    while ( scanf("%d",&n)==1 && n ){
        for ( int i=0;i<n;++i ){
            scanf("%lf %lf",&arr[i].X,&arr[i].Y);
        }

        sort( arr,arr+n,[]( pint a,pint b ){return a.Y<b.Y;} );

        multiset<pdd> have;
        double ans = 1e20;
        for (int i=0;i<n;++i){
            while ( !have.empty() && arr[i].Y- (have.begin()->Y) >= ans ){
                have.erase( have.begin() );
            }

            auto sit = have.lower_bound( MP( arr[i].X-ans-eps,-inf ) );
            auto fit = have.upper_bound( MP( arr[i].X+ans+eps ,-inf ) );

            while ( sit != fit ){
                ans = min( ans , dist( *sit,arr[i] ) );
                sit++;
            }
            have.insert( arr[i] );
        }
        //cout<<ans<<endl;
        /*
        if ( ans > 10000 ){
            printf("INFINITY\n");
        }else{
            printf("%.4f\n",ans);
        }*/
        printf("%.6f\n",ans);

    }

    return 0;
}

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

#define SIZE 3000

LL dp[SIZE][5];

LL ncr(int n,int r){
    if ( r>n )return 0;
    else if ( r == 0 || r == n )return 1;
    else if ( dp[n][r] != -1 )return dp[n][r];
    else{
        return dp[n][r] = ncr(n-1,r-1)+ncr(n-1,r);
    }
}

struct mathv{
    mathv(){x=0;y=0;}
    mathv(int a,int b){x=a;y=b;}
    int x,y;

    mathv operator + (mathv & p){
        mathv tmp( x+p.x,y+p.y );
        return tmp;
    }
    mathv operator - (mathv & p){
        mathv tmp( x-p.x,y-p.y );
        return tmp;
    }

}arr[SIZE];

int n;


double deg[SIZE];

const double pi = acos(-1);

int main(){

    FRO


    NEG(dp);

    int kk=1;
    while ( scanf("%d",&n)==1 && n ){

        FO(i,0,n){
            scanf("%d %d",&arr[i].x,&arr[i].y);
        }


        LL baad = 0;
        FO(i,0,n){
            int cnt = 0;
            FO(j,0,n){
                if ( j != i ){
                    deg[cnt++] = atan2( arr[j].y-arr[i].y , arr[j].x-arr[i].x  );
                }
            }
            sort( deg,deg+cnt );
            FO(j,0,cnt){
                deg[cnt+j] = 2*pi+deg[j];
            }

            int side = 0;
            FO(j,0,cnt){
                while ( deg[j]+ pi > deg[side] )side++;
                baad += ncr( side-j-1,2 );
            }

        }

        LL all = ncr(n,3);
        printf("City %d: %.2f\n",kk++,double( n*ncr(n-1,3)-baad)/all);
    }

    return 0;
}

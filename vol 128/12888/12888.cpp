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

#define SIZE 1000000


bool prime[SIZE];
vector<int> p;

int fact[SIZE];

void pre(){
    for (int i=2;i<SIZE;++i){
        prime[i] = true;
    }
    for (int i=2;i<SIZE ;++i ){
        if ( prime[i] ){
            for (int j= i+i;j<SIZE;j+=i){
                prime[j] = false;
                fact[j] = i;
            }
            fact[i] = i;
        }
    }
    for (int i=2;i<SIZE;++i){
        if ( prime[i] ){
            p.PB( i );
        }
    }
}


int num[SIZE];

int calc( int x ){

    int ret = 1;
    for (int i=0; p[i]*p[i] <= x ;++i){
        if ( x%p[i] == 0 ){
            while ( x%p[i] == 0 ){
                x/= p[i];
            }
            ret *= p[i];
        }
    }
    if ( x != 1 )ret *= x;
    return ret;
}

int dp[SIZE];

int main(){

    for (int i=1;i<SIZE;++i){
        fact[i] = 1;
    }

    pre();
    for (int i=1;i<SIZE;++i){
        num[i] = calc( i );
    }

    int kase;
    scanf("%d",&kase);

    int n,m;
    while ( kase-- ){
        scanf("%d %d",&n,&m);
        if ( n > m )swap( n,m );

        LL ans = m;
        dp[1] = m;
        for (int i=2;i<=n;++i){

            if ( num[i] == i ){
                vector<int> f;
                int tmp = i;
                while ( tmp != 1 ){
                    f.PB( fact[tmp] );
                    tmp /= fact[tmp];
                }
                dp[i] = m;
                LL sum;
                for (int state = 1;state <(1<< f.size() );++state){
                    tmp = 0;
                    sum = 0;
                    for (int j=0;j<f.size();++j){
                        if ( state & (1<<j) ){
                            sum += m/ f[j];
                            tmp++;
                        }
                    }
                    if ( tmp &1 ){
                        dp[i] -= sum;
                    }else{
                        dp[i] += sum;
                    }
                }
            }
            //show( i,num[i],fact[i],dp[ num[i] ] );
            ans += dp[ num[i] ];
        }
        printf("%lld\n",ans);
    }


    return 0;
}

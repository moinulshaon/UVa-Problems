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

#define SIZE 4000001
int h[SIZE];
int f[SIZE];
int mobius[SIZE];

bool prime[SIZE];

LL pre[SIZE];

int main(){

    for (int i=2;i<SIZE;++i){
        prime[i] = true;
    }
    for (int i=1;i<SIZE;++i){
        mobius[i] = 1;
    }
    for (int i=2;i<SIZE;++i){
        if ( prime[i] ){
            for (int j=i+i;j<SIZE;j+=i){
                prime[j] = false;
                if ( j%( LL(i)*i ) == 0 ){
                    mobius[j] = 0;
                }
                mobius[j] *= -1;
            }
            mobius[i] *= -1;
        }
    }
    for (int i=1;i<SIZE;++i){
        h[i] = i;
    }

    for (int i=1;i<SIZE;++i){
        for (int j=i;j<SIZE;j+=i){
            f[j] += h[i] * mobius[j/i];
        }
    }

    for (int i=1;i<SIZE;++i){
        for (int j=i+i;j<SIZE;j+=i){
            pre[j] += i*f[j/i];
        }
    }
    for (int i=1;i<SIZE;++i){
        pre[i] += pre[i-1];
    }
    int n;
    while ( scanf("%d",&n)==1 && n ){
        printf("%lld\n",pre[n]);
    }

    return 0;
}

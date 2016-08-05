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

int cnt[30];

const int mid = 11;

int calcF(){
    int ret = 0;
    for ( int i=0;i<30;++i ){
        if ( cnt[i] == 0 )continue;
        for ( int j=i+1;j<30;++j ){
            if ( cnt[j] == 0 )continue;
            ret += j-i;
            i = j;
            break;
        }
    }
    return ret;
}

int main(){

    int n;
    while ( scanf("%d",&n) == 1 ){

        CLR(cnt);
        int tmp;
        FO(i,0,n){
            scanf("%d",&tmp);
            cnt[ mid+tmp ]++;
        }

        FO(i,0,30)cnt[i]%=2;

        int ans = calcF() ;
        ans = min( ans,24-ans );

        printf("%d\n",ans);

    }

    return 0;
}

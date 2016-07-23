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


LL p[10][11];

int getDig(LL x){
    int ret = 0;
    while ( x>0 ){
        x/= 10;
        ret++;
    }
    return ret;
}

LL getArmstrong( LL x,int d ){
    LL ret = 0;
    while ( x>0 ){
        ret += p[x%10][d];
        x/= 10;
    }
    return ret;
}

int main(){

    FO(i,1,10){
        p[i][0] = 1;
        FO(j,1,11){
            p[i][j] = p[i][j-1]*i;
        }
    }

    int kase;
    scanf("%d",&kase);

    LL n;
    while ( kase-- ){

        scanf("%lld",&n);

        int d = getDig(n);
        LL val = getArmstrong(n,d);

        if ( val == n ){
            printf("Armstrong\n");
        }else{
            printf("Not Armstrong\n");
        }

    }


    return 0;
}

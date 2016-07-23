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

bool scan( int *arr ){

    FO(i,0,5){
        if ( scanf("%d",&arr[i]) != 1 ){
            return false;
        }
    }
    return true;
}

int main(){

    int one[5],two[5];

    while ( scan( one ) && scan(two) ){
        bool yes = true;
        FO(i,0,5)
            if ( (one[i]^two[i])==0 ){
                yes=false;
                break;
            }
        if ( yes )printf("Y\n");
        else printf("N\n");
    }


    return 0;
}

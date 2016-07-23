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


int len[]={
    1,
    4,3,3,
    3,3,3,
    4,3,4
};

string str=" .,?\"abcdefghijklmnopqrstuvwxyz";

#define SIZE 110

int arr[SIZE];
int cnt[SIZE];

char ans[SIZE];

int main(){

    int st[10] ;
    st[0] = 0;
    FO(i,1,10){
        st[i] = st[i-1]+len[i-1];
    }

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){
        int n;
        scanf("%d",&n);
        FO(i,0,n)scanf("%d",&arr[i]);
        FO(i,0,n)scanf("%d",&cnt[i]);


        FO(i,0,n){
            int ind = (cnt[i]-1)%len[ arr[i] ];
            ind += st[ arr[i] ];
            ans[i] = str[ind];
        }
        ans[n] = '\0';
        printf("%s\n",ans);
    }

    return 0;
}

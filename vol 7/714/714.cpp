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

#define SIZE 550

LL arr[SIZE];
int n,k;


int pos(LL x){

    int ret = 1;

    LL sum = 0;
    for (int i=n-1;i>=0;--i){
        if ( sum + arr[i] > x ){
            sum = arr[i];
            ret++;
        }else{
            sum += arr[i];
        }
    }
    return ret;
}

vector<vector<LL>> ans;

void print(LL x){

    ans.clear();
    int num = k-1;
    ans.resize(k);

    LL sum = 0;
    for (int i=n-1;i>=0;--i){
        if ( sum + arr[i] > x ){
            num--;
            ans[num].PB( arr[i] );
            sum = arr[i];
        }else{
            ans[num].PB( arr[i] );
            sum += arr[i];
        }
    }
/*
    FO(i,0,k){
        show_c(ans[i]);
    }
*/
    for (int i=0;i<k;++i){
        if ( ans[i].empty() ){
            int f = i+1;
            while ( ans[f].empty() ){
                f++;
            }
            ans[i].PB( ans[f].back() );
            ans[f].pop_back();
        }
    }

    bool on=false;
    for (int i=0;i<k;++i){
        if ( i )printf(" /");
        for ( int j=ans[i].size()-1;j>=0;--j ){
            if ( on )printf(" ");
            printf("%lld",ans[i][j]);
            on=true;
        }
    }
    printf("\n");
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){

        scanf("%d %d",&n,&k);
        FO(i,0,n){
            scanf("%lld",&arr[i]);
        }

        LL low=0,high = 50010000000LL;
        LL ans = -1;

        FO(i,0,n){
            low = max( low,arr[i] );
        }

        while ( low<=high ){
            LL mid  = (low+high)/2;

            if ( pos( mid ) <= k ){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }

        }

        print(ans);

    }

    return 0;
}

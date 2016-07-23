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


#define SIZE 33



int calc(char * str){

    int cnt[26]={0};
    for ( int i=0;str[i];++i ){
        cnt[ str[i]-'a' ]++;
    }


    int d = 0;
    for (int i=0;i<26 && d<=1 ;++i){
        if ( cnt[i] > 0 )d++;
    }
    if ( d<=1 )return 0;

    bool vis[SIZE]={0};
    FO(i,0,26){

        if ( cnt[i] == 0 )continue;

        if ( vis[ cnt[i]  ] )return 0;
        vis[ cnt[i] ] = true;
    }
    return 1;
}


char str[SIZE];

int main(){

    int n;
    for (int kk=1;~scanf("%d",&n);++kk){



        int ans = 0;
        while ( n-- ){
            scanf("%s",str);
            ans += calc( str );
        }

        printf("Case %d: %d\n",kk,ans);
    }

    return 0;
}

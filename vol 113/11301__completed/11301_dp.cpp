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


int dp[1010][1<<5];
int vis[1010][1<<5];
int shaon;
vector<int> out[1<<5];

int n;
char str[7][1010];


int calc(int col,int s,int t){

    vector<int> spos;
    vector<int> tpos;

    for ( int i=0;i<5;++i ){
        if ( s & (1<<i) ){
            spos.PB(i);
        }
    }
    for ( int i=0;i<5;++i ){
        if ( t & (1<<i) ){
            tpos.PB(i);
        }
    }


    int ret = 0;
    for ( int i=0;i<3;++i ){
        int x = spos[i];
        int y = tpos[i];

        int mn = min(x,y);
        int mx = max(x,y);

        for (int j=mn;j<=mx;++j){
            if ( j != x ){
                ret += str[j][col]-'0';
            }
        }

        ret += str[y][col+1]-'0';
    }


    return ret;
}

int func(int col,int state){

    if ( col >= n-1 )return 0;

    int &ret = dp[col][state];

    if ( vis[col][state] == shaon )return ret;
    vis[col][state] = shaon;


    ret = (1<<29);
    for ( auto&t:out[state] ){
        ret = min( ret , calc(col,state,t)+func( col+1,t ) );
    }

    return ret;
}



vector<int> av;

bool pos(int s,int t){

    vector<int> spos;
    vector<int> tpos;

    for ( int i=0;i<5;++i ){
        if ( s & (1<<i) ){
            spos.PB(i);
        }
    }
    for ( int i=0;i<5;++i ){
        if ( t & (1<<i) ){
            tpos.PB(i);
        }
    }

    for ( int i=1;i<3;++i ){
        if ( max( spos[i-1],tpos[i-1] ) >= min( spos[i],tpos[i] ) ){
            return false;
        }
    }
    return true;
}

int main(){


    FRO

    for (int i=0;i<(1<<5);++i){
        if ( __builtin_popcount(i) == 3 ){
            av.PB( i );
        }
    }

    for ( auto&s:av ){
        for ( auto&t:av ){
            if ( pos(s,t) ){
                out[s].PB( t );
            }
        }
    }

    while ( scanf("%d",&n)==1 && n ){

        shaon++;

        for (int i =0;i<5;++i){
            scanf("%s",str[i]);
        }

        int s=0;
        for (int i=0;i<5;++i){
            if ( str[i][0] == '@' ){
                s |= 1<<i;
            }
        }


        printf("%d\n",func(0,s));


    }

    return 0;
}

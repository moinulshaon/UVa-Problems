#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

int parent[35],size[35];

int parentOf (int n){
    if ( n == parent [n] ) return n;
    return parent [n] = parentOf (parent [n]);
}
int n,ntotal,weight[35];

bool vis[1<<21];
double dp[1<<21];

int Set(int N,int pos){
    return N=N | (1<<pos);
}
int Reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool Check(int N,int pos){
    return (bool)(N & (1<<pos));
}


double func( int state ,int cnt){

    if ( state == ( 1<<n )-1 || n== 1 )return 0;



    double &ret = dp[state];
    if ( vis[state] )return ret;

    vis[state] = true;
    ret = 0;

    for (int i=0;i<n;++i){
        if ( Check( state,i ) == 0 ){
            ret += double( weight[i] )/( ntotal-1 ) * ( 1 + func( Set(state,i),cnt+weight[i] ) );
        }
    }
    double tmp= double( cnt-1 )/(ntotal-1);
    ret = ( ret+tmp )/( 1-tmp );
    //cout<<tmp<<" "<<state<<" "<<cnt<<" "<<ntotal<<endl;
    return ret;
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int ee;
        scanf("%d %d",&ntotal,&ee);

        for (int i=1;i<=ntotal;++i){
            parent[i] = i;
            size[i] = 1;
        }

        int u,v;
        while ( ee-- ){
            scanf("%d %d",&u,&v);
            int p = parentOf(u);
            int q = parentOf(v);
            if ( q>p )swap(p,q);
            if ( p==q  )continue;
            size[ q ] += size[ p ];
            parent[ p ]= q;
            //cout<<u<<" "<<v<<" "<<q<<" "<<size[q]<<endl;

        }
        n=0;
        for (int i=1;i<=ntotal;++i){
            int p =parentOf(i);
            //cout<<"sahon "<<i<<" "<<p<<endl;
            if (  p == i ){
                //cout<<n<<" "<<size[p]<<endl;
                weight[n] = size[p];
                n++;
            }
        }

        //if ( n>20 )exit(5);
        CLR(vis);
        printf("Case %d: %.7lf\n",kk,func( 1 ,weight[0]));
    }


    return 0;
}

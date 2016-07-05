#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

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


#define SIZE 105
vector<int>out[SIZE];

pint dp[SIZE];
vector<int> stk;

pint node[SIZE];
int parent[SIZE];

void dfs(int x,int p){

    parent[x] = p;

    for ( auto y:out[x] ){
        if ( y == p )continue;
        dfs( y,x );
    }
    stk.PB(x);
}

int main(){

    FRO

    int kk=1;

    int n;
    while ( scanf("%d",&n) ==1 && n ){

        int tmp;
        for (int i=1;i<=n;++i){
            scanf("%d %d",&node[i].X,&node[i].Y);
            scanf("%d",&tmp);
            node[i].Y += tmp;

            if ( node[i].Y > node[i].X )node[i].X = node[i].Y;

            out[i].clear();

        }

        int u,v;
        for (int i=1;i<n;++i){
            scanf("%d %d",&u,&v);
            out[u].PB( v );
            out[v].PB( u );
        }

        int ans = (1<<29);
        for (int i=1;i<=n;++i){
            stk.clear();
            dfs(i,0);
            //show_c( stk );

            for (int j=0;j<stk.size();++j){

                int &x= stk[j];

                pint &ret = dp[x];

                ret.X = node[x].X;
                ret.Y = node[x].Y;

                vector<pint> vec;

                for (auto y:out[x]){
                    if ( parent[x] == y )continue;
                    vec.PB( MP( dp[y].X,dp[y].Y ) );
                }
                sort( vec.begin(),vec.end(),[]( const pint &a,const pint &b ){ if ( a.X != b.X )return a.X>b.X;else return a.Y<b.Y;  } );

                for ( auto &v:vec ){
                    ret.X = max( ret.X,ret.Y+v.X );
                    ret.Y += v.Y;
                }

                //show( x,ret.X,ret.Y );
            }
            //show( i, stk.back() , dp[ stk.back() ].X );
            ans=min( ans , dp[ stk.back() ].X );

            //break;
        }

        printf("Case %d: %d\n",kk++,ans);
        //break;

    }

    return 0;
}

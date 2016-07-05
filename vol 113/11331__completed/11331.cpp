#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

template<class T>
    inline T fastIn() {
    register char c=0;
    register T a=0;
    bool neg=false;
    while ( c<33 ) c=getchar();
    while ( c>33 ) {
        if ( c=='-' ) {
            neg=true;
        } else {
            a= ( a*10 ) + ( c-'0' );
        }
        c=getchar();
    }
    return neg?-a:a;
}

#define SIZE 2100

vector<int> outarrow[SIZE];
char vis[SIZE];
bool bipartitePossible;

typedef pair<int,int> ppi;

ppi checkBipartite(int start){
    queue<int> q;
    q.push(start);
    vis[start]=0;
    int cnt[2]={0};

    while (!q.empty() && bipartitePossible){
        int tmp=q.front();
        q.pop();
        cnt[ vis[tmp] ]++;

        for (int i=0;i<outarrow[tmp].size();++i){
            if ( vis[ outarrow[tmp][i] ]==-1 ){
                vis[ outarrow[tmp][i] ]=  !vis[tmp];
                q.push( outarrow[tmp][i] );
            }
            else if ( vis[ outarrow[tmp][i] ]==  vis[tmp]){
                bipartitePossible=false;
                break;
            }
        }
    }
    return make_pair( cnt[0],cnt[1] );
}
vector<ppi>com;

char dp[1010][1010];

char func(int sum,int totake){

    if ( sum==0 &&  totake==com.size() )return 1;
    else if ( sum<0 || totake==com.size() )return 0;

    if ( dp[sum][totake]!= -1 )return dp[sum][totake];

    return dp[sum][totake]= func( sum-com[totake].first,totake+1 ) | func( sum-com[totake].second,totake+1 );
}

int main(){
    int kase=fastIn<int>();
    int u,v;

    while(kase--){
        int a=fastIn<int>();
        int b=fastIn<int>();
        int ee=fastIn<int>();

        for (int i=0;i<=a+b;++i){
            outarrow[i].clear();
        }

        while(ee--){
            u=fastIn<int>();
            v=fastIn<int>();

            outarrow[u].push_back(v);
            outarrow[v].push_back(u);
        }

        bipartitePossible=true;
        memset(vis,-1,sizeof(vis));

        com.clear();

        for (int i=1;i<=a+b;++i){
            if ( vis[i]== -1 && bipartitePossible ){
                com.push_back( checkBipartite(i) );
            }
        }
        if ( !bipartitePossible ){
            printf("no\n");
        }else{
            memset(dp,-1,sizeof(dp));
            if (  func(a,0) ){
                printf("yes\n");
            }else{
                printf("no\n");
            }
        }
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define SIZE 8100

using namespace std;

#define NODE(x) ( 2*(x) )

int total;
vector<int> out[SIZE];
vector<int> in[SIZE];

int plane[SIZE];

void build(int len){

    for (int i=0;i<total;++i){
        out[ NODE(i)^1 ].push_back( NODE(i^1) );
        in[ NODE(i^1) ].push_back( NODE(i)^1 );
    }

    for (int i=0;i<total;++i){
        for (int j=0;j<total;++j){
            if ( i!=j && j!= (i^1) ){
                if ( abs( plane[j]-plane[i] )< len ){
                    out[ NODE(i) ].push_back( NODE(j)^1 );
                    in[ NODE(j)^1 ].push_back( NODE(i) );
                }
            }
        }
    }
}

bool vis[SIZE];
int component[SIZE];
vector<int> stk;
void dfs1 (int x)
{
	vis [x] = true;

	for ( int u = 0; u < out [x].size (); u++ )
		if ( !vis [ out [x] [u]] )
            dfs1 (out [x] [u]);

	stk.push_back (x);
}

void dfs2 (int x, int c)
{
	vis [x] = false;
	component [x] = c;

	for ( int u = 0; u < in [x].size (); u++ )
		if ( vis [in [x] [u]] )
            dfs2 (in [x] [u], c);
}



bool pos(int len){

    for (int i=0;i<=NODE(total);++i){
        out[i].clear();
        in[i].clear();
    }

    build(len);

    memset(vis,false,sizeof(vis));
    stk.clear();
    for (int i=0;i<NODE(total);++i){
        if ( !vis[i] ){
            dfs1(i);
        }
    }
    int c = 0;
    for ( int i = stk.size () - 1; i >= 0; i-- )
        if ( vis [stk [i]] )
            dfs2 (stk [i], ++c);
    for (int i=0;i<NODE(total);i+=2){
        if ( component[i] == component[i^1] ){
            return false;
        }
        //printf("%d %d\n",component[i],component[i^1]);
    }
    return true;
}


int main(){
    freopen("in.txt","r",stdin);
    while(scanf("%d",&total)==1 ){

        int low=0,high=0;
        total=2*total;
        for (int i=0;i<total;++i){
            scanf("%d",&plane[i] );
        }

        for (int i=0;i<total;++i){
            for (int j=i+1;j<total;++j){
                high=max(  high, abs(plane[i]-plane[j]) );
            }
        }

        int ans= -1;
        while(low<=high){
            int mid=(low+high)/2;
            //printf("%d %d\n",mid,pos(10));
            if ( pos( mid ) ){
                ans=mid;
                low=mid+1;
                //printf("%d\n",ans);
            }else{
                high=mid-1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

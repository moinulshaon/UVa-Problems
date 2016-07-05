#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define SIZE 20100

vector<int> edge[SIZE];
bool isArtic[SIZE];
int level[SIZE];
int low[SIZE];
int childrenCnt[SIZE];
vector<int> com[SIZE];
int after[SIZE];

int parent [SIZE];
int sz[SIZE];

int parentOf (int n){
    if ( n == parent [n] ) return n;
    return parent [n] = parentOf (parent [n]);
}

int dfs( int x ){
    //printf("%d %d\n",x,level[x]);
    low[x]=level[x];
    after[x]=1;
    int y;
    for (int i=0;i<edge[x].size();++i){
        y=edge[x][i];
        if ( level[ y ]== -1 ){

            level[ y ]=level[x]+1;
            childrenCnt[ x ]++;

            dfs( y );
            after[x]+=after[y];


            low[x]=min( low[x],low[y] );

            if ( level[x]!=0 && low[y]>=level[x] ){
                isArtic[x]=true;
                com[x].push_back(after[y]);
            }
        }else if ( level[y]< level[x]-1 ){
            low[x]=min( low[x],level[y] );
        }
    }
    if ( level[x]==0 && childrenCnt[x]>1){
        isArtic[x]=true;
        for (int i=0;i<edge[x].size();++i){
            y=edge[x][i];
            if ( level[y] == 1 )
                com[x].push_back(after[y]);
        }
    }
}
typedef long long LL;

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


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int kase,a,b,v,e;
    kase=fastIn<int>();

    for (int kk=1;kase--;++kk){

        v=fastIn<int>();
        e=fastIn<int>();
        for (int i=1;i<=v;++i){
            edge[i].clear();
            com[i].clear();
        }
        for (int i=0;i<=v; ++i ){
            parent [i] = i;
            sz[i]=1;
        }

        while(e-- ){
            a=fastIn<int>();
            b=fastIn<int>();
            edge[a].push_back(b);
            edge[b].push_back(a);

            int p = parentOf (a);
            int q = parentOf (b);

            if ( p != q ) {
                if (sz[p]>sz[q])swap(p,q);
                sz[q]+=sz[p];
                parent [p] = q;
            }

        }


        memset( level,-1,sizeof(level));
        memset( childrenCnt,0,sizeof(childrenCnt));
        memset( isArtic,false,sizeof(isArtic) );
        memset( after,0,sizeof(after) );

        for (int i=1;i<=v;++i){
            if ( level[i] == -1 ){
                level[i]=0;
                dfs(i);
            }
        }

        LL ans=0;
        for (int i=1;i<=v;++i){
            if ( isArtic[i]  ){

                //printf("artic %d\n",i,ans);
                int sum=0;
                for (int j=0;j<com[i].size();++j){
                    ans+= com[i][j] * ( sz[ parentOf(i) ] - com[i][j]-1  );
                    sum+= com[i][j];
                    //printf("%d %d\n",com[i][j],( sz[ parentOf(i) ] - com[i][j] -1  ) );
                }
                //printf("%d %d\n",( sz[ parentOf(i) ] - sum -1 ),sum );
                ans+= sum* ( sz[ parentOf(i) ] - sum -1 ) ;
                //printf("%d\n",ans);
            }
        }
        printf("Case %d: %lld\n",kk,ans);
    }
    return 0;

}



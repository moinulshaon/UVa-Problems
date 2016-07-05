#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

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


#define SIZE 5010

using namespace std;

vector<int>out[SIZE];
bool vis[SIZE];
int parent[SIZE][14];
int depth[SIZE];

void dfs(int x,int p){
    vis[x]=true;

    parent[x][0]=p;
    depth[x]=depth[p]+1;


    for (int i=1;i<14;++i)
        parent[x][i]=parent[ parent[x][i-1] ][i-1];

    for (int i=0;i<out[x].size();++i){
        int y=out[x][i];
        if ( !vis[y] ){
            dfs(y,x);
        }
    }

}

int lca(int x,int y){
    if ( depth[x]>depth[y] ){
        swap(x,y);
    }
    for (int i=0;i<14;++i){
        if( ( ( depth[y]-depth[x] )>>i )&1){
            y=parent[y][i];
        }
    }
    if ( x==y ){
        return x;
    }
    for(int i=13;i>=0;--i)
        if(parent[x][i]!=parent[y][i] )
            x=parent[x][i],y=parent[y][i];
    return parent[x][0];
}

int dis(int x,int y){
    int dis=0;
    for (int i=0;i<14;++i){
        if( ( ( depth[y]-depth[x] )>>i )&1){
            y=parent[y][i];
            dis |=(1<<i);
        }
    }
    return dis;
}

int up(int x,int val){
    //printf("me %d\n",val);
    if ( val==0 ){
        return x;
    }else{
        for(int i=13;i>=0;--i){
            if ( (val>>i)&1 ){
                x=parent[x][i];
            }
        }
        return x;
    }
}


int main(){
    freopen("in.txt","r",stdin);
    int n;

    while(true){
        n=fastIn<int>();

        if ( !n )return 0;

        for (int i=1;i<=n;++i){
            out[i].clear();
        }
        int a,b;
        for (int i=1;i<n;++i){
            a=fastIn<int>();
            b=fastIn<int>();

            out[a].push_back(b);
            out[b].push_back(a);
        }

        memset(vis,false,sizeof(vis));
        depth[1]=0;
        dfs(1,0);

        int query=fastIn<int>();

        while(query--){
            a=fastIn<int>();
            b=fastIn<int>();

            int d=lca(a,b);

            int x=dis( d,a );
            int y=dis( d,b );

            //printf("lca %d val %d %d\n",d,x,y);
            if ( (x+y)%2 == 0 ){
                if ( x>=y ){
                    printf("The fleas meet at %d.\n", up(a,(x+y)/2) );
                }else{
                    printf("The fleas meet at %d.\n", up(b,(x+y)/2) );
                }
            }else{
                int u,v;
                if ( x>=y ){
                    u=up(a,(x+y)/2);
                    v=up(a,(x+y)/2+1);
                }else{
                    u=up(b,(x+y)/2);
                    v=up(b,(x+y)/2+1);
                }
                printf("The fleas jump forever between %d and %d.\n",min(u,v),max(u,v));
            }
        }
    }

}

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define SIZE 100100

bool vis[SIZE];
int parent[SIZE][18],depth[SIZE],innow[SIZE],outnow[SIZE],now,vertex;
vector<int> out[SIZE];

void dfs(int x,int p){
    vis[x]=true;

    parent[x][0]=p;
    depth[x]=depth[p]+1;

    innow[x]=++now;
    for (int i=1;i<18;++i)
        parent[x][i]=parent[ parent[x][i-1] ][i-1];

    for (int i=0;i<out[x].size();++i){
        int y=out[x][i];
        if ( !vis[y] ){
            dfs(y,x);
        }
    }

    outnow[x]=now;
}

int lca(int x,int y){
    if ( depth[x]>depth[y] ){
        swap(x,y);
    }
    for (int i=0;i<18;++i){
        if( ( ( depth[y]-depth[x] )>>i )&1){
            y=parent[y][i];
        }
    }
    if ( x==y ){
        return x;
    }
    for(int i=17;i>=0;--i)
        if(parent[x][i]!=parent[y][i] )
            x=parent[x][i],y=parent[y][i];
    return parent[x][0];
}

int val[SIZE];
const int MaxVal=SIZE-10;

int read(int idx,int tree[]){
	int sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx ,int val,int tree[]){
	while (idx <= MaxVal){
		tree[idx] += val;
		idx += (idx & -idx);
    	}
}

int tree[11][SIZE];

int main(){
    freopen("in.txt","r",stdin);

    int qq,a,b,kase,q;
    scanf("%d",&kase);

    while(kase--){
        scanf("%d %d",&vertex,&q);

        for (int i=1;i<=vertex;++i){
            scanf("%d",&val[i]);
            out[i].clear();
        }

        for (int i=1;i<vertex;++i){
            scanf("%d %d",&a,&b);
            out[a].push_back(b);
            out[b].push_back(a);
        }

        memset(vis,false,sizeof(vis));
        now=0;
        dfs(1,0);

        memset(tree,0,sizeof(tree));
        for (int i=1;i<=vertex;++i){
            update( innow[i], 1, tree[ val[i] ] );
            update( outnow[i]+1 , -1, tree[ val[i] ] );
        }

        while(q--){
            scanf("%d %d %d",&qq,&a,&b);
            if ( qq ){
                int ans=0;
                int t=lca(a,b);
                //printf("lca %d\n",t);
                for (int i=1;i<=10;++i){
                    ans=max( ans, read( innow[a] , tree[i] )+read( innow[b] , tree[i] )
                            - read( innow[t] , tree[i] ) -read( innow[ parent[t][0] ] , tree[i] )  );
                }
                printf("%d\n",ans);
            }else{
                update( innow[ a ],-1,tree[ val[a] ] );
                update( outnow[ a ]+1 , 1, tree[ val[a] ] );

                val[a]=b;
                update( innow[ a ],1,tree[ val[a] ] );
                update( outnow[ a ]+1 , -1, tree[ val[a] ] );

            }
        }
    }
    return 0;
}

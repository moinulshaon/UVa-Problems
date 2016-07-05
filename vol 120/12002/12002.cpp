#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int arr[510];
int lis1[510];
int lds1[510];

int dfs1( int x ){

    if ( lis1[x]!= -1 )return lis1[x];
    int mx=1;
    for (int i=x+1;i<n;++i){
        if ( arr[i]>=arr[x] ){
            mx=max( mx,1+dfs1(i) );
        }
    }
    return lis1[x]=mx;
}

int dfs2( int x ){

    if ( lds1[x]!= -1 )return lds1[x];
    int mx=1;
    for (int i=x+1;i<n;++i){
        if ( arr[i]<=arr[x] ){
            mx=max( mx,1+dfs2(i) );
        }
    }
    return lds1[x]=mx;
}


int main(){
    freopen("in.txt","r",stdin);

    while( scanf("%d",&n)==1 && n ){
        for (int i=0;i<n;++i){
            scanf("%d",&arr[i]);
        }

        memset(lis1,-1,sizeof(lis1));
        memset(lds1,-1,sizeof(lds1));

        for (int i=0;i<n;++i){
            dfs1(i);
            dfs2(i);
            //printf("%d %d %d\n",i,lis1[i],lds1[i]);
        }

        int ans=0;
        for (int i=0;i<n;++i){
            ans=max( ans,max( lis1[i],lds1[i] ) );
            for (int j=i;j<n;++j){
                if ( arr[i]>arr[j] ){
                    ans=max( ans, lis1[i]+lds1[j]  );
                }else if ( arr[i]<arr[j] ){
                    ans=max( ans, lds1[i]+lis1[j]  );
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>

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

#define SIZE 110

int nxt[SIZE];
int val[SIZE];
int end;

int dfs(int x){
    end=x;
    if ( nxt[x]== -1 ){
        return val[x];
    }else{
        return val[x]+dfs( nxt[x] );
    }
}

int main(){
    freopen("in.txt","r",stdin);
    int kase=fastIn<int>(),a,b;
    for (int kk=1;kase--;++kk){
        int n=fastIn<int>();
        int m=fastIn<int>();

        for (int i=0;i<n;++i){
            val[i]=fastIn<int>();
        }
        memset(nxt,-1,sizeof(nxt));
        while(m--){
            a=fastIn<int>();
            b=fastIn<int>();

            if ( nxt[a]== -1 ){
                nxt[a]=b;
            }else{
                if ( val[ nxt[a] ]< val[b] ){
                    nxt[a]=b;
                }
            }
        }
        int ans=dfs(0);
        printf("Case %d: %d %d\n",kk,ans,end);
    }
    return 0;
}

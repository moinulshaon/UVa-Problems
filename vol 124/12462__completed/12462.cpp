#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>

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


#define SIZE 100005
typedef long long LL;

int height[SIZE],color[SIZE];
int ctoleft[SIZE];
int ctoright[SIZE];
int n,cc;
LL area[SIZE];

void calcleft(){

    for (int i=1;i<=n;++i){
        ctoleft[i]=(1<<color[i]);
    }
    stack<int> stk;
    stk.push(0);

    for (int i=1;i<=n;++i){

        while( height[ stk.top() ] >= height[i] ){
            ctoleft[i] |= ctoleft[ stk.top() ];
            stk.pop();
        }
        area[i]=LL( height[i] )*( i-stk.top() );
        stk.push(i);
    }
}

void calcright(){
    for (int i=1;i<=n;++i){
        ctoright[i]=(1<<color[i]);
    }
    stack<int> stk;
    stk.push(n+1);
    height[n+1]=0;
    for (int i=n;i>0;--i){

        while( height[ stk.top() ]>= height[i] ){
            ctoright[i] |= ctoright[ stk.top() ];
            stk.pop();
        }
        area[i]+= LL(height[i])*( stk.top()-i-1 );
        stk.push(i);
    }
}

int main(){

    freopen("in.txt","r",stdin);
    while(true){
        n=fastIn<int>();
        cc=fastIn<int>();

        if ( !n && !cc )return 0;

        for (int i=1;i<=n;++i){
            height[i]=fastIn<int>();
        }
        for (int i=1;i<=n;++i){
            color[i]=fastIn<int>();
        }
        calcleft();
        calcright();

        LL ans=0;
        for (int i=1;i<=n;++i){
            if ( ( ctoleft[i] | ctoright[i] ) == (1<<cc)-1 ){
                ans=max(ans,area[i]);
            }
        }
        printf("%lld\n",ans);
    }
}

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int ans[52];

int top[52];



bool issqr( int x ){
    int ss=sqrt(x)+1e-6;

    return ss*ss == x;
}

int main(){

    memset( top,-1,sizeof(top) );

    int tower=1;

    top[1]=1;
    for (int peg=2;tower<52;peg++ ){
        //printf("%d\n",tower);
        bool placed=false;
        for (int i=1;i<=tower;++i){

            if ( issqr( peg+top[i] ) ){
                top[i]=peg;
                placed=true;
                break;
            }
        }
        if ( !placed ){
            ans[tower]=peg-1;
            top[++tower]=peg;
        }
    }


    int n,kase;
    scanf("%d",&kase);

    while(kase--){
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
    return 0;
}
